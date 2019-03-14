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
#include "masd.cpp_ref_impl.do_not_delete_empty_dirs/test_data/one_property_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return static_cast<int>(position);
}

}

namespace masd::cpp_ref_impl::do_not_delete_empty_dirs {

one_property_generator::one_property_generator() : position_(0) { }

void one_property_generator::
populate(const unsigned int position, result_type& v) {
    v.public_attribute(create_int(position + 0));
}

one_property_generator::result_type
one_property_generator::create(const unsigned int position) {
    one_property r;
    one_property_generator::populate(position, r);
    return r;
}

one_property_generator::result_type*
one_property_generator::create_ptr(const unsigned int position) {
    one_property* p = new one_property();
    one_property_generator::populate(position, *p);
    return p;
}

one_property_generator::result_type
one_property_generator::operator()() {
    return create(position_++);
}

}
