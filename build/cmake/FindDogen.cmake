# -*- mode: cmake; cmake-tab-width: 4; indent-tabs-mode: nil -*-
#
# Copyright (C) 2016 Domain Driven Consulting Plc
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
# Set CMAKE_PROGRAM_PATH as required
#
find_program(DOGEN_KNITTER_EXECUTABLE NAMES masd.dogen.knitter)
if (DOGEN_KNITTER_EXECUTABLE)
    execute_process(
        COMMAND ${DOGEN_KNITTER_EXECUTABLE} --version
        COMMAND grep ^Dogen
        COMMAND cut -b15-
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        ERROR_VARIABLE DOGEN_ERROR
        OUTPUT_VARIABLE DOGEN_KNITTER_VERSION
        RESULT_VARIABLE DOGEN_RESULT
        OUTPUT_STRIP_TRAILING_WHITESPACE)

      message(STATUS "Found Dogen Knitter: ${DOGEN_KNITTER_VERSION}...")
else()
    message(STATUS "Dogen Knitter not found.")
endif()
