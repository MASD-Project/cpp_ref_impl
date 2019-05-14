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
#ifndef CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_HEX_FLAGS_LC_HPP
#define CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_HEX_FLAGS_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_model/types/hex_flags.hpp"

namespace boost {

template<>
inline std::string lexical_cast(const cpp_ref_impl::cpp_model::hex_flags& v) {
    using cpp_ref_impl::cpp_model::hex_flags;

    switch (v) {
    case hex_flags::none:
        return "hex_flags::none";
    case hex_flags::top:
        return "hex_flags::top";
    case hex_flags::bottom:
        return "hex_flags::bottom";
    case hex_flags::left:
        return "hex_flags::left";
    case hex_flags::right:
        return "hex_flags::right";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
inline cpp_ref_impl::cpp_model::hex_flags lexical_cast(const std::string & s) {
    using cpp_ref_impl::cpp_model::hex_flags;

    if (s == "none" || s == "hex_flags::none")
        return hex_flags::none;
    if (s == "top" || s == "hex_flags::top")
        return hex_flags::top;
    if (s == "bottom" || s == "hex_flags::bottom")
        return hex_flags::bottom;
    if (s == "left" || s == "hex_flags::left")
        return hex_flags::left;
    if (s == "right" || s == "hex_flags::right")
        return hex_flags::right;
    throw boost::bad_lexical_cast();
}

}

#endif
