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
#ifndef CPP_REF_IMPL_OUT_OF_SYNC_TYPES_CHANGED_HANDCRAFTED_HPP
#define CPP_REF_IMPL_OUT_OF_SYNC_TYPES_CHANGED_HANDCRAFTED_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>

namespace cpp_ref_impl::out_of_sync {

/**
 * @brief This class is handcrafted. A new attribute was added after initial generation.
 */
class changed_handcrafted final {
public:
    changed_handcrafted() = default;
    changed_handcrafted(const changed_handcrafted&) = default;
    changed_handcrafted(changed_handcrafted&&) = default;
    ~changed_handcrafted() = default;
    changed_handcrafted& operator=(const changed_handcrafted&) = default;

public:
    bool operator==(const changed_handcrafted& rhs) const;
    bool operator!=(const changed_handcrafted& rhs) const {
        return !this->operator==(rhs);
    }

};

}

#endif
