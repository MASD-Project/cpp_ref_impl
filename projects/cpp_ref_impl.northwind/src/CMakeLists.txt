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
set(files "")
file(GLOB_RECURSE files RELATIVE
    "${CMAKE_CURRENT_SOURCE_DIR}/"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

if(NOT ODB_LIBODB_FOUND)
    message(FATAL "ODB include directories not defined.")
endif()

set(odb_files "")
file(GLOB_RECURSE odb_files RELATIVE
   "${CMAKE_CURRENT_SOURCE_DIR}/"
   "${CMAKE_CURRENT_SOURCE_DIR}/*.cxx")
set(files ${files} ${odb_files})

add_library(cpp_ref_impl_northwind ${files})
set_target_properties(cpp_ref_impl_northwind PROPERTIES
    OUTPUT_NAME cpp_ref_impl_northwind)

install(TARGETS cpp_ref_impl_northwind
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    COMPONENT libraries)

#
# ODB Executable Targets
#
if (ODB_EXECUTABLE)
    # Top-level targets
    add_custom_target(odb_cpp_ref_impl_northwind)
    add_dependencies(odb_all odb_cpp_ref_impl_northwind)

    # Individual targets
    get_directory_property(dirs INCLUDE_DIRECTORIES)
    set(global_includes "")
    foreach(dir in ${dirs})
        set(global_includes ${global_includes} -I ${dir})
    endforeach()

    add_custom_target(odb_cpp_ref_impl_northwind_categories
        COMMENT "ODB categories"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/categories_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/categories.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/categories-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/categories-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_categories)

    add_custom_target(odb_cpp_ref_impl_northwind_category_id
        COMMENT "ODB category_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/category_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/category_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/category_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/category_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_category_id)

    add_custom_target(odb_cpp_ref_impl_northwind_class_0
        COMMENT "ODB class_0"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/package/class_0_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/package
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/package/class_0.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/package/class_0-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/package/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/package/class_0-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/package/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_class_0)

    add_custom_target(odb_cpp_ref_impl_northwind_customer_id
        COMMENT "ODB customer_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/customer_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/customer_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/customer_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/customer_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_customer_id)

    add_custom_target(odb_cpp_ref_impl_northwind_customers
        COMMENT "ODB customers"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/customers_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/customers.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/customers-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/customers-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_customers)

    add_custom_target(odb_cpp_ref_impl_northwind_employee_id
        COMMENT "ODB employee_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/employee_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/employee_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/employee_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/employee_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_employee_id)

    add_custom_target(odb_cpp_ref_impl_northwind_employees
        COMMENT "ODB employees"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/employees_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/employees.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/employees-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/employees-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_employees)

    add_custom_target(odb_cpp_ref_impl_northwind_order_details
        COMMENT "ODB order_details"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/order_details_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/order_details.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_details-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_details-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_order_details)

    add_custom_target(odb_cpp_ref_impl_northwind_order_details_key
        COMMENT "ODB order_details_key"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/order_details_key_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/order_details_key.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_details_key-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_details_key-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_order_details_key)

    add_custom_target(odb_cpp_ref_impl_northwind_order_id
        COMMENT "ODB order_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/order_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/order_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/order_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_order_id)

    add_custom_target(odb_cpp_ref_impl_northwind_orders
        COMMENT "ODB orders"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/orders_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/orders.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/orders-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/orders-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_orders)

    add_custom_target(odb_cpp_ref_impl_northwind_product_id
        COMMENT "ODB product_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/product_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/product_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/product_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/product_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_product_id)

    add_custom_target(odb_cpp_ref_impl_northwind_products
        COMMENT "ODB products"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/products_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/products.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/products-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/products-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_products)

    add_custom_target(odb_cpp_ref_impl_northwind_shipper_id
        COMMENT "ODB shipper_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/shipper_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/shipper_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/shipper_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/shipper_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_shipper_id)

    add_custom_target(odb_cpp_ref_impl_northwind_shippers
        COMMENT "ODB shippers"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/shippers_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/shippers.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/shippers-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/shippers-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_shippers)

    add_custom_target(odb_cpp_ref_impl_northwind_supplier_id
        COMMENT "ODB supplier_id"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/supplier_id_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/supplier_id.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/supplier_id-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/supplier_id-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_supplier_id)

    add_custom_target(odb_cpp_ref_impl_northwind_suppliers
        COMMENT "ODB suppliers"
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        COMMAND ${ODB_EXECUTABLE}
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/common_options.odb
            --options-file ${CMAKE_CURRENT_SOURCE_DIR}/odb/suppliers_options.odb
            --output-dir ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb
            -I ${ODB_INCLUDE_DIRS} ${global_includes}
            ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/types/suppliers.hpp
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/suppliers-odb-pgsql.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        COMMAND mv ${CMAKE_CURRENT_SOURCE_DIR}/../include/cpp_ref_impl.northwind/odb/suppliers-odb-sqlite.cxx ${CMAKE_CURRENT_SOURCE_DIR}/odb/
        VERBATIM
    )
    add_dependencies(odb_cpp_ref_impl_northwind odb_cpp_ref_impl_northwind_suppliers)
endif()
