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
#ifndef CPP_REF_IMPL_DELETE_EXTRA_TYPES_ONE_PROPERTY_HPP
#define CPP_REF_IMPL_DELETE_EXTRA_TYPES_ONE_PROPERTY_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl.delete_extra/serialization/one_property_fwd_ser.hpp"

namespace cpp_ref_impl::delete_extra {

/**
 * @brief This class has not changed.
 */
class one_property final {
public:
    one_property(const one_property&) = default;
    one_property(one_property&&) = default;
    ~one_property() = default;

public:
    one_property();

public:
    explicit one_property(const int public_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::delete_extra::one_property& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::delete_extra::one_property& v, unsigned int version);

public:
    int public_attribute() const;
    void public_attribute(const int v);

public:
    bool operator==(const one_property& rhs) const;
    bool operator!=(const one_property& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(one_property& other) noexcept;
    one_property& operator=(one_property other);

private:
    int public_attribute_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::delete_extra::one_property& lhs,
    cpp_ref_impl::delete_extra::one_property& rhs) {
    lhs.swap(rhs);
}

}

#endif
