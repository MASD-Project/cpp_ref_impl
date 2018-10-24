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
#ifndef MASD_CPP_REF_IMPL_NORTHWIND_TYPES_PRODUCTS_HPP
#define MASD_CPP_REF_IMPL_NORTHWIND_TYPES_PRODUCTS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <algorithm>
#include "masd.cpp_ref_impl.northwind/types/product_id.hpp"
#include "masd.cpp_ref_impl.northwind/types/category_id.hpp"
#include "masd.cpp_ref_impl.northwind/types/supplier_id.hpp"
#include "masd.cpp_ref_impl.northwind/serialization/products_fwd_ser.hpp"

namespace masd::cpp_ref_impl::northwind {

class products final {
public:
    products(const products&) = default;
    products(products&&) = default;
    ~products() = default;

public:
    products();

public:
    products(
        const masd::cpp_ref_impl::northwind::product_id& product_id,
        const std::string& product_name,
        const masd::cpp_ref_impl::northwind::supplier_id& supplier_id,
        const masd::cpp_ref_impl::northwind::category_id& category_id,
        const std::string& quantity_per_unit,
        const double unit_price,
        const int units_in_stock,
        const int units_in_order,
        const int reorder_level,
        const bool discontinued);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const masd::cpp_ref_impl::northwind::products& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, masd::cpp_ref_impl::northwind::products& v, unsigned int version);

public:
    const masd::cpp_ref_impl::northwind::product_id& product_id() const;
    masd::cpp_ref_impl::northwind::product_id& product_id();
    void product_id(const masd::cpp_ref_impl::northwind::product_id& v);
    void product_id(const masd::cpp_ref_impl::northwind::product_id&& v);

    const std::string& product_name() const;
    std::string& product_name();
    void product_name(const std::string& v);
    void product_name(const std::string&& v);

    const masd::cpp_ref_impl::northwind::supplier_id& supplier_id() const;
    masd::cpp_ref_impl::northwind::supplier_id& supplier_id();
    void supplier_id(const masd::cpp_ref_impl::northwind::supplier_id& v);
    void supplier_id(const masd::cpp_ref_impl::northwind::supplier_id&& v);

    const masd::cpp_ref_impl::northwind::category_id& category_id() const;
    masd::cpp_ref_impl::northwind::category_id& category_id();
    void category_id(const masd::cpp_ref_impl::northwind::category_id& v);
    void category_id(const masd::cpp_ref_impl::northwind::category_id&& v);

    const std::string& quantity_per_unit() const;
    std::string& quantity_per_unit();
    void quantity_per_unit(const std::string& v);
    void quantity_per_unit(const std::string&& v);

    double unit_price() const;
    void unit_price(const double v);

    int units_in_stock() const;
    void units_in_stock(const int v);

    int units_in_order() const;
    void units_in_order(const int v);

    int reorder_level() const;
    void reorder_level(const int v);

    bool discontinued() const;
    void discontinued(const bool v);

public:
    bool operator==(const products& rhs) const;
    bool operator!=(const products& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(products& other) noexcept;
    products& operator=(products other);

private:
    masd::cpp_ref_impl::northwind::product_id product_id_;
    std::string product_name_;
    masd::cpp_ref_impl::northwind::supplier_id supplier_id_;
    masd::cpp_ref_impl::northwind::category_id category_id_;
    std::string quantity_per_unit_;
    double unit_price_;
    int units_in_stock_;
    int units_in_order_;
    int reorder_level_;
    bool discontinued_;
};

}

namespace std {

template<>
inline void swap(
    masd::cpp_ref_impl::northwind::products& lhs,
    masd::cpp_ref_impl::northwind::products& rhs) {
    lhs.swap(rhs);
}

}

#endif
