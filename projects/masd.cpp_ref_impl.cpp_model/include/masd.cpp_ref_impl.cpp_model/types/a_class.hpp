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
#ifndef MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_A_CLASS_HPP
#define MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_A_CLASS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "masd.cpp_ref_impl.cpp_model/types/book_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/colour_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_4/shape_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/serialization/a_class_fwd_ser.hpp"

namespace masd::cpp_ref_impl::cpp_model {

class a_class final {
public:
    a_class(const a_class&) = default;
    a_class(a_class&&) = default;
    ~a_class() = default;

public:
    a_class();

public:
    a_class(
        const masd::cpp_ref_impl::cpp_model::colour_types colour_type,
        const masd::cpp_ref_impl::cpp_model::book_types book_type,
        const masd::cpp_ref_impl::cpp_model::package_4::shape_types shape_type);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::cpp_model::a_class& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::cpp_model::a_class& v, unsigned int version);

public:
    masd::cpp_ref_impl::cpp_model::colour_types colour_type() const;
    void colour_type(const masd::cpp_ref_impl::cpp_model::colour_types v);

    masd::cpp_ref_impl::cpp_model::book_types book_type() const;
    void book_type(const masd::cpp_ref_impl::cpp_model::book_types v);

    masd::cpp_ref_impl::cpp_model::package_4::shape_types shape_type() const;
    void shape_type(const masd::cpp_ref_impl::cpp_model::package_4::shape_types v);

public:
    bool operator==(const a_class& rhs) const;
    bool operator!=(const a_class& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(a_class& other) noexcept;
    a_class& operator=(a_class other);

private:
    masd::cpp_ref_impl::cpp_model::colour_types colour_type_;
    masd::cpp_ref_impl::cpp_model::book_types book_type_;
    masd::cpp_ref_impl::cpp_model::package_4::shape_types shape_type_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::cpp_model::a_class& lhs,
    masd::cpp_ref_impl::cpp_model::a_class& rhs) {
    lhs.swap(rhs);
}

}

#endif
