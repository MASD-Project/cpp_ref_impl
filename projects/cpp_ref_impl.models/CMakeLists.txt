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

if (DOGEN_CLI_EXECUTABLE)
    # input models
    set(models cpp_ref_impl.directory_settings)
    set(models ${models} cpp_ref_impl.northwind)
    set(models ${models} cpp_ref_impl.boost_model)
    set(models ${models} cpp_ref_impl.cpp_98)
    set(models ${models} cpp_ref_impl.cpp_model)
    set(models ${models} cpp_ref_impl.disable_cmakelists)
    set(models ${models} cpp_ref_impl.disable_facet_folders)
    set(models ${models} cpp_ref_impl.enable_facet_hash)
    set(models ${models} cpp_ref_impl.enable_facet_io)
    set(models ${models} cpp_ref_impl.enable_facet_serialization)
    set(models ${models} cpp_ref_impl.enable_facet_types)
    set(models ${models} cpp_ref_impl.flat_directory_mode)
    set(models ${models} cpp_ref_impl.lam_model)
    set(models ${models} cpp_ref_impl.split_project)
    set(models ${models} cpp_ref_impl.std_model)
    set(models ${models} cpp_ref_impl.two_layers)

    # Uncomment the next line if you need to regenerate this model.
    # Ensue the extra files are not deleted and checked in.
    # set(models ${models} cpp_ref_impl.delete_extra)

    set(models ${models} cpp_ref_impl.skip_empty_dirs)
    set(models ${models} cpp_ref_impl.force_write)
    set(models ${models} cpp_ref_impl.ignore_extra)

    # Uncomment the next line if you need to regenerate this model.
    # You need to manually ensure that the model is out of sync with
    # the filesystem before checking in.
    # set(models ${models} cpp_ref_impl.out_of_sync)
endif()

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/org)
