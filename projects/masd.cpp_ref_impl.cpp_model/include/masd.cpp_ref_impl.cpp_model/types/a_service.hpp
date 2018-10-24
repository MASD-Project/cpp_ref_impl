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
#ifndef MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_A_SERVICE_HPP
#define MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_A_SERVICE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>

namespace masd::cpp_ref_impl::cpp_model {

class a_service final {
public:
    a_service() = default;
    a_service(const a_service&) = default;
    a_service(a_service&&) = default;
    ~a_service() = default;
    a_service& operator=(const a_service&) = default;

public:
    bool operator==(const a_service& rhs) const;
    bool operator!=(const a_service& rhs) const {
        return !this->operator==(rhs);
    }

};

}

#endif
