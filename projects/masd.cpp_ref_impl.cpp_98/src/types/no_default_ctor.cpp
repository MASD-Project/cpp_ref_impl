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
#include "masd.cpp_ref_impl.cpp_98/types/no_default_ctor.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

no_default_ctor::no_default_ctor()
     { }

no_default_ctor::no_default_ctor(const std::string& prop_0)
    : prop_0_(prop_0) { }

void no_default_ctor::swap(no_default_ctor& other) {
    using std::swap;
    swap(prop_0_, other.prop_0_);
}

bool no_default_ctor::operator==(const no_default_ctor& rhs) const {
    return prop_0_ == rhs.prop_0_;
}

no_default_ctor& no_default_ctor::operator=(no_default_ctor other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::string& no_default_ctor::prop_0() const {
    return prop_0_;
}

std::string& no_default_ctor::prop_0() {
    return prop_0_;
}

void no_default_ctor::prop_0(const std::string& v) {
    prop_0_ = v;
}

} } }
