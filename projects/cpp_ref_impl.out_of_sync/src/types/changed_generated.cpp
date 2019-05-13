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
#include "cpp_ref_impl.out_of_sync/types/changed_generated.hpp"

namespace cpp_ref_impl::out_of_sync {

changed_generated::changed_generated()
    : public_attribute_(static_cast<int>(0)) { }

changed_generated::changed_generated(const int public_attribute)
    : public_attribute_(public_attribute) { }

void changed_generated::swap(changed_generated& other) noexcept {
    using std::swap;
    swap(public_attribute_, other.public_attribute_);
}

bool changed_generated::operator==(const changed_generated& rhs) const {
    return public_attribute_ == rhs.public_attribute_;
}

changed_generated& changed_generated::operator=(changed_generated other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int changed_generated::public_attribute() const {
    return public_attribute_;
}

void changed_generated::public_attribute(const int v) {
    public_attribute_ = v;
}

}
