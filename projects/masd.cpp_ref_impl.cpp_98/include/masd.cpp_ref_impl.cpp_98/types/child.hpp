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
#ifndef MASD_CPP_REF_IMPL_CPP_98_TYPES_CHILD_HPP
#define MASD_CPP_REF_IMPL_CPP_98_TYPES_CHILD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "masd.cpp_ref_impl.cpp_98/types/parent.hpp"
#include "masd.cpp_ref_impl.cpp_98/serialization/child_fwd_ser.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

class child : public masd::cpp_ref_impl::cpp_98::parent {
public:
    child();

    virtual ~child() { }

public:
    child(
        const int prop_0,
        const int prop_1);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::cpp_98::child& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::cpp_98::child& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const;

public:
    int prop_1() const;
    void prop_1(const int v);

public:
    bool operator==(const child& rhs) const;
    bool operator!=(const child& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const masd::cpp_ref_impl::cpp_98::parent& other) const;

public:
    void swap(child& other);
    child& operator=(child other);

private:
    int prop_1_;
};

} } }

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::cpp_98::child& lhs,
    masd::cpp_ref_impl::cpp_98::child& rhs) {
    lhs.swap(rhs);
}

}

#endif
