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
#ifndef CPP_REF_IMPL_CPP_MODEL_SERIALIZATION_CHILD_VIA_SETTINGS_SER_HPP
#define CPP_REF_IMPL_CPP_MODEL_SERIALIZATION_CHILD_VIA_SETTINGS_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include <boost/type_traits/is_virtual_base_of.hpp>
#include "cpp_ref_impl.cpp_model/types/child_via_settings.hpp"

namespace boost {

template<>struct
is_virtual_base_of<
    cpp_ref_impl::cpp_model::parent_with_members,
    cpp_ref_impl::cpp_model::child_via_settings
> : public mpl::true_ {};

}

BOOST_SERIALIZATION_SPLIT_FREE(cpp_ref_impl::cpp_model::child_via_settings)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const cpp_ref_impl::cpp_model::child_via_settings& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, cpp_ref_impl::cpp_model::child_via_settings& v, unsigned int version);

} }

#endif
