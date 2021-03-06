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
#include "cpp_ref_impl.cpp_model/types/long_primitive.hpp"

namespace cpp_ref_impl::cpp_model {

long_primitive::long_primitive()
    : value_(static_cast<long>(0)) { }

long_primitive::long_primitive(const long value)
    : value_(value) { }

long long_primitive::value() const {
    return value_;
}

void long_primitive::value(const long v) {
    value_ = v;
}

bool long_primitive::operator==(const long_primitive& rhs) const {
    return value_ == rhs.value_;
}

void long_primitive::swap(long_primitive& other) noexcept {
    using std::swap;
    swap(value_, other.value_);
}

long_primitive& long_primitive::operator=(long_primitive other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

}
