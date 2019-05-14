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
#ifndef CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_COLOUR_TYPES_LC_HPP
#define CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_COLOUR_TYPES_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_model/types/colour_types.hpp"

namespace boost {

template<>
std::string lexical_cast(const cpp_ref_impl::cpp_model::colour_types& v) {
    using cpp_ref_impl::cpp_model::colour_types;

    switch (v) {
    case colour_types::invalid:
        return "colour_types::invalid";
    case colour_types::red:
        return "colour_types::red";
    case colour_types::blue:
        return "colour_types::blue";
    case colour_types::green:
        return "colour_types::green";
    case colour_types::gray:
        return "colour_types::gray";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
cpp_ref_impl::cpp_model::colour_types lexical_cast(const std::string & s) {
    using cpp_ref_impl::cpp_model::colour_types;

    if (s == "invalid" || s == "colour_types::invalid")
        return colour_types::invalid;
    if (s == "red" || s == "colour_types::red")
        return colour_types::red;
    if (s == "blue" || s == "colour_types::blue")
        return colour_types::blue;
    if (s == "green" || s == "colour_types::green")
        return colour_types::green;
    if (s == "gray" || s == "colour_types::gray")
        return colour_types::gray;
    throw boost::bad_lexical_cast();
}

}

#endif
