# -*- mode: cmake; cmake-tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#

# parameters for boost tests
set(boost_test_parameters "--log_level=error")

# tests to ignore
set(boost_tests_ignore "")

#
# macro to create CTest tests for each boost unit tests
#
macro(add_boost_tests test_module)
    foreach(cpp_file ${ARGN})
        file(READ "${cpp_file}" contents)

        string(REGEX MATCHALL "BOOST_AUTO_TEST_SUITE(\\([A-Za-z_0-9]+\\))"
            found_suites ${contents})

        list(LENGTH found_suites total_suites)
         if (total_suites GREATER 1)
             message(FATAL_ERROR "Only one test suite per file is supported. File: ${cpp_file}")
         elseif (total_suites EQUAL 1)
             list (GET found_suites 0 test_suite)
             string(REGEX REPLACE "BOOST_AUTO_TEST_SUITE(\\([A-Za-z_0-9]+\\))"
                 "\\1" test_suite ${test_suite})
             string(REPLACE "(" "" test_suite ${test_suite})
             string(REPLACE ")" "" test_suite ${test_suite})

             string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\(([A-Za-z_0-9]+)\\)"
                 found_tests ${contents})
             foreach(hit ${found_tests})
                 string(REGEX REPLACE "BOOST_AUTO_TEST_CASE(\\([A-Za-z_0-9]+\\))"
                     "\\1" test_name ${hit})
                 string(REPLACE "(" "" test_name ${test_name})
                 string(REPLACE ")" "" test_name ${test_name})

                 if (${test_name} IN_LIST boost_tests_ignore)
                     message(STATUS "Ignoring test: ${test_name}")
                 else()
                     set(tests_cmd ${stage_bin_dir}/${test_module})
                     add_test(${test_module}/${test_suite}/${test_name}
                         ${CMAKE_COMMAND} -E chdir ${stage_bin_dir}
                         ${tests_cmd} --run_test=${test_suite}/${test_name}
                         ${boost_test_parameters})
                 endif()
             endforeach()
         endif()
    endforeach()
endmacro()

#
# compiler and linker flags
#
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_COMPILER_IS_CLANGXX "TRUE")
endif()

#
# Use C++ 17 on all compilers.
#
set(CMAKE_CXX_STANDARD 17 CACHE STRING "The C++ standard to use")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX
        AND NOT "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
    # enable as many warnings as possible
    set(warning_flags "-Wall -Wextra -Wconversion")

    # force DWARF version to 4 in order to keep Valgrind happy.
    set(warning_flags "${warning_flags} -gdwarf-4")

    if (CMAKE_COMPILER_IS_GNUCXX)
        set(warning_flags "${warning_flags} -Wno-maybe-uninitialized")
    endif()

    if (CMAKE_COMPILER_IS_CLANGXX)
        # disable mismatched tags as there are STL inconsistencies that
        # make it a bit useless.
        set(warning_flags "${warning_flags} -Wno-mismatched-tags")

        # Ignore self-assigns as we need this for generated tests.
        set(warning_flags "${warning_flags} -Wno-self-assign-overloaded ")

        if(CCACHE_PROGRAM)
            # CCache and Clang don't seem to play nice when it comes
            # to unused arguments.
            set(warning_flags "${warning_flags} -Qunused-arguments")
        endif()
    endif()

    # issue all the warnings demanded by strict iso c and iso c++
    set(warning_flags "${warning_flags} -pedantic")

    # treat warnings as errors
    set(warning_flags "${warning_flags} -Werror")

    # do not issue warnings for system headers
    set(warning_flags "${warning_flags} -Wno-system-headers")

    # overloaded virtual function has a different signature
    set(warning_flags "${warning_flags} -Woverloaded-virtual")

    # make string constants const char*
    set(warning_flags "${warning_flags} -Wwrite-strings")

    # enable RTTI
    if(APPLE)
        set(other_flags "${other_flags} -fvisibility=default")
    else()
        set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
        set(other_flags "${other_flags} -fvisibility=hidden")
    endif()

    set(profiling_flags "")
    if(WITH_PROFILING)
        if (CMAKE_COMPILER_IS_GNUCXX)
            # set absolute path to avoid problems with relative path. This
            # only works with GCC.
            set(profiling_flags "-fprofile-abs-path")
        endif()

        # do not use --coverage to support both gcc and clang.
        set(profiling_flags "${profiling_flags} -fprofile-arcs")
        set(profiling_flags "${profiling_flags} -ftest-coverage")
    endif()

    # set the flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warning_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${profiling_flags}")

    if(UNIX AND NOT APPLE)
        # use the Gold linker.
        set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} -Wl,-fuse-ld=gold")
        set(CMAKE_SHARED_LINKER_FLAGS
            "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-fuse-ld=gold")
    endif()
endif()

# user includes
include_directories(
    # Split project
    ${CMAKE_SOURCE_DIR}/projects/public_headers
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.directory_settings/cpp_backend/id
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.boost_model/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.compressed/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.cpp_98/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.cpp_model/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.disable_cmakelists/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.disable_facet_folders/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.enable_facet_hash/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.enable_facet_io/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.enable_facet_serialization/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.enable_facet_types/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.flat_directory_mode/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.lam_model/cpp/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.seam/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.std_model/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.test_model_sanitizer/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.two_layers/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.delete_extra/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.skip_empty_dirs/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.ignore_extra/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.force_write/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.out_of_sync/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.utility/include
    )

#
# feature specific projects
#

if (WITH_RELATIONAL_SUPPORT AND ODB_LIBODB_FOUND)
    message(STATUS "Adding ODB feature test project")
    include_directories(${CMAKE_SOURCE_DIR}/projects/cpp_ref_impl.northwind/include)

    #
    # Setup includes for ODB
    #
    get_directory_property(dirs INCLUDE_DIRECTORIES)
    set(global_includes "")
    foreach(dir IN LISTS dirs)
        set(ODB_EXECUTABLE_GLOBAL_ARGS ${ODB_EXECUTABLE_GLOBAL_ARGS} -I ${dir})
    endforeach()
    set(ODB_EXECUTABLE_GLOBAL_ARGS ${ODB_EXECUTABLE_GLOBAL_ARGS} -I ${ODB_INCLUDE_DIRS})

    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.northwind)
endif()

#
# add projects
#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.directory_settings/cpp_backend)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.boost_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.compressed)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.cpp_98)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.cpp_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.disable_facet_folders)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.enable_facet_hash)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.enable_facet_io)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.enable_facet_serialization)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.enable_facet_types)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.flat_directory_mode)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.lam_model/cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.models)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.seam)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.split_project/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.std_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.two_layers)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.delete_extra)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.skip_empty_dirs)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.ignore_extra)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.force_write)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.out_of_sync)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_ref_impl.utility)
