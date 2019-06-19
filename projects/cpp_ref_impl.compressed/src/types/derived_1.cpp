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
#include "cpp_ref_impl.compressed/types/derived_1.hpp"

namespace cpp_ref_impl {
namespace compressed {

derived_1::derived_1()
    : prop_1_(static_cast<int>(0)) { }

derived_1::derived_1(
    const int prop_0,
    const int prop_1)
    : cpp_ref_impl::compressed::base(prop_0),
      prop_1_(prop_1) { }

void derived_1::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::compressed::derived_1\"" << ", "
      << "\"__parent_0__\": ";
    cpp_ref_impl::compressed::base::to_stream(s);
    s << ", "
      << "\"prop_1\": " << prop_1_
      << " }";
}

void derived_1::swap(derived_1& other) noexcept {
    cpp_ref_impl::compressed::base::swap(other);

    using std::swap;
    swap(prop_1_, other.prop_1_);
}

bool derived_1::equals(const cpp_ref_impl::compressed::base& other) const {
    const derived_1* const p(dynamic_cast<const derived_1* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool derived_1::operator==(const derived_1& rhs) const {
    return cpp_ref_impl::compressed::base::compare(rhs) &&
        prop_1_ == rhs.prop_1_;
}

derived_1& derived_1::operator=(derived_1 other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int derived_1::prop_1() const {
    return prop_1_;
}

void derived_1::prop_1(const int v) {
    prop_1_ = v;
}

} }
