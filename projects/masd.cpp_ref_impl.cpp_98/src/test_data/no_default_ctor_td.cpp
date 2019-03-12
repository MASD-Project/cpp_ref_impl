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
#include <sstream>
#include "masd.cpp_ref_impl.cpp_98/test_data/no_default_ctor_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

}

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

no_default_ctor_generator::no_default_ctor_generator() : position_(0) { }

void no_default_ctor_generator::
populate(const unsigned int position, result_type& v) {
    v.prop_0(create_std_string(position + 0));
}

no_default_ctor_generator::result_type
no_default_ctor_generator::create(const unsigned int position) {
    no_default_ctor r;
    no_default_ctor_generator::populate(position, r);
    return r;
}

no_default_ctor_generator::result_type*
no_default_ctor_generator::create_ptr(const unsigned int position) {
    no_default_ctor* p = new no_default_ctor();
    no_default_ctor_generator::populate(position, *p);
    return p;
}

no_default_ctor_generator::result_type
no_default_ctor_generator::operator()() {
    return create(position_++);
}

} } }
