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
#include "cpp_ref_impl.compressed/types/base.hpp"
#include "cpp_ref_impl.compressed/types/consumer.hpp"

namespace boost {

inline bool operator==(const boost::shared_ptr<cpp_ref_impl::compressed::base>& lhs,
const boost::shared_ptr<cpp_ref_impl::compressed::base>& rhs) {
    return (!lhs && !rhs) ||(lhs && rhs && (*lhs == *rhs));
}

}

namespace cpp_ref_impl {
namespace compressed {

consumer::consumer(const boost::shared_ptr<cpp_ref_impl::compressed::base>& base_ptr)
    : base_ptr_(base_ptr) { }

void consumer::swap(consumer& other) noexcept {
    using std::swap;
    swap(base_ptr_, other.base_ptr_);
}

bool consumer::operator==(const consumer& rhs) const {
    return base_ptr_ == rhs.base_ptr_;
}

consumer& consumer::operator=(consumer other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

const boost::shared_ptr<cpp_ref_impl::compressed::base>& consumer::base_ptr() const {
    return base_ptr_;
}

boost::shared_ptr<cpp_ref_impl::compressed::base>& consumer::base_ptr() {
    return base_ptr_;
}

void consumer::base_ptr(const boost::shared_ptr<cpp_ref_impl::compressed::base>& v) {
    base_ptr_ = v;
}

void consumer::base_ptr(const boost::shared_ptr<cpp_ref_impl::compressed::base>&& v) {
    base_ptr_ = std::move(v);
}

} }
