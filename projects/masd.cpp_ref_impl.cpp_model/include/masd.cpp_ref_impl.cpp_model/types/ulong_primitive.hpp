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
#ifndef MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_ULONG_PRIMITIVE_HPP
#define MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_ULONG_PRIMITIVE_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "masd.cpp_ref_impl.cpp_model/serialization/ulong_primitive_fwd_ser.hpp"

namespace masd::cpp_ref_impl::cpp_model {
/**
 * @brief Test a primitive with an underlying unsigned long.
 */
class ulong_primitive final {
public:
    ulong_primitive() = default;
    ulong_primitive(const ulong_primitive&) = default;
    ulong_primitive(ulong_primitive&&) = default;
    ~ulong_primitive() = default;
public:
    explicit ulong_primitive(const unsigned long value);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::cpp_model::ulong_primitive& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::cpp_model::ulong_primitive& v, unsigned int version);

public:
    /**
     * @brief Obtain the underlying value.
     */
    /**@{*/
    unsigned long value() const;
    void value(const unsigned long v);
    /**@}*/

public:
    explicit operator unsigned long() const {
        return value_;
    }

public:
    bool operator==(const ulong_primitive& rhs) const;
    bool operator!=(const ulong_primitive& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(ulong_primitive& other) noexcept;
    ulong_primitive& operator=(ulong_primitive other);

private:
    unsigned long value_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::cpp_model::ulong_primitive& lhs,
    masd::cpp_ref_impl::cpp_model::ulong_primitive& rhs) {
    lhs.swap(rhs);
}

}

#endif