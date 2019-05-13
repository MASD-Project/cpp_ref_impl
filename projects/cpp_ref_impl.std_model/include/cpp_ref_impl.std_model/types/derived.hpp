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
#ifndef CPP_REF_IMPL_STD_MODEL_TYPES_DERIVED_HPP
#define CPP_REF_IMPL_STD_MODEL_TYPES_DERIVED_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <list>
#include <iosfwd>
#include <algorithm>
#include "cpp_ref_impl.std_model/types/base.hpp"
#include "cpp_ref_impl.std_model/types/pkg1/class_c.hpp"
#include "cpp_ref_impl.std_model/serialization/derived_fwd_ser.hpp"

namespace cpp_ref_impl::std_model {

class derived final : public cpp_ref_impl::std_model::base {
public:
    derived() = default;
    derived(const derived&) = default;
    derived(derived&&) = default;

    virtual ~derived() noexcept { }

public:
    derived(
        const std::vector<std::string>& prop_0,
        const std::list<cpp_ref_impl::std_model::pkg1::class_c>& prop_1);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::std_model::derived& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::std_model::derived& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    const std::list<cpp_ref_impl::std_model::pkg1::class_c>& prop_1() const;
    std::list<cpp_ref_impl::std_model::pkg1::class_c>& prop_1();
    void prop_1(const std::list<cpp_ref_impl::std_model::pkg1::class_c>& v);
    void prop_1(const std::list<cpp_ref_impl::std_model::pkg1::class_c>&& v);

public:
    bool operator==(const derived& rhs) const;
    bool operator!=(const derived& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const cpp_ref_impl::std_model::base& other) const override;

public:
    void swap(derived& other) noexcept;
    derived& operator=(derived other);

private:
    std::list<cpp_ref_impl::std_model::pkg1::class_c> prop_1_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::std_model::derived& lhs,
    cpp_ref_impl::std_model::derived& rhs) {
    lhs.swap(rhs);
}

}

#endif
