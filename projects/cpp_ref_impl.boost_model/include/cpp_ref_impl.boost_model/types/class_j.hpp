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
#ifndef CPP_REF_IMPL_BOOST_MODEL_TYPES_CLASS_J_HPP
#define CPP_REF_IMPL_BOOST_MODEL_TYPES_CLASS_J_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl.boost_model/types/date_primitive.hpp"
#include "cpp_ref_impl.boost_model/types/ptime_primitive.hpp"
#include "cpp_ref_impl.boost_model/serialization/class_j_fwd_ser.hpp"
#include "cpp_ref_impl.boost_model/types/time_duration_primitive.hpp"

namespace cpp_ref_impl::boost_model {

class class_j final {
public:
    class_j() = default;
    class_j(const class_j&) = default;
    class_j(class_j&&) = default;
    ~class_j() = default;

public:
    class_j(
        const cpp_ref_impl::boost_model::ptime_primitive& prop_0,
        const cpp_ref_impl::boost_model::time_duration_primitive& prop_1,
        const cpp_ref_impl::boost_model::date_primitive& prop_2);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::boost_model::class_j& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::boost_model::class_j& v, unsigned int version);

public:
    const cpp_ref_impl::boost_model::ptime_primitive& prop_0() const;
    cpp_ref_impl::boost_model::ptime_primitive& prop_0();
    void prop_0(const cpp_ref_impl::boost_model::ptime_primitive& v);
    void prop_0(const cpp_ref_impl::boost_model::ptime_primitive&& v);

    const cpp_ref_impl::boost_model::time_duration_primitive& prop_1() const;
    cpp_ref_impl::boost_model::time_duration_primitive& prop_1();
    void prop_1(const cpp_ref_impl::boost_model::time_duration_primitive& v);
    void prop_1(const cpp_ref_impl::boost_model::time_duration_primitive&& v);

    const cpp_ref_impl::boost_model::date_primitive& prop_2() const;
    cpp_ref_impl::boost_model::date_primitive& prop_2();
    void prop_2(const cpp_ref_impl::boost_model::date_primitive& v);
    void prop_2(const cpp_ref_impl::boost_model::date_primitive&& v);

public:
    bool operator==(const class_j& rhs) const;
    bool operator!=(const class_j& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(class_j& other) noexcept;
    class_j& operator=(class_j other);

private:
    cpp_ref_impl::boost_model::ptime_primitive prop_0_;
    cpp_ref_impl::boost_model::time_duration_primitive prop_1_;
    cpp_ref_impl::boost_model::date_primitive prop_2_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::boost_model::class_j& lhs,
    cpp_ref_impl::boost_model::class_j& rhs) {
    lhs.swap(rhs);
}

}

#endif
