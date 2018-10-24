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
#ifndef MASD_CPP_REF_IMPL_NORTHWIND_TYPES_CATEGORIES_HPP
#define MASD_CPP_REF_IMPL_NORTHWIND_TYPES_CATEGORIES_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include "masd.cpp_ref_impl.northwind/types/category_id.hpp"
#include "masd.cpp_ref_impl.northwind/serialization/categories_fwd_ser.hpp"

namespace masd::cpp_ref_impl::northwind {

class categories final {
public:
    categories() = default;
    categories(const categories&) = default;
    categories(categories&&) = default;
    ~categories() = default;

public:
    categories(
        const masd::cpp_ref_impl::northwind::category_id& category_id,
        const std::string& category_name,
        const std::string& description,
        const std::string& picutre);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::northwind::categories& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::northwind::categories& v, unsigned int version);

public:
    const masd::cpp_ref_impl::northwind::category_id& category_id() const;
    masd::cpp_ref_impl::northwind::category_id& category_id();
    void category_id(const masd::cpp_ref_impl::northwind::category_id& v);
    void category_id(const masd::cpp_ref_impl::northwind::category_id&& v);

    const std::string& category_name() const;
    std::string& category_name();
    void category_name(const std::string& v);
    void category_name(const std::string&& v);

    const std::string& description() const;
    std::string& description();
    void description(const std::string& v);
    void description(const std::string&& v);

    const std::string& picutre() const;
    std::string& picutre();
    void picutre(const std::string& v);
    void picutre(const std::string&& v);

public:
    bool operator==(const categories& rhs) const;
    bool operator!=(const categories& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(categories& other) noexcept;
    categories& operator=(categories other);

private:
    masd::cpp_ref_impl::northwind::category_id category_id_;
    std::string category_name_;
    std::string description_;
    std::string picutre_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::northwind::categories& lhs,
    masd::cpp_ref_impl::northwind::categories& rhs) {
    lhs.swap(rhs);
}

}

#endif
