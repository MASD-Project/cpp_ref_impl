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
#include "cpp_ref_impl.std_model/io/base_io.hpp"
#include "cpp_ref_impl.std_model/types/derived.hpp"
#include "cpp_ref_impl.std_model/io/pkg1/class_c_io.hpp"

namespace std {

inline std::ostream& operator<<(std::ostream& s, const std::list<cpp_ref_impl::std_model::pkg1::class_c>& v) {
    s << "[ ";
    for (auto i(v.begin()); i != v.end(); ++i) {
        if (i != v.begin()) s << ", ";
        s << *i;
    }
    s << "] ";
    return s;
}

}

namespace cpp_ref_impl::std_model {

derived::derived(
    const std::vector<std::string>& prop_0,
    const std::list<cpp_ref_impl::std_model::pkg1::class_c>& prop_1)
    : cpp_ref_impl::std_model::base(prop_0),
      prop_1_(prop_1) { }

void derived::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::std_model::derived\"" << ", "
      << "\"__parent_0__\": ";
    cpp_ref_impl::std_model::base::to_stream(s);
    s << ", "
      << "\"prop_1\": " << prop_1_
      << " }";
}

void derived::swap(derived& other) noexcept {
    cpp_ref_impl::std_model::base::swap(other);

    using std::swap;
    swap(prop_1_, other.prop_1_);
}

bool derived::equals(const cpp_ref_impl::std_model::base& other) const {
    const derived* const p(dynamic_cast<const derived* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool derived::operator==(const derived& rhs) const {
    return cpp_ref_impl::std_model::base::compare(rhs) &&
        prop_1_ == rhs.prop_1_;
}

derived& derived::operator=(derived other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<cpp_ref_impl::std_model::pkg1::class_c>& derived::prop_1() const {
    return prop_1_;
}

std::list<cpp_ref_impl::std_model::pkg1::class_c>& derived::prop_1() {
    return prop_1_;
}

void derived::prop_1(const std::list<cpp_ref_impl::std_model::pkg1::class_c>& v) {
    prop_1_ = v;
}

void derived::prop_1(const std::list<cpp_ref_impl::std_model::pkg1::class_c>&& v) {
    prop_1_ = std::move(v);
}

}
