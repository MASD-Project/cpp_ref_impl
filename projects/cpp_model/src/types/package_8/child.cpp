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
#include "cpp_ref_impl/cpp_model/types/package_8/child.hpp"
#include "cpp_ref_impl/cpp_model/io/package_7/parent_io.hpp"

namespace cpp_ref_impl::cpp_model::package_8 {

child::child()
    : prop_1_(static_cast<int>(0)) { }

child::child(
    const int prop_0,
    const int prop_1)
    : cpp_ref_impl::cpp_model::package_7::parent(prop_0),
      prop_1_(prop_1) { }

void child::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::cpp_model::package_8::child\"" << ", "
      << "\"__parent_0__\": ";
    cpp_ref_impl::cpp_model::package_7::parent::to_stream(s);
    s << ", "
      << "\"prop_1\": " << prop_1_
      << " }";
}

void child::swap(child& other) noexcept {
    cpp_ref_impl::cpp_model::package_7::parent::swap(other);

    using std::swap;
    swap(prop_1_, other.prop_1_);
}

bool child::equals(const cpp_ref_impl::cpp_model::package_7::parent& other) const {
    const child* const p(dynamic_cast<const child* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool child::operator==(const child& rhs) const {
    return cpp_ref_impl::cpp_model::package_7::parent::compare(rhs) &&
        prop_1_ == rhs.prop_1_;
}

child& child::operator=(child other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int child::prop_1() const {
    return prop_1_;
}

void child::prop_1(const int v) {
    prop_1_ = v;
}

}
