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
cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

# ctest support
enable_testing()

#
# Setup CCache
#
find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    message(STATUS "Found CCache (${CCACHE_PROGRAM})...")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")

    execute_process(COMMAND ${CCACHE_PROGRAM} --max-size=5G
        ${CCACHE_PROGRAM} --show-stats
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})
else()
    message(STATUS "CCache NOT found.")
endif()

project(masd_cpp_ref_impl)

# add our own modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/build/cmake)

# options
option(WITH_COVERALLS "Generate coveralls coverage." off)
option(WITH_PROFILING "Build the project with profiling support" off)
option(WITH_MINIMAL_PACKAGING "Package just the main application" off)
option(WITH_BENCHMARKS "Adds targets for running benchmarks" on)
option(WITH_JSON_VALIDATION "Adds JSON validation targets. Requires jq." on)

#
# check for dependencies
#

# threads
find_package(Threads REQUIRED)

# boost
# force static linking for all libraries
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(BOOST_ALL_DYN_LINK OFF)

# Note: it is possible to build with older versions of boost, but
# these require patches.
find_package(Boost 1.61 REQUIRED COMPONENTS
    system
    serialization
    date_time
    log
    filesystem
    program_options
    unit_test_framework
    )

if (Boost_FOUND)
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
endif()

# odb
find_package(Oracle)
if (ORACLE_FOUND)
    find_package(ODB COMPONENTS boost oracle pgsql)
    if (ODB_FOUND)
        message(STATUS "Found odb...")

        include_directories(SYSTEM ${ORACLE_INCLUDE_DIR} ${ODB_INCLUDE_DIRS})
        set(LIBS ${LIBS} ${ORACLE_LIBRARY} ${ODB_LIBRARIES} ${Boost_LIBRARIES})
    else()
        message(STATUS "odb not found.")
    endif()
else()
    message(STATUS "Oracle not found.")
endif()

# packaging type
if (WITH_MINIMAL_PACKAGING)
    message(STATUS "Packaging just the main application")
else()
    message(STATUS "Packaging everything main application")
endif()

# profiling
if (WITH_PROFILING)
    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        message(STATUS "Profiling enabled...")
    else()
        message(STATUS "Ignoring attempt to enable profiling without debug.")
        set(WITH_PROFILING off)
    endif()
else()
    message(STATUS "Profiling NOT enabled...")
endif()

# coveralls
if (WITH_COVERALLS)
    if (WITH_PROFILING)
        message(STATUS "Coveralls enabled...")
    else()
        message(STATUS "Ignoring attempt to enable Coveralls without profiling.")
        set(WITH_COVERALLS off)
    endif()
endif()

#
# setup git
#
find_program(GIT_COMMAND NAMES git)
if (GIT_COMMAND)
    message(STATUS "Found git (${GIT_COMMAND})...")
else()
    message(FATAL_ERROR "git not found.")
endif()


#
# setup jq, for JSON validation.
#
find_program(JQ_COMMAND NAMES jq)
if (JQ_COMMAND)
    message(STATUS "Found jq (${JQ_COMMAND})...")
    add_custom_target(validate_all_json)
    add_custom_target(indent_all_json)
else()
    message(STATUS "jq not found, disabling JSON validation.")
    set(WITH_JSON_VALIDATION "off")
endif()

# hash of the top commit
execute_process(COMMAND ${GIT_COMMAND} rev-list -n 1 HEAD
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    ERROR_VARIABLE git_error
    OUTPUT_VARIABLE CURRENT_GIT_COMMIT
    RESULT_VARIABLE ret_var
    OUTPUT_STRIP_TRAILING_WHITESPACE)

#
# useful vars
#

# site (for ctest)
site_name(MASD_CPP_REF_IMPL_SITE)

# setup staging directory
set(stage_dir ${PROJECT_BINARY_DIR}/stage)
if(NOT EXISTS "${stage_dir}")
    make_directory("${stage_dir}")
endif()

set(stage_bin_dir ${stage_dir}/bin)
if(NOT EXISTS "${stage_bin_dir}")
    make_directory("${stage_bin_dir}")
endif()

set(stage_pkg_dir ${stage_dir}/pkg)
if(NOT EXISTS "${stage_pkg_dir}")
    make_directory("${stage_pkg_dir}")
endif()
set(DOGEN_PACKAGE_DIR "${stage_pkg_dir}")

set(stage_lib_dir ${stage_dir}/lib)
if(NOT EXISTS "${stage_lib_dir}")
    make_directory("${stage_lib_dir}")
endif()

set(stage_inc_dir ${stage_dir}/include)
if(NOT EXISTS "${stage_inc_dir}")
    make_directory("${stage_inc_dir}")
endif()

#
# ensure cmake dumps binaries in the right places
#
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${stage_bin_dir})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${stage_bin_dir})

if(MSVC)
    foreach(CONFIGURATION_TYPE ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${CONFIGURATION_TYPE} CONFIGURATION_TYPE)
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${CONFIGURATION_TYPE} ${stage_bin_dir})
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${CONFIGURATION_TYPE} ${stage_bin_dir})
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CONFIGURATION_TYPE} ${stage_bin_dir})
    endforeach()
endif()

# debug
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building WITH DEBUG symbols...")
else()
    message(STATUS "Building WITHOUT DEBUG symbols...")
endif()

#
# Analysis and formatting tools
#
find_package(ClangTools)
if (CLANG_FORMAT_FOUND)
    message(STATUS "Found clang-format (${CLANG_FORMAT_BIN}).")
else()
    message(STATUS "Could not find clang-format.")
endif()

if (CLANG_TIDY_FOUND)
    message(STATUS "Found clang-tidy (${CLANG_FORMAT_BIN}).")
else()
    message(STATUS "Could not find clang-tidy.")
endif()

find_package(cppcheck)
if (CPPCHECK_FOUND)
    message(STATUS "Found cppcheck (${CPPCHECK_EXECUTABLE}).")
else()
    message(STATUS "Could not find cppcheck.")
endif()

#
# Log level to use for all Dogen tools
#
set(DOGEN_LOG_LEVEL "debug")

#
# Dogen
#
find_package(Dogen)

#
# aggregate targets and their aliases
#
add_custom_target(run_all_tests)
add_custom_target(rat)
add_dependencies(rat run_all_tests)
add_custom_target(run_windows_green_tests)

if (DOGEN_KNITTER_EXECUTABLE)
    add_custom_target(knit_all_dia)
    add_custom_target(knit_all_json)
    add_custom_target(ka)
    add_dependencies(ka knit_all_dia)
endif()

if (DOGEN_TAILOR_EXECUTABLE)
    add_custom_target(tailor_all)
    add_custom_target(ta)
    add_dependencies(ta tailor_all)
endif()

if (WITH_JSON_VALIDATION)
    add_custom_target(iaj)
    add_custom_target(vaj)

    add_dependencies(iaj indent_all_json)
    add_dependencies(vaj indent_all_json)
endif()

#
# Benchmarks
#
if(NOT UNIX)
    set(WITH_BENCHMARKS "off")
endif()

if(WITH_BENCHMARKS)
    set(benchmark_repeats "20")
    set(benchmark_command "${CMAKE_SOURCE_DIR}/build/scripts/benchmark.linux.sh")
    set(benchmark_directory "${stage_test_data_dir}/benchmarks/actual")
    set(benchmark_prefix "")
    if(NOT EXISTS "${benchmark_directory}")
        make_directory("${benchmark_directory}")
    endif()

    add_custom_target(benchmark_stats)
    add_custom_target(benchmark_all)
    add_custom_target(ba)
    add_dependencies(ba benchmark_all)

    add_custom_target(benchmark_dia)
    add_custom_target(benchmark_json)
    add_dependencies(benchmark_all benchmark_dia)
endif()

#
# include all sub directories
#
add_subdirectory(${CMAKE_SOURCE_DIR}/projects)
