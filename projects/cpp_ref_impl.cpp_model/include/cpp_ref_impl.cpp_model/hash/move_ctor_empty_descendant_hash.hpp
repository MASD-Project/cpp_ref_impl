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
#ifndef CPP_REF_IMPL_CPP_MODEL_HASH_MOVE_CTOR_EMPTY_DESCENDANT_HASH_HPP
#define CPP_REF_IMPL_CPP_MODEL_HASH_MOVE_CTOR_EMPTY_DESCENDANT_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "cpp_ref_impl.cpp_model/types/move_ctor_empty_descendant.hpp"

namespace cpp_ref_impl::cpp_model {

struct move_ctor_empty_descendant_hasher {
public:
    static std::size_t hash(const move_ctor_empty_descendant& v);
};

}

namespace std {

template<>
struct hash<cpp_ref_impl::cpp_model::move_ctor_empty_descendant> {
public:
    size_t operator()(const cpp_ref_impl::cpp_model::move_ctor_empty_descendant& v) const {
        return cpp_ref_impl::cpp_model::move_ctor_empty_descendant_hasher::hash(v);
    }
};

}
#endif
