/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (C) 2012-2015 Marco Craveiro <marco.craveiro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#ifndef MASD_CPP_REF_IMPL_DIRECTORY_SETTINGS_TEST_DATA_DIR_PACKAGE_0_PACKAGE_0_1_CLASS_2_0_4_0_THE_TEST_DATA_HH
#define MASD_CPP_REF_IMPL_DIRECTORY_SETTINGS_TEST_DATA_DIR_PACKAGE_0_PACKAGE_0_1_CLASS_2_0_4_0_THE_TEST_DATA_HH

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "masd.cpp_ref_impl.directory_settings/types_dir/package_0/package_0_1/class_2_0_5_0_the_types.hh"

namespace masd::cpp_ref_impl::directory_settings::package_0::package_0_1 {

class class_2_generator {
public:
    class_2_generator();

public:
    typedef masd::cpp_ref_impl::directory_settings::package_0::package_0_1::class_2 result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
public:
    static result_type* create_ptr(const unsigned int position);
};

}

#endif