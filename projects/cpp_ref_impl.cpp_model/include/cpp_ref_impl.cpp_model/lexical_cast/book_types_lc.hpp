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
#ifndef CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_BOOK_TYPES_LC_HPP
#define CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_BOOK_TYPES_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_model/types/book_types.hpp"

namespace boost {

template<>
std::string lexical_cast(const cpp_ref_impl::cpp_model::book_types& v) {
    using cpp_ref_impl::cpp_model::book_types;

    switch (v) {
    case book_types::invalid:
        return "book_types::invalid";
    case book_types::great:
        return "book_types::great";
    case book_types::not_so_great:
        return "book_types::not_so_great";
    case book_types::bad:
        return "book_types::bad";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
cpp_ref_impl::cpp_model::book_types lexical_cast(const std::string & s) {
    using cpp_ref_impl::cpp_model::book_types;

    if (s == "invalid" || s == "book_types::invalid")
        return book_types::invalid;
    if (s == "great" || s == "book_types::great")
        return book_types::great;
    if (s == "not_so_great" || s == "book_types::not_so_great")
        return book_types::not_so_great;
    if (s == "bad" || s == "book_types::bad")
        return book_types::bad;
    throw boost::bad_lexical_cast();
}

}

#endif
