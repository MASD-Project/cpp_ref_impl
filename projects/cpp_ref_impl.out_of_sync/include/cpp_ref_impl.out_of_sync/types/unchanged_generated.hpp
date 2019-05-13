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
#ifndef CPP_REF_IMPL_OUT_OF_SYNC_TYPES_UNCHANGED_GENERATED_HPP
#define CPP_REF_IMPL_OUT_OF_SYNC_TYPES_UNCHANGED_GENERATED_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl.out_of_sync/serialization/unchanged_generated_fwd_ser.hpp"

namespace cpp_ref_impl::out_of_sync {

/**
 * @brief This class has not changed.
 */
class unchanged_generated final {
public:
    unchanged_generated(const unchanged_generated&) = default;
    unchanged_generated(unchanged_generated&&) = default;
    ~unchanged_generated() = default;

public:
    unchanged_generated();

public:
    unchanged_generated(
        const int public_attribute,
        const int private_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::out_of_sync::unchanged_generated& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::out_of_sync::unchanged_generated& v, unsigned int version);

public:
    int public_attribute() const;
    void public_attribute(const int v);

    int private_attribute() const;
    void private_attribute(const int v);

public:
    bool operator==(const unchanged_generated& rhs) const;
    bool operator!=(const unchanged_generated& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(unchanged_generated& other) noexcept;
    unchanged_generated& operator=(unchanged_generated other);

private:
    int public_attribute_;
    int private_attribute_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::out_of_sync::unchanged_generated& lhs,
    cpp_ref_impl::out_of_sync::unchanged_generated& rhs) {
    lhs.swap(rhs);
}

}

#endif
