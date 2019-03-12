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
#ifndef MASD_CPP_REF_IMPL_CPP_98_TYPES_NO_DEFAULT_CTOR_HPP
#define MASD_CPP_REF_IMPL_CPP_98_TYPES_NO_DEFAULT_CTOR_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include "masd.cpp_ref_impl.cpp_98/serialization/no_default_ctor_fwd_ser.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

/**
 * @brief This class does not require a default constructor due to using simple types.
 */
class no_default_ctor {
public:
    no_default_ctor();

public:
    explicit no_default_ctor(const std::string& prop_0);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::cpp_98::no_default_ctor& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::cpp_98::no_default_ctor& v, unsigned int version);

public:
    const std::string& prop_0() const;
    std::string& prop_0();
    void prop_0(const std::string& v);

public:
    bool operator==(const no_default_ctor& rhs) const;
    bool operator!=(const no_default_ctor& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(no_default_ctor& other);
    no_default_ctor& operator=(no_default_ctor other);

private:
    std::string prop_0_;
};

} } }

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::cpp_98::no_default_ctor& lhs,
    masd::cpp_ref_impl::cpp_98::no_default_ctor& rhs) {
    lhs.swap(rhs);
}

}

#endif
