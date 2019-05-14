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
#ifndef CPP_REF_IMPL_STD_MODEL_LEXICAL_CAST_ENUM_WITH_STD_BUILTIN_LC_HPP
#define CPP_REF_IMPL_STD_MODEL_LEXICAL_CAST_ENUM_WITH_STD_BUILTIN_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.std_model/types/enum_with_std_builtin.hpp"

namespace boost {

template<>
inline std::string lexical_cast(const cpp_ref_impl::std_model::enum_with_std_builtin& v) {
    using cpp_ref_impl::std_model::enum_with_std_builtin;

    switch (v) {
    case enum_with_std_builtin::invalid:
        return "enum_with_std_builtin::invalid";
    case enum_with_std_builtin::an_enumerator:
        return "enum_with_std_builtin::an_enumerator";
    case enum_with_std_builtin::another_enumerator:
        return "enum_with_std_builtin::another_enumerator";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
inline cpp_ref_impl::std_model::enum_with_std_builtin lexical_cast(const std::string & s) {
    using cpp_ref_impl::std_model::enum_with_std_builtin;

    if (s == "invalid" || s == "enum_with_std_builtin::invalid")
        return enum_with_std_builtin::invalid;
    if (s == "an_enumerator" || s == "enum_with_std_builtin::an_enumerator")
        return enum_with_std_builtin::an_enumerator;
    if (s == "another_enumerator" || s == "enum_with_std_builtin::another_enumerator")
        return enum_with_std_builtin::another_enumerator;
    throw boost::bad_lexical_cast();
}

}

#endif
