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
#include "cpp_ref_impl.compressed/test_data/base_td.hpp"
#include "cpp_ref_impl.compressed/test_data/consumer_td.hpp"

namespace {

cpp_ref_impl::compressed::base*
create_cpp_ref_impl_compressed_base_ptr(const unsigned int position) {
    return cpp_ref_impl::compressed::base_generator::create_ptr(position);
}

boost::shared_ptr<cpp_ref_impl::compressed::base>
create_boost_shared_ptr_cpp_ref_impl_compressed_base(unsigned int position) {
    boost::shared_ptr<cpp_ref_impl::compressed::base> r(
        create_cpp_ref_impl_compressed_base_ptr(position));
    return r;
}

}

namespace cpp_ref_impl {
namespace compressed {

consumer_generator::consumer_generator() : position_(0) { }

void consumer_generator::
populate(const unsigned int position, result_type& v) {
    v.base_ptr(create_boost_shared_ptr_cpp_ref_impl_compressed_base(position + 0));
}

consumer_generator::result_type
consumer_generator::create(const unsigned int position) {
    consumer r;
    consumer_generator::populate(position, r);
    return r;
}

consumer_generator::result_type*
consumer_generator::create_ptr(const unsigned int position) {
    consumer* p = new consumer();
    consumer_generator::populate(position, *p);
    return p;
}

consumer_generator::result_type
consumer_generator::operator()() {
    return create(position_++);
}

} }
