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
#include <ostream>
#include "masd.cpp_ref_impl.cpp_model/io/value_io.hpp"
#include "masd.cpp_ref_impl.cpp_model/io/simple_object_template_instance_io.hpp"

namespace masd::cpp_ref_impl::cpp_model {

std::ostream& operator<<(std::ostream& s, const simple_object_template_instance& v) {
    s << " { "
      << "\"__type__\": " << "\"masd::cpp_ref_impl::cpp_model::simple_object_template_instance\"" << ", "
      << "\"prop_0\": " << v.prop_0() << ", "
      << "\"prop_1\": " << v.prop_1() << ", "
      << "\"prop_10\": " << v.prop_10()
      << " }";
    return(s);
}

}
