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

message(STATUS "CMake: ${CMAKE_VERSION}")

# ctest support
enable_testing()

#
# setup CCache
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

#
# options
#
option(WITH_COVERALLS "Generate coveralls coverage." off)
option(WITH_PROFILING "Build the project with profiling support" off)
option(WITH_MINIMAL_PACKAGING "Package just the main application" off)
option(WITH_BENCHMARKS "Adds targets for running benchmarks" on)
option(WITH_JSON_VALIDATION "Adds JSON validation targets. Requires jq." on)

#
# check for dependencies
#

#
# threads
#
find_package(Threads REQUIRED)

#
# boost
#
# force static linking for all libraries
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
set(BOOST_ALL_DYN_LINK OFF)

# note: it is possible to build with older versions of boost, but
# these require patches.
find_package(Boost 1.61 REQUIRED COMPONENTS
    system
    serialization
    date_time
    log
    thread
    filesystem
    program_options
    unit_test_framework
    regex
    chrono
    atomic
    )

if (Boost_FOUND)
    # FIXME: using global settings at present because dogen does not
    # FIXME: know how to add dependencies at the project level.
    include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
    set(LIBS ${LIBS} ${Boost_LIBRARIES})
endif()

#
# ODB
#

# First we try to locate the required libraries. Note that we split
# the compiler from the libraries so that we can build ODB code even
# if the compiler is not present. This is a common setup when using
# vcpkg. Note also that in order to compile and run the ODB tests we
# need all of the dependencies to be present.
set(odb_dependencies_found TRUE)

find_package(PostgreSQL)
if (PostgreSQL_FOUND)
    message(STATUS "PostgreSQL Found.")
else()
    message(STATUS "PostgreSQL NOT Found. Disabling ODB.")
    set(odb_dependencies_found FALSE)
endif()

find_package(SQLite3)
if (SQLite3_FOUND)
    message(STATUS "SQLite3 Found.")
else()
    message(STATUS "SQLite NOT Found. Disabling ODB.")
    set(odb_dependencies_found FALSE)
endif()

find_package(OpenSSL)
if (OpenSSL_FOUND)
    message(STATUS "OpenSSL Found.")
else()
    message(STATUS "OpenSSL NOT Found. Disabling ODB.")
    set(odb_dependencies_found FALSE)
endif()

if (odb_dependencies_found)
    find_package(ODB COMPONENTS boost pgsql sqlite)
    if (ODB_LIBODB_FOUND)
        message(STATUS "Found ODB Libraries...")
        # FIXME: using global settings at present because dogen does not
        # FIXME: know how to add dependencies at the project level.
        include_directories(SYSTEM ${ODB_LIBODB_INCLUDE_DIRS})
    else()
        message(STATUS "ODB Libraries NOT Found.")
    endif()

    if (ODB_FOUND)
        message(STATUS "Found ODB Compiler...")
    else()
        message(STATUS "ODB Compiler NOT Found.")
    endif()
endif()

#
# packaging type
#
if (WITH_MINIMAL_PACKAGING)
    message(STATUS "Packaging just the main application")
else()
    message(STATUS "Packaging everything main application")
endif()

#
# profiling
#
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

#
# Coverage
#
if (WITH_COVERALLS)
    if (WITH_PROFILING)
        message(STATUS "Coveralls enabled...")
    else()
        message(STATUS "Ignoring attempt to enable Coveralls without profiling.")
        set(WITH_COVERALLS off)
    endif()
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

#
# debug
#
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Building WITH DEBUG symbols...")
else()
    message(STATUS "Building WITHOUT DEBUG symbols...")
endif()

#
# analysis and formatting tools
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
# log level to use for all Dogen tools
#
set(DOGEN_LOG_LEVEL "debug")

#
# aggregate targets and their aliases
#
add_custom_target(run_all_tests)
add_custom_target(rat)
add_dependencies(rat run_all_tests)
add_custom_target(run_windows_green_tests)

#
# dogen and related top-level targets.
#
find_package(Dogen)

if (DOGEN_CLI_EXECUTABLE)
    add_custom_target(generate_all_dia)
    add_custom_target(generate_all_json)
    add_custom_target(gad)
    add_dependencies(gad generate_all_dia)
    add_custom_target(gaj)
    add_dependencies(gaj generate_all_json)
    add_custom_target(odb_all)
    add_custom_target(oa)
    add_dependencies(oa odb_all)

    add_custom_target(convert_all)
    add_custom_target(ca)
    add_dependencies(ca convert_all)

    add_custom_target(weave_all)
    add_custom_target(wa)
    add_dependencies(wa weave_all)

    #
    # Options to use for all Dogen invocations
    #
    set(DOGEN_LOG_LEVEL "debug")
    set(DOGEN_LOG_OPTIONS --log-enabled --log-level ${DOGEN_LOG_LEVEL})

    set(DOGEN_TRACING_OPTIONS "")
    # uncomment to enable tracing.
    # set(DOGEN_TRACING_OPTIONS ${DOGEN_TRACING_OPTIONS} --tracing-enabled)
    # set(DOGEN_TRACING_OPTIONS ${DOGEN_TRACING_OPTIONS} --tracing-level detail)
    # set(DOGEN_TRACING_OPTIONS ${DOGEN_TRACING_OPTIONS} --tracing-format org-mode)
    # set(DOGEN_TRACING_OPTIONS ${DOGEN_TRACING_OPTIONS} --tracing-guids-enabled)

    set(DOGEN_COMMON_OPTIONS ${DOGEN_LOG_OPTIONS} ${DOGEN_TRACING_OPTIONS})
    # uncomment the next line if you require compatibility support
    # set(DOGEN_COMMON_OPTIONS ${DOGEN_COMMON_OPTIONS} --compatibility-mode)

    #
    # Options for code generation only
    #
    set(projects_dir "${CMAKE_SOURCE_DIR}/projects")
    set(DOGEN_GENERATION_OPTIONS --output-directory ${projects_dir}/)
endif()

if (WITH_JSON_VALIDATION)
    add_custom_target(iaj)
    add_custom_target(vaj)

    add_dependencies(iaj indent_all_json)
    add_dependencies(vaj indent_all_json)
endif()

#
# benchmarks
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
