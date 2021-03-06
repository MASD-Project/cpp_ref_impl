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
#include "cpp_ref_impl.northwind/types/categories.hpp"

namespace cpp_ref_impl::northwind {

categories::categories(
    const cpp_ref_impl::northwind::category_id& category_id,
    const std::string& category_name,
    const std::string& description,
    const std::string& picture)
    : category_id_(category_id),
      category_name_(category_name),
      description_(description),
      picture_(picture) { }

void categories::swap(categories& other) noexcept {
    using std::swap;
    swap(category_id_, other.category_id_);
    swap(category_name_, other.category_name_);
    swap(description_, other.description_);
    swap(picture_, other.picture_);
}

bool categories::operator==(const categories& rhs) const {
    return category_id_ == rhs.category_id_ &&
        category_name_ == rhs.category_name_ &&
        description_ == rhs.description_ &&
        picture_ == rhs.picture_;
}

categories& categories::operator=(categories other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const cpp_ref_impl::northwind::category_id& categories::category_id() const {
    return category_id_;
}

cpp_ref_impl::northwind::category_id& categories::category_id() {
    return category_id_;
}

void categories::category_id(const cpp_ref_impl::northwind::category_id& v) {
    category_id_ = v;
}

void categories::category_id(const cpp_ref_impl::northwind::category_id&& v) {
    category_id_ = std::move(v);
}

const std::string& categories::category_name() const {
    return category_name_;
}

std::string& categories::category_name() {
    return category_name_;
}

void categories::category_name(const std::string& v) {
    category_name_ = v;
}

void categories::category_name(const std::string&& v) {
    category_name_ = std::move(v);
}

const std::string& categories::description() const {
    return description_;
}

std::string& categories::description() {
    return description_;
}

void categories::description(const std::string& v) {
    description_ = v;
}

void categories::description(const std::string&& v) {
    description_ = std::move(v);
}

const std::string& categories::picture() const {
    return picture_;
}

std::string& categories::picture() {
    return picture_;
}

void categories::picture(const std::string& v) {
    picture_ = v;
}

void categories::picture(const std::string&& v) {
    picture_ = std::move(v);
}

}
