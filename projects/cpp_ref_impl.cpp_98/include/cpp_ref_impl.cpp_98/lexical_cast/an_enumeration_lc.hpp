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
#ifndef CPP_REF_IMPL_CPP_98_LEXICAL_CAST_AN_ENUMERATION_LC_HPP
#define CPP_REF_IMPL_CPP_98_LEXICAL_CAST_AN_ENUMERATION_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_98/types/an_enumeration.hpp"

namespace boost {

template<>
std::string lexical_cast(const cpp_ref_impl::cpp_98::an_enumeration& v) {
    switch (v) {
    case cpp_ref_impl::cpp_98::invalid:
        return "an_enumeration::invalid";
    case cpp_ref_impl::cpp_98::first:
        return "an_enumeration::first";
    case cpp_ref_impl::cpp_98::second:
        return "an_enumeration::second";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
cpp_ref_impl::cpp_98::an_enumeration lexical_cast(const std::string & s) {
    if (s == "invalid" || s == "an_enumeration::invalid")
        return cpp_ref_impl::cpp_98::invalid;
    if (s == "first" || s == "an_enumeration::first")
        return cpp_ref_impl::cpp_98::first;
    if (s == "second" || s == "an_enumeration::second")
        return cpp_ref_impl::cpp_98::second;
    throw boost::bad_lexical_cast();
}

}

#endif
