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
#ifndef MASD_CPP_REF_IMPL_OUT_OF_SYNC_TYPES_CHANGED_GENERATED_HPP
#define MASD_CPP_REF_IMPL_OUT_OF_SYNC_TYPES_CHANGED_GENERATED_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "masd.cpp_ref_impl.out_of_sync/serialization/changed_generated_fwd_ser.hpp"

namespace masd::cpp_ref_impl::out_of_sync {

/**
 * @brief This class has a new attribute.
 */
class changed_generated final {
public:
    changed_generated(const changed_generated&) = default;
    changed_generated(changed_generated&&) = default;
    ~changed_generated() = default;

public:
    changed_generated();

public:
    explicit changed_generated(const int public_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::out_of_sync::changed_generated& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::out_of_sync::changed_generated& v, unsigned int version);

public:
    int public_attribute() const;
    void public_attribute(const int v);

public:
    bool operator==(const changed_generated& rhs) const;
    bool operator!=(const changed_generated& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(changed_generated& other) noexcept;
    changed_generated& operator=(changed_generated other);

private:
    int public_attribute_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::out_of_sync::changed_generated& lhs,
    masd::cpp_ref_impl::out_of_sync::changed_generated& rhs) {
    lhs.swap(rhs);
}

}

#endif
