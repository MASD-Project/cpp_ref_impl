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
#ifndef CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_SHORT_ENUM_LC_HPP
#define CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_SHORT_ENUM_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_model/types/short_enum.hpp"

namespace boost {

template<>
std::string lexical_cast(const cpp_ref_impl::cpp_model::short_enum& v) {
    using cpp_ref_impl::cpp_model::short_enum;

    switch (v) {
    case short_enum::invalid:
        return "short_enum::invalid";
    case short_enum::an_enumerator:
        return "short_enum::an_enumerator";
    case short_enum::another_enumerator:
        return "short_enum::another_enumerator";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
cpp_ref_impl::cpp_model::short_enum lexical_cast(const std::string & s) {
    using cpp_ref_impl::cpp_model::short_enum;

    if (s == "invalid" || s == "short_enum::invalid")
        return short_enum::invalid;
    if (s == "an_enumerator" || s == "short_enum::an_enumerator")
        return short_enum::an_enumerator;
    if (s == "another_enumerator" || s == "short_enum::another_enumerator")
        return short_enum::another_enumerator;
    throw boost::bad_lexical_cast();
}

}

#endif
