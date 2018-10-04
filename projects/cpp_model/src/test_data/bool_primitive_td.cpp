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
#include "cpp_ref_impl/cpp_model/test_data/bool_primitive_td.hpp"

namespace {

bool create_bool(const unsigned int position) {
    return (position % 2) != 0;
}

}

namespace cpp_ref_impl {
namespace cpp_model {

bool_primitive_generator::bool_primitive_generator() : position_(0) { }

void bool_primitive_generator::
populate(const unsigned int position, result_type& v) {
    v.value(create_bool(position + 1));
}

bool_primitive_generator::result_type
bool_primitive_generator::create(const unsigned int position) {
    bool_primitive r;
    bool_primitive_generator::populate(position, r);
    return r;
}

bool_primitive_generator::result_type*
bool_primitive_generator::create_ptr(const unsigned int position) {
    bool_primitive* r = new bool_primitive();
    bool_primitive_generator::populate(position, *r);
    return r;
}

bool_primitive_generator::result_type
bool_primitive_generator::operator()() {
    return create(position_++);
}

} }
