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
#include "masd.cpp_ref_impl.std_model/types/class_d.hpp"

namespace masd::cpp_ref_impl::std_model {

class_d::class_d(
    const std::list<std::string>& prop_0,
    const std::list<masd::cpp_ref_impl::std_model::class_a>& prop_1,
    const std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>& prop_2,
    const std::list<unsigned int>& prop_3,
    const std::list<masd::cpp_ref_impl::std_model::class_a>& prop_4,
    const std::list<std::list<unsigned int> >& prop_5)
    : prop_0_(prop_0),
      prop_1_(prop_1),
      prop_2_(prop_2),
      prop_3_(prop_3),
      prop_4_(prop_4),
      prop_5_(prop_5) { }

void class_d::swap(class_d& other) noexcept {
    using std::swap;
    swap(prop_0_, other.prop_0_);
    swap(prop_1_, other.prop_1_);
    swap(prop_2_, other.prop_2_);
    swap(prop_3_, other.prop_3_);
    swap(prop_4_, other.prop_4_);
    swap(prop_5_, other.prop_5_);
}

bool class_d::operator==(const class_d& rhs) const {
    return prop_0_ == rhs.prop_0_ &&
        prop_1_ == rhs.prop_1_ &&
        prop_2_ == rhs.prop_2_ &&
        prop_3_ == rhs.prop_3_ &&
        prop_4_ == rhs.prop_4_ &&
        prop_5_ == rhs.prop_5_;
}

class_d& class_d::operator=(class_d other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const std::list<std::string>& class_d::prop_0() const {
    return prop_0_;
}

std::list<std::string>& class_d::prop_0() {
    return prop_0_;
}

void class_d::prop_0(const std::list<std::string>& v) {
    prop_0_ = v;
}

void class_d::prop_0(const std::list<std::string>&& v) {
    prop_0_ = std::move(v);
}

const std::list<masd::cpp_ref_impl::std_model::class_a>& class_d::prop_1() const {
    return prop_1_;
}

std::list<masd::cpp_ref_impl::std_model::class_a>& class_d::prop_1() {
    return prop_1_;
}

void class_d::prop_1(const std::list<masd::cpp_ref_impl::std_model::class_a>& v) {
    prop_1_ = v;
}

void class_d::prop_1(const std::list<masd::cpp_ref_impl::std_model::class_a>&& v) {
    prop_1_ = std::move(v);
}

const std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>& class_d::prop_2() const {
    return prop_2_;
}

std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>& class_d::prop_2() {
    return prop_2_;
}

void class_d::prop_2(const std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>& v) {
    prop_2_ = v;
}

void class_d::prop_2(const std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>&& v) {
    prop_2_ = std::move(v);
}

const std::list<unsigned int>& class_d::prop_3() const {
    return prop_3_;
}

std::list<unsigned int>& class_d::prop_3() {
    return prop_3_;
}

void class_d::prop_3(const std::list<unsigned int>& v) {
    prop_3_ = v;
}

void class_d::prop_3(const std::list<unsigned int>&& v) {
    prop_3_ = std::move(v);
}

const std::list<masd::cpp_ref_impl::std_model::class_a>& class_d::prop_4() const {
    return prop_4_;
}

std::list<masd::cpp_ref_impl::std_model::class_a>& class_d::prop_4() {
    return prop_4_;
}

void class_d::prop_4(const std::list<masd::cpp_ref_impl::std_model::class_a>& v) {
    prop_4_ = v;
}

void class_d::prop_4(const std::list<masd::cpp_ref_impl::std_model::class_a>&& v) {
    prop_4_ = std::move(v);
}

const std::list<std::list<unsigned int> >& class_d::prop_5() const {
    return prop_5_;
}

std::list<std::list<unsigned int> >& class_d::prop_5() {
    return prop_5_;
}

void class_d::prop_5(const std::list<std::list<unsigned int> >& v) {
    prop_5_ = v;
}

void class_d::prop_5(const std::list<std::list<unsigned int> >&& v) {
    prop_5_ = std::move(v);
}

}