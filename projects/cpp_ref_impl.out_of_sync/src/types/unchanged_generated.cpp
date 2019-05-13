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
#include "cpp_ref_impl.out_of_sync/types/unchanged_generated.hpp"

namespace cpp_ref_impl::out_of_sync {

unchanged_generated::unchanged_generated()
    : public_attribute_(static_cast<int>(0)),
      private_attribute_(static_cast<int>(0)) { }

unchanged_generated::unchanged_generated(
    const int public_attribute,
    const int private_attribute)
    : public_attribute_(public_attribute),
      private_attribute_(private_attribute) { }

void unchanged_generated::swap(unchanged_generated& other) noexcept {
    using std::swap;
    swap(public_attribute_, other.public_attribute_);
    swap(private_attribute_, other.private_attribute_);
}

bool unchanged_generated::operator==(const unchanged_generated& rhs) const {
    return public_attribute_ == rhs.public_attribute_ &&
        private_attribute_ == rhs.private_attribute_;
}

unchanged_generated& unchanged_generated::operator=(unchanged_generated other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int unchanged_generated::public_attribute() const {
    return public_attribute_;
}

void unchanged_generated::public_attribute(const int v) {
    public_attribute_ = v;
}

int unchanged_generated::private_attribute() const {
    return private_attribute_;
}

void unchanged_generated::private_attribute(const int v) {
    private_attribute_ = v;
}

}
