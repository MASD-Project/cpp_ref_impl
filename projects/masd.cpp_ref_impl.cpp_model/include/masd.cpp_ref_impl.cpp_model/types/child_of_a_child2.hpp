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
#ifndef MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_CHILD_OF_A_CHILD2_HPP
#define MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_CHILD_OF_A_CHILD2_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "masd.cpp_ref_impl.cpp_model/types/third_child_with_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/serialization/child_of_a_child2_fwd_ser.hpp"

namespace masd::cpp_ref_impl::cpp_model {

class child_of_a_child2 final : public masd::cpp_ref_impl::cpp_model::third_child_with_members {
public:
    child_of_a_child2(const child_of_a_child2&) = default;
    child_of_a_child2(child_of_a_child2&&) = default;

public:
    child_of_a_child2();

    virtual ~child_of_a_child2() noexcept { }

public:
    child_of_a_child2(
        const int prop_0,
        const unsigned int prop_1,
        const unsigned int prop_2);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::cpp_model::child_of_a_child2& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::cpp_model::child_of_a_child2& v, unsigned int version);

public:
    void to_stream(std::ostream& s) const override;

public:
    unsigned int prop_2() const;
    void prop_2(const unsigned int v);

public:
    bool operator==(const child_of_a_child2& rhs) const;
    bool operator!=(const child_of_a_child2& rhs) const {
        return !this->operator==(rhs);
    }

public:
    bool equals(const masd::cpp_ref_impl::cpp_model::parent_with_members& other) const override;

public:
    void swap(child_of_a_child2& other) noexcept;
    child_of_a_child2& operator=(child_of_a_child2 other);

private:
    unsigned int prop_2_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::cpp_model::child_of_a_child2& lhs,
    masd::cpp_ref_impl::cpp_model::child_of_a_child2& rhs) {
    lhs.swap(rhs);
}

}

#endif
