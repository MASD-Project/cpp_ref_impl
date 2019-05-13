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
#include "cpp_ref_impl.std_model/test_data/class_a_td.hpp"

namespace {

std::string create_std_string(const unsigned int position) {
    std::ostringstream s;
    s << "a_string_" << position;
    return s.str();
}

}

namespace cpp_ref_impl::std_model {

class_a_generator::class_a_generator() : position_(0) { }

void class_a_generator::
populate(const unsigned int position, result_type& v) {
    v.prop0(create_std_string(position + 0));
    v.prop1(create_std_string(position + 1));
}

class_a_generator::result_type
class_a_generator::create(const unsigned int position) {
    class_a r;
    class_a_generator::populate(position, r);
    return r;
}

class_a_generator::result_type*
class_a_generator::create_ptr(const unsigned int position) {
    class_a* p = new class_a();
    class_a_generator::populate(position, *p);
    return p;
}

class_a_generator::result_type
class_a_generator::operator()() {
    return create(position_++);
}

}
