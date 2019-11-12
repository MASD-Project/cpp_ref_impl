# -*- mode: cmake; cmake-tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be  useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
# MA 02110-1301, USA.
#
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

#
# Handle input parameters to script. Define them as internal CMake
# variables.
#
if(DEFINED CTEST_SCRIPT_ARG)
    # transform ctest script arguments of the form
    # script.ctest,var1=value1,var2=value2
    # to variables with the respective names set to the respective values
    string(REPLACE "," ";" script_args "${CTEST_SCRIPT_ARG}")
    foreach(current_var ${script_args})
        if ("${current_var}" MATCHES "^([^=]+)=(.+)$")
            set("${CMAKE_MATCH_1}" "${CMAKE_MATCH_2}")
        endif()
    endforeach()
endif()

#
# Ensure all mandatory parameters have been set.
#
if(NOT DEFINED build_group)
    message(FATAL_ERROR "Build group parameter not defined.")
endif()

if(NOT DEFINED configuration_type)
    message(FATAL_ERROR "Configuration type parameter not defined.")
endif()

if(NOT DEFINED generator)
    message(FATAL_ERROR "Generator parameter not defined.")
endif()

if(NOT DEFINED compiler)
    message(FATAL_ERROR "Compiler parameter not defined.")
endif()

#
# Setup the environment for supported compilers.
#
if(${compiler} STREQUAL "gcc8")
    set(ENV{CC} "gcc-8")
    set(ENV{CXX} "g++-8")
    message(STATUS "Compiler: GCC-8")
elseif(${compiler} STREQUAL "gcc9")
    set(ENV{CC} "gcc-9")
    set(ENV{CXX} "g++-9")
    message(STATUS "Compiler: GCC-9")
elseif(${compiler} STREQUAL "clang8")
    set(ENV{CC} "clang-8")
    set(ENV{CXX} "clang++-8")
    message(STATUS "Compiler: Clang-8")
elseif(${compiler} STREQUAL "clang7")
    set(ENV{CC} "clang-7")
    set(ENV{CXX} "clang++-7")
    message(STATUS "Compiler: Clang-7")
elseif(${compiler} STREQUAL "clang")
    set(ENV{CC} "clang")
    set(ENV{CXX} "clang++")
    message(STATUS "Compiler: Clang")
elseif(${compiler} STREQUAL "clang-cl")
    set(ENV{CC} "clang-cl")
    set(ENV{CXX} "clang-cl")
    message(STATUS "Compiler: Clang-CL")
elseif(${compiler} STREQUAL "msvc")
    message(STATUS "Compiler: MSVC")
else()
    message(FATAL_ERROR "Unrecognised compiler: ${compiler}")
endif()

#
# Setup CTest variables
#
if (DEFINED ENV{BUILD_PROVIDER})
    set(CTEST_SITE $ENV{BUILD_PROVIDER})
else()
    site_name(APP_SITE)
    set(CTEST_SITE "${APP_SITE}")
endif()
set(SITE "${CTEST_SITE}")
set(CTEST_CMAKE_GENERATOR "${generator}")
set(CTEST_CONFIGURATION_TYPE "${configuration_type}")
set(CTEST_BUILD_NAME
    "${compiler}-${CMAKE_SYSTEM}-${CMAKE_SYSTEM_PROCESSOR}-${configuration_type}")
set(CTEST_SOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(build_folder "${compiler}/${CTEST_CONFIGURATION_TYPE}")
set(CTEST_BINARY_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/build/output/${build_folder}")

if(DEFINED number_of_jobs)
    set(CTEST_BUILD_FLAGS -j${number_of_jobs})
endif()

#
# Set limits for test output
#
set(CTEST_CUSTOM_MAXIMUM_PASSED_TEST_OUTPUT_SIZE 0)
set(CTEST_CUSTOM_MAXIMUM_FAILED_TEST_OUTPUT_SIZE 0)
set(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS 50)

#
# Defines for CMake.
#
set(cmake_defines "")
if(DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
    set(cmake_defines ${cmake_defines}
        "-DCMAKE_TOOLCHAIN_FILE=$ENV{CMAKE_TOOLCHAIN_FILE}")
endif()

if(DEFINED ENV{VCPKG_TARGET_TRIPLET})
    set(cmake_defines ${cmake_defines}
        "-DVCPKG_TARGET_TRIPLET=$ENV{VCPKG_TARGET_TRIPLET}")
endif()

if(DEFINED ENV{POSTGRES_SERVER_SETUP})
    set(cmake_defines ${cmake_defines} "-DWITH_POSTGRES=ON")
endif()

#
# We only want to enable the relational model for Linux.
#
if(UNIX AND NOT APPLE)
    set(cmake_defines ${cmake_defines} "-DWITH_RELATIONAL_SUPPORT=On")
endif()

# only run these for Nightly.
set(WITH_MEMCHECK false)

#
# Nightly
#
if(${build_group} MATCHES Nightly)
    # setup valgrind
    find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
    if(NOT CTEST_MEMORYCHECK_COMMAND)
        message("valgrind not found, disabling coverage.")
        set(WITH_MEMCHECK false)
    else()
        message("Found valgrind (${CTEST_MEMORYCHECK_COMMAND})...")
        set(WITH_MEMCHECK true)

        set(valgrind_options "--trace-children=yes")
        set(valgrind_options "${valgrind_options} --quiet")
        set(valgrind_options "${valgrind_options} --tool=memcheck")
        set(valgrind_options "${valgrind_options} --leak-check=full")
        set(valgrind_options "${valgrind_options} --show-reachable=yes")
        set(valgrind_options "${valgrind_options} --num-callers=50")
        set(valgrind_options "${valgrind_options} --demangle=yes")
        set(valgrind_options "${valgrind_options} --gen-suppressions=all")
        set(CTEST_MEMORYCHECK_COMMAND_OPTIONS ${valgrind_options})
        set(CTEST_MEMORYCHECK_SUPPRESSIONS_FILE
            "${CTEST_SOURCE_DIRECTORY}/build/valgrind/custom.supp")
    endif()
endif()

#
# Start the build
#

# ensure we start from a known state
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})

ctest_start(${build_group})

#
# Do not perform a git update when running from CI. This is because
# AppVeyor/Travis are already managing the git checkout.
#
if (NOT DEFINED ENV{BUILD_PROVIDER})
    find_program(CTEST_GIT_COMMAND NAMES git)
    if(NOT CTEST_GIT_COMMAND)
        message(FATAL_ERROR "git not found.")
    endif()
    set(CTEST_UPDATE_COMMAND "${CTEST_GIT_COMMAND}")
    set(CTEST_GIT_UPDATE_CUSTOM "${CTEST_GIT_COMMAND}" pull origin master)
    ctest_update(BUILD ${CTEST_SOURCE_DIRECTORY} RETURN_VALUE git_result)
    if (git_result LESS 0)
        message(FATAL_ERROR "Failed to update source code from git.")
    endif()
endif()

ctest_configure(BUILD ${CTEST_BINARY_DIRECTORY} OPTIONS "${cmake_defines}")
ctest_build()

#
# Note: because we are doing nothing with the return value, the build
# will be green even when tests fail. This is OK because we rely on
# CDash to see the testing status. Travis/AppVeyor just tells us
# weather the build and packaging steps have worked or failed.
#
ctest_test(RETURN_VALUE retval)

if(WITH_MEMCHECK AND CTEST_MEMORYCHECK_COMMAND)
    ctest_memcheck(PARALLEL_LEVEL ${number_of_jobs})
endif()

ctest_submit()
