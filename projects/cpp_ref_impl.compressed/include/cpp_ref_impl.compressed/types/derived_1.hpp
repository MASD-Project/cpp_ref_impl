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
#ifndef CPP_REF_IMPL_COMPRESSED_TYPES_DERIVED_1_HPP
#define CPP_REF_IMPL_COMPRESSED_TYPES_DERIVED_1_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "cpp_ref_impl.compressed/types/base.hpp"
#include "cpp_ref_impl.compressed/serialization/derived_1_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace compressed {

class derived_1 final : public cpp_ref_impl::compressed::base {
public:
    derived_1(const derived_1&) = default;
    derived_1(derived_1&&) = default;

public:
    derived_1();

    virtual ~derived_1() noexcept { }

public:
    derived_1(
        const int prop_0,
        const int prop_1);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::compressed::derived_1& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::compressed::derived_1& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    int prop_1() const;
    void prop_1(const int v);

public:
    bool operator==(const derived_1& rhs) const;
    bool operator!=(const derived_1& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const cpp_ref_impl::compressed::base& other) const override;

public:
    void swap(derived_1& other) noexcept;
    derived_1& operator=(derived_1 other);

private:
    int prop_1_;
};

} }

namespace std {

template<>
inline void swap(
    cpp_ref_impl::compressed::derived_1& lhs,
    cpp_ref_impl::compressed::derived_1& rhs) {
    lhs.swap(rhs);
}

}

#endif
