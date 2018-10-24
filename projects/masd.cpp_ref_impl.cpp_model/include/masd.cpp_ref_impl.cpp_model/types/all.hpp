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
#ifndef MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_ALL_HPP
#define MASD_CPP_REF_IMPL_CPP_MODEL_TYPES_ALL_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "masd.cpp_ref_impl.cpp_model/types/base.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/value.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/fluent.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/a_class.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_0.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_a.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_b.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_c.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/class_d.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/service.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/builtins.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/consumer.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/my_error.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/one_line.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/a_service.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/hex_flags.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/some_type.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/book_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/multi_line.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/short_enum.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/descendant1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/descendant2.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/descendant3.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/base_visitor.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/colour_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_two.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/int_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/bool_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/char_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_four.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_zero.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/long_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/move_ctor_base.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/non_final_leaf.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/parent_outside.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/test_all_knobs.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/uint_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/float_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_6/child.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_8/child.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_9/child.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/short_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/uchar_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/ulong_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/double_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/non_final_orphan.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_6/parent.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_7/parent.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/ushort_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/child_of_a_child1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/child_of_a_child2.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/further_inherited.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_1/class_1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_1/class_2.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_1/class_3.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_1/class_4.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_1/class_5.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_2/class_1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_2/class_2.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/service_interface.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/child_via_settings.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/child_with_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_primitive.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_3/package_3.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/parent_with_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/move_ctor_descendant.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/child_without_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_one_builtin.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_4/shape_types.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/parent_without_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/third_child_with_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/base_with_object_template.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/immutable_one_non_builtin.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/move_ctor_empty_descendant.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_5/catastrophic_error.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_6/child_via_settings.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_8/child_via_settings.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_9/child_via_settings.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/second_child_without_members.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/base_object_template_instance.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_3/package_1/package_1.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/multi_object_template_instance.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/simple_object_template_instance.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/package_10/consume_object_template.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/descendant_object_template_instance.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/multiple_parents_object_template_instance.hpp"
#include "masd.cpp_ref_impl.cpp_model/types/second_descendant_object_template_instance.hpp"

#endif
