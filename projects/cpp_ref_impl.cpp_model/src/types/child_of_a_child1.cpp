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
#include <ostream>
#include "cpp_ref_impl.cpp_model/types/child_of_a_child1.hpp"
#include "cpp_ref_impl.cpp_model/io/third_child_with_members_io.hpp"

namespace cpp_ref_impl::cpp_model {

child_of_a_child1::child_of_a_child1(
    const int prop_0,
    const unsigned int prop_1)
    : cpp_ref_impl::cpp_model::third_child_with_members(
      prop_0,
      prop_1) { }

void child_of_a_child1::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::cpp_model::child_of_a_child1\"" << ", "
      << "\"__parent_0__\": ";
    cpp_ref_impl::cpp_model::third_child_with_members::to_stream(s);
    s << " }";
}

void child_of_a_child1::swap(child_of_a_child1& other) noexcept {
    cpp_ref_impl::cpp_model::third_child_with_members::swap(other);

}

bool child_of_a_child1::equals(const cpp_ref_impl::cpp_model::parent_with_members& other) const {
    const child_of_a_child1* const p(dynamic_cast<const child_of_a_child1* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool child_of_a_child1::operator==(const child_of_a_child1& rhs) const {
    return cpp_ref_impl::cpp_model::third_child_with_members::compare(rhs);
}

child_of_a_child1& child_of_a_child1::operator=(child_of_a_child1 other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

}
