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
#ifndef CPP_REF_IMPL_NORTHWIND_TYPES_SHIPPER_ID_HPP
#define CPP_REF_IMPL_NORTHWIND_TYPES_SHIPPER_ID_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl.northwind/serialization/shipper_id_fwd_ser.hpp"

namespace cpp_ref_impl::northwind {
class shipper_id final {
public:
    shipper_id(const shipper_id&) = default;
    shipper_id(shipper_id&&) = default;
    ~shipper_id() = default;
public:
    shipper_id();

public:
    explicit shipper_id(const int value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::northwind::shipper_id& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::northwind::shipper_id& v, unsigned int version);

public:
    /**
     * @brief Obtain the underlying value.
     */
    /**@{*/
    int value() const;
    void value(const int v);
    /**@}*/

public:
    explicit operator int() const {
        return value_;
    }

public:
    bool operator==(const shipper_id& rhs) const;
    bool operator!=(const shipper_id& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(shipper_id& other) noexcept;
    shipper_id& operator=(shipper_id other);

private:
    int value_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::northwind::shipper_id& lhs,
    cpp_ref_impl::northwind::shipper_id& rhs) {
    lhs.swap(rhs);
}

}

#endif
