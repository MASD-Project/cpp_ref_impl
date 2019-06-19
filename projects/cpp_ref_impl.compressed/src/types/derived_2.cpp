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
#include "cpp_ref_impl.compressed/io/base_io.hpp"
#include "cpp_ref_impl.compressed/types/derived_2.hpp"

namespace cpp_ref_impl {
namespace compressed {

derived_2::derived_2()
    : prop_2_(static_cast<int>(0)) { }

derived_2::derived_2(
    const int prop_0,
    const int prop_2)
    : cpp_ref_impl::compressed::base(prop_0),
      prop_2_(prop_2) { }

void derived_2::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::compressed::derived_2\"" << ", "
      << "\"__parent_0__\": ";
    cpp_ref_impl::compressed::base::to_stream(s);
    s << ", "
      << "\"prop_2\": " << prop_2_
      << " }";
}

void derived_2::swap(derived_2& other) noexcept {
    cpp_ref_impl::compressed::base::swap(other);

    using std::swap;
    swap(prop_2_, other.prop_2_);
}

bool derived_2::equals(const cpp_ref_impl::compressed::base& other) const {
    const derived_2* const p(dynamic_cast<const derived_2* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool derived_2::operator==(const derived_2& rhs) const {
    return cpp_ref_impl::compressed::base::compare(rhs) &&
        prop_2_ == rhs.prop_2_;
}

derived_2& derived_2::operator=(derived_2 other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int derived_2::prop_2() const {
    return prop_2_;
}

void derived_2::prop_2(const int v) {
    prop_2_ = v;
}

} }
