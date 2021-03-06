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
#ifndef CPP_REF_IMPL_CPP_MODEL_TYPES_PACKAGE_6_CHILD_HPP
#define CPP_REF_IMPL_CPP_MODEL_TYPES_PACKAGE_6_CHILD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "cpp_ref_impl.cpp_model/types/package_6/parent.hpp"
#include "cpp_ref_impl.cpp_model/serialization/package_6/child_fwd_ser.hpp"

namespace cpp_ref_impl::cpp_model::package_6 {

class child final : public cpp_ref_impl::cpp_model::package_6::parent {
public:
    child(const child&) = default;
    child(child&&) = default;

public:
    child();

    virtual ~child() noexcept { }

public:
    child(
        const unsigned int prop_0,
        const int prop_1);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_model::package_6::child& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_model::package_6::child& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    int prop_1() const;
    void prop_1(const int v);

public:
    bool operator==(const child& rhs) const;
    bool operator!=(const child& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const cpp_ref_impl::cpp_model::package_6::parent& other) const override;

public:
    void swap(child& other) noexcept;
    child& operator=(child other);

private:
    int prop_1_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::cpp_model::package_6::child& lhs,
    cpp_ref_impl::cpp_model::package_6::child& rhs) {
    lhs.swap(rhs);
}

}

#endif
