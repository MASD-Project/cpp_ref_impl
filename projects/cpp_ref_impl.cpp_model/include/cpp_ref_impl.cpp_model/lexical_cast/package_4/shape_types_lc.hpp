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
#ifndef CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_PACKAGE_4_SHAPE_TYPES_LC_HPP
#define CPP_REF_IMPL_CPP_MODEL_LEXICAL_CAST_PACKAGE_4_SHAPE_TYPES_LC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/lexical_cast.hpp>
#include "cpp_ref_impl.cpp_model/types/package_4/shape_types.hpp"

namespace boost {

template<>
std::string lexical_cast(const cpp_ref_impl::cpp_model::package_4::shape_types& v) {
    using cpp_ref_impl::cpp_model::package_4::shape_types;

    switch (v) {
    case shape_types::invalid:
        return "shape_types::invalid";
    case shape_types::triangle:
        return "shape_types::triangle";
    case shape_types::square:
        return "shape_types::square";
    case shape_types::rectangle:
        return "shape_types::rectangle";
    case shape_types::circle:
        return "shape_types::circle";
    default:
        throw boost::bad_lexical_cast();
    }
}

template<>
cpp_ref_impl::cpp_model::package_4::shape_types lexical_cast(const std::string & s) {
    using cpp_ref_impl::cpp_model::package_4::shape_types;

    if (s == "invalid" || s == "shape_types::invalid")
        return shape_types::invalid;
    if (s == "triangle" || s == "shape_types::triangle")
        return shape_types::triangle;
    if (s == "square" || s == "shape_types::square")
        return shape_types::square;
    if (s == "rectangle" || s == "shape_types::rectangle")
        return shape_types::rectangle;
    if (s == "circle" || s == "shape_types::circle")
        return shape_types::circle;
    throw boost::bad_lexical_cast();
}

}

#endif
