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
#include "cpp_ref_impl.cpp_98/test_data/an_enumeration_td.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

an_enumeration_generator::an_enumeration_generator() : position_(0) { }
void an_enumeration_generator::
populate(const unsigned int position, result_type& v) {
    v = static_cast<an_enumeration>(position % 3);
}

an_enumeration_generator::result_type
an_enumeration_generator::create(const unsigned int  position) {
    result_type r;
    an_enumeration_generator::populate(position, r);
    return r;
}

an_enumeration_generator::result_type
an_enumeration_generator::operator()() {
    return create(position_++);
}

} }
