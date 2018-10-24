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
#ifndef MASD_CPP_REF_IMPL_STD_MODEL_TYPES_CLASS_B_HPP
#define MASD_CPP_REF_IMPL_STD_MODEL_TYPES_CLASS_B_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <vector>
#include <algorithm>
#include "masd.cpp_ref_impl.std_model/types/class_a.hpp"
#include "masd.cpp_ref_impl.std_model/types/pkg1/class_c.hpp"
#include "masd.cpp_ref_impl.std_model/serialization/class_b_fwd_ser.hpp"

namespace masd::cpp_ref_impl::std_model {

class class_b final {
public:
    class_b() = default;
    class_b(const class_b&) = default;
    class_b(class_b&&) = default;
    ~class_b() = default;

public:
    class_b(
        const std::vector<std::string>& prop_0,
        const std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_1,
        const std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c>& prop_2,
        const std::vector<unsigned int>& prop_3,
        const std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_4,
        const std::vector<std::vector<unsigned int> >& prop_5);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::std_model::class_b& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::std_model::class_b& v, unsigned int version);

public:
    const std::vector<std::string>& prop_0() const;
    std::vector<std::string>& prop_0();
    void prop_0(const std::vector<std::string>& v);
    void prop_0(const std::vector<std::string>&& v);

    const std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_1() const;
    std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_1();
    void prop_1(const std::vector<masd::cpp_ref_impl::std_model::class_a>& v);
    void prop_1(const std::vector<masd::cpp_ref_impl::std_model::class_a>&& v);

    const std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c>& prop_2() const;
    std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c>& prop_2();
    void prop_2(const std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c>& v);
    void prop_2(const std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c>&& v);

    const std::vector<unsigned int>& prop_3() const;
    std::vector<unsigned int>& prop_3();
    void prop_3(const std::vector<unsigned int>& v);
    void prop_3(const std::vector<unsigned int>&& v);

    const std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_4() const;
    std::vector<masd::cpp_ref_impl::std_model::class_a>& prop_4();
    void prop_4(const std::vector<masd::cpp_ref_impl::std_model::class_a>& v);
    void prop_4(const std::vector<masd::cpp_ref_impl::std_model::class_a>&& v);

    const std::vector<std::vector<unsigned int> >& prop_5() const;
    std::vector<std::vector<unsigned int> >& prop_5();
    void prop_5(const std::vector<std::vector<unsigned int> >& v);
    void prop_5(const std::vector<std::vector<unsigned int> >&& v);

public:
    bool operator==(const class_b& rhs) const;
    bool operator!=(const class_b& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(class_b& other) noexcept;
    class_b& operator=(class_b other);

private:
    std::vector<std::string> prop_0_;
    std::vector<masd::cpp_ref_impl::std_model::class_a> prop_1_;
    std::vector<masd::cpp_ref_impl::std_model::pkg1::class_c> prop_2_;
    std::vector<unsigned int> prop_3_;
    std::vector<masd::cpp_ref_impl::std_model::class_a> prop_4_;
    std::vector<std::vector<unsigned int> > prop_5_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::std_model::class_b& lhs,
    masd::cpp_ref_impl::std_model::class_b& rhs) {
    lhs.swap(rhs);
}

}

#endif
