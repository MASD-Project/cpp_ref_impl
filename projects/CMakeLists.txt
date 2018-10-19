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

#
# macro to create CTest tests for each boost unit tests
#
macro(add_boost_tests test_module)
    foreach(cpp_file ${ARGN})
        file(READ "${cpp_file}" contents)
        string(REGEX MATCHALL "BOOST_AUTO_TEST_CASE\\(([A-Za-z_0-9]+)\\)"
            found_tests ${contents})

        foreach(hit ${found_tests})
            string(REGEX REPLACE "BOOST_AUTO_TEST_CASE(\\([A-Za-z_0-9]+\\))"
                "\\1" test_name ${hit})
            string(REPLACE "(" "" test_name ${test_name})
            string(REPLACE ")" "" test_name ${test_name})

            string(REPLACE "_tests.cpp" "_tests" test_suite ${cpp_file})
            # string(REPLACE "tests/" "" test_suite ${test_suite})

            set(tests_cmd
                ${stage_bin_dir}/dogen.${test_module}.tests)
            add_test(${test_module}/${test_suite}/${test_name}
                ${CMAKE_COMMAND} -E chdir ${stage_bin_dir}
                ${tests_cmd} --run_test=${test_suite}/${test_name})
        endforeach()
    endforeach()
endmacro()

#
# compiler and linker flags
#
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_COMPILER_IS_CLANGXX "TRUE")
endif()

if (UNIX)
    check_library_exists(rt clock_gettime "" HAVE_CLOCK_GETTIME)
    if (HAVE_CLOCK_GETTIME)
        message(STATUS "Requires clock_gettime.")
        set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_LIBRARIES} rt)
    else()
        message(STATUS "Does NOT require clock_gettime.")
    endif()
endif()

#
# Use C++ 17 on all compilers.
#
set(CMAKE_CXX_STANDARD 17)

if (CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX
        AND NOT "x${CMAKE_CXX_SIMULATE_ID}" STREQUAL "xMSVC")
    # enable as many warnings as possible
    set(warning_flags "-Wall -Wextra -Wconversion")

    if (CMAKE_COMPILER_IS_GNUCXX)
        set(warning_flags "${warning_flags} -Wno-maybe-uninitialized")
    endif()

    if (CMAKE_COMPILER_IS_CLANGXX)
        # disable mismatched tags as there are STL inconsistencies that
        # make it a bit useless.
        set(warning_flags "${warning_flags} -Wno-mismatched-tags")
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

    if(WITH_PROFILING)
        # enable code profiling options
        set(profiling_flags "-fprofile-arcs -ftest-coverage")

        if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
            # FIXME: profiling flags appear not to be used during
            # compilation so disable the warning. bit of a hack, for now.
            set(profiling_flags "${profiling_flags} -Qunused-arguments")

            set(profiling_flags "${profiling_flags} --coverage")
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-cfg-checksum")
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-no-function-names-in-data")

            # 408 for gcc 4.8 compatibility of the gcov format.
            set(profiling_flags
                "${profiling_flags} -Xclang -coverage-version='408*'")
        endif()
    endif()

    # enable RTTI
    add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
    set(other_flags "${other_flags} -frtti -fvisibility-inlines-hidden")
    set(other_flags "${other_flags} -fvisibility=hidden")

    # set the flags
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${optimisation_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${warning_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${profiling_flags}")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${other_flags}")

    # ignore fuzzy link errors
    if (WIN32)
        set(CMAKE_EXE_LINKER_FLAGS
            "${CMAKE_EXE_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
        set(CMAKE_SHARED_LINKER_FLAGS
            "${CMAKE_SHARED_LINKER_FLAGS} -Wl,-enable-stdcall-fixup")
    endif()

elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC" OR
        CMAKE_CXX_SIMULATE_ID MATCHES "MSVC")
    if(${MSVC_VERSION} GREATER 1399) # 1400+ => VC2005+
        # cannot use incremental rebuild
        string(REPLACE "/Gm" "" CMAKE_C_FLAGS_DEBUG ${CMAKE_C_FLAGS_DEBUG})
        string(REPLACE "/Gm" "" CMAKE_C_FLAGS_RELEASE ${CMAKE_C_FLAGS_RELEASE})
        string(REPLACE "/Gm" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
        string(REPLACE "/Gm" "" CMAKE_CXX_FLAGS_RELEASE
            ${CMAKE_CXX_FLAGS_RELEASE})
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

        # workaround for C1128: number of sections exceeded object
        # file format limit.
        set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
    endif()

    set(CMAKE_CXX_FLAGS
        "${CMAKE_CXX_FLAGS} /D _SILENCE_CXX17_OLD_ALLOCATOR_MEMBERS_DEPRECATION_WARNING")

    foreach(flag_var CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE CMAKE_C_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        string(REGEX REPLACE "/MDd" "/MTd" ${flag_var} "${${flag_var}}")
    endforeach(flag_var)

    if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
        # For some reason CMake seems to be including the debug
        # version of this library on release builds as well so we
        # need to ignore it. Not adding this to clang-cl as it
        # does not seem to recognise it.
        set(CMAKE_LINKER_FLAGS ${CMAKE_LINKER_FLAGS}
            /NODEFAULTLIB:\"libcmtd.lib\")
    endif()

    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG}" CACHE STRING "MSVC C Debug MT flags " FORCE)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}" CACHE STRING "MSVC CXX Debug MT flags " FORCE)
    set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE}" CACHE STRING "MSVC C Release MT flags " FORCE)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}" CACHE STRING "MSVC CXX Release MT flags " FORCE)
    set(CMAKE_C_FLAGS_MINSIZEREL "${CMAKE_C_FLAGS_MINSIZEREL}" CACHE STRING "MSVC C Debug MT flags " FORCE)
    set(CMAKE_CXX_FLAGS_MINSIZEREL "${CMAKE_CXX_FLAGS_MINSIZEREL}" CACHE STRING "MSVC C Release MT flags " FORCE)
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO}" CACHE STRING "MSVC CXX Debug MT flags " FORCE)
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO}" CACHE STRING "MSVC CXX Release MT flags " FORCE)

endif()

# parameters for boost tests
set(boost_test_parameters "--log_level=error")

# user includes
include_directories(
    ${CMAKE_SOURCE_DIR}/projects/all_path_and_directory_settings/cpp_backend/some_include_dir
    ${CMAKE_SOURCE_DIR}/projects/boost_model/include
    ${CMAKE_SOURCE_DIR}/projects/compressed/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_98/include
    ${CMAKE_SOURCE_DIR}/projects/cpp_model/include
    ${CMAKE_SOURCE_DIR}/projects/disable_cmakelists/include
    ${CMAKE_SOURCE_DIR}/projects/disable_facet_folders/include
    ${CMAKE_SOURCE_DIR}/projects/enable_facet_hash/include
    ${CMAKE_SOURCE_DIR}/projects/enable_facet_io/include
    ${CMAKE_SOURCE_DIR}/projects/enable_facet_serialization/include
    ${CMAKE_SOURCE_DIR}/projects/enable_facet_types/include
    ${CMAKE_SOURCE_DIR}/projects/flat_directory_mode/include
    ${CMAKE_SOURCE_DIR}/projects/lam_model/cpp/include
    ${CMAKE_SOURCE_DIR}/projects/seam/include
    ${CMAKE_SOURCE_DIR}/projects/split_project/dir/inc/another
    ${CMAKE_SOURCE_DIR}/projects/std_model/include
    ${CMAKE_SOURCE_DIR}/projects/test_model_sanitizer/include
    ${CMAKE_SOURCE_DIR}/projects/two_layers_with_objects/include
    ${CMAKE_SOURCE_DIR}/projects/utility/include
    )

#
# feature specific projects
#
if(ODB_FOUND)
    message(STATUS "Adding ODB feature test project")
    include_directories(${CMAKE_SOURCE_DIR}/projects/northwind/include)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/northwind)
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/northwind/tests)
endif()

#
# add projects
#
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/all_path_and_directory_settings/cpp_backend)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/boost_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/compressed)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_98)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/cpp_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/disable_facet_folders)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/enable_facet_hash)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/enable_facet_io)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/enable_facet_serialization)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/enable_facet_types)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/flat_directory_mode)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lam_model/cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/models)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/seam)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/split_project/some_dir/split_project)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/std_model)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test_model_sanitizer/tests)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/two_layers_with_objects)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/utility)
