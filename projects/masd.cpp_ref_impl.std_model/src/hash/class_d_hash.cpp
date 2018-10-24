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
#include "masd.cpp_ref_impl.std_model/hash/class_a_hash.hpp"
#include "masd.cpp_ref_impl.std_model/hash/class_d_hash.hpp"
#include "masd.cpp_ref_impl.std_model/hash/pkg1/class_c_hash.hpp"

namespace {

template <typename HashableType>
inline void combine(std::size_t& seed, const HashableType& value) {
    std::hash<HashableType> hasher;
    seed ^= hasher(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

inline std::size_t hash_std_list_std_string(const std::list<std::string>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_list_masd_cpp_ref_impl_std_model_class_a(const std::list<masd::cpp_ref_impl::std_model::class_a>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_list_masd_cpp_ref_impl_std_model_pkg1_class_c(const std::list<masd::cpp_ref_impl::std_model::pkg1::class_c>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_list_unsigned_int(const std::list<unsigned int>& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, i);
    }
    return seed;
}

inline std::size_t hash_std_list_std_list_unsigned_int(const std::list<std::list<unsigned int> >& v) {
    std::size_t seed(0);
    for (const auto i : v) {
        combine(seed, hash_std_list_unsigned_int(i));
    }
    return seed;
}

}

namespace masd::cpp_ref_impl::std_model {

std::size_t class_d_hasher::hash(const class_d& v) {
    std::size_t seed(0);

    combine(seed, hash_std_list_std_string(v.prop_0()));
    combine(seed, hash_std_list_masd_cpp_ref_impl_std_model_class_a(v.prop_1()));
    combine(seed, hash_std_list_masd_cpp_ref_impl_std_model_pkg1_class_c(v.prop_2()));
    combine(seed, hash_std_list_unsigned_int(v.prop_3()));
    combine(seed, hash_std_list_masd_cpp_ref_impl_std_model_class_a(v.prop_4()));
    combine(seed, hash_std_list_std_list_unsigned_int(v.prop_5()));

    return seed;
}

}
