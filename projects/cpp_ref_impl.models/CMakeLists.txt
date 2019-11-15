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
set(input_dir "json")
set(output_dir "${CMAKE_CURRENT_SOURCE_DIR}/json")
set(folder "${CMAKE_CURRENT_SOURCE_DIR}/json")
if (WITH_JSON_VALIDATION)
    set(files "")

    file(GLOB_RECURSE files RELATIVE
        "${CMAKE_CURRENT_SOURCE_DIR}/${input_dir}"
        "${CMAKE_CURRENT_SOURCE_DIR}/${input_dir}/*.json")

    set(target "models.json")
    add_custom_target(validate_${target})
    add_dependencies(validate_all_json validate_${target})

    add_custom_target(indent_${target})
    add_dependencies(indent_all_json indent_${target})

    foreach(file ${files})
        add_custom_target(validate_${file}
            COMMENT "Validating JSON for ${target}/${file}."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMAND ${JQ_COMMAND} . ${folder}/${file} > /dev/null)
        add_dependencies(validate_${target} validate_${file})

        add_custom_target(indent_${file}
            COMMENT "Indenting JSON for ${target}/${file}."
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMAND ${JQ_COMMAND} . ${folder}/${file} > ${folder}/${file}_tmp
            COMMAND mv ${folder}/${file}_tmp ${folder}/${file})
        add_dependencies(indent_${target} indent_${file})

    endforeach()
endif()

#
# Conversion targets
#
if (DOGEN_CLI_EXECUTABLE)
    #
    # Model conversion
    #
    file(GLOB models "dia/*.dia")
    foreach(model ${models})
        set(model_name "")
        get_filename_component(model_name ${model} NAME)

        set(destination_name ${output_dir}/${model_name})
        string(REGEX REPLACE ".dia$" ".json" destination_name
            ${destination_name})

        add_custom_target(convert_${model_name}
            COMMENT "Converting ${model_name}."
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMAND ${DOGEN_CLI_EXECUTABLE} convert
            --source ${model} --destination ${destination_name}
            ${DOGEN_COMMON_OPTIONS})
        add_dependencies(convert_all convert_${model_name})
    endforeach()

    # input models
    set(models cpp_ref_impl.directory_settings)
    set(models ${models} cpp_ref_impl.northwind)
    set(models ${models} cpp_ref_impl.boost_model)
    set(models ${models} cpp_ref_impl.compressed)
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

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/dia)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/json)
