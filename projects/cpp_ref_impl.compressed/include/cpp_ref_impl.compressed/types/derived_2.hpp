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
#ifndef CPP_REF_IMPL_COMPRESSED_TYPES_DERIVED_2_HPP
#define CPP_REF_IMPL_COMPRESSED_TYPES_DERIVED_2_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "cpp_ref_impl.compressed/types/base.hpp"
#include "cpp_ref_impl.compressed/serialization/derived_2_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace compressed {

class derived_2 final : public cpp_ref_impl::compressed::base {
public:
    derived_2(const derived_2&) = default;
    derived_2(derived_2&&) = default;

public:
    derived_2();

    virtual ~derived_2() noexcept { }

public:
    derived_2(
        const int prop_0,
        const int prop_2);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::compressed::derived_2& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::compressed::derived_2& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    int prop_2() const;
    void prop_2(const int v);

public:
    bool operator==(const derived_2& rhs) const;
    bool operator!=(const derived_2& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const cpp_ref_impl::compressed::base& other) const override;

public:
    void swap(derived_2& other) noexcept;
    derived_2& operator=(derived_2 other);

private:
    int prop_2_;
};

} }

namespace std {

template<>
inline void swap(
    cpp_ref_impl::compressed::derived_2& lhs,
    cpp_ref_impl::compressed::derived_2& rhs) {
    lhs.swap(rhs);
}

}

#endif
