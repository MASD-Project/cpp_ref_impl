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
#ifndef CPP_REF_IMPL_CPP_98_TYPES_PACKAGE1_FIRST_CLASS_HPP
#define CPP_REF_IMPL_CPP_98_TYPES_PACKAGE1_FIRST_CLASS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl.cpp_98/serialization/package1/first_class_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {
namespace package1 {

class first_class {
public:
    first_class();

public:
    first_class(
        const int public_attribute,
        const int private_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_98::package1::first_class& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_98::package1::first_class& v, unsigned int version);

public:
    int public_attribute() const;
    void public_attribute(const int v);

    int private_attribute() const;
    void private_attribute(const int v);

public:
    bool operator==(const first_class& rhs) const;
    bool operator!=(const first_class& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(first_class& other);
    first_class& operator=(first_class other);

private:
    int public_attribute_;
    int private_attribute_;
};

} } }

namespace std {

template<>
inline void swap(
    cpp_ref_impl::cpp_98::package1::first_class& lhs,
    cpp_ref_impl::cpp_98::package1::first_class& rhs) {
    lhs.swap(rhs);
}

}

#endif
