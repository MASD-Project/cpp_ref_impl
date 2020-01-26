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
#ifndef CPP_REF_IMPL_OUT_OF_SYNC_TYPES_OUT_OF_SYNC_HPP
#define CPP_REF_IMPL_OUT_OF_SYNC_TYPES_OUT_OF_SYNC_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

/**
 * @brief This model is designed to be out of sync with the generated code. It
 * tests the behaviour of Dogen when faced with the following scenarios:
 *
 * - model elements that have not changed.
 * - model elements that have changed.
 * - files that are expected to be ignored.
 * - files that are unexpected.
 *
 * If you need to regenerate this model, you need to remove the attribute
 * changed_property in class changed_generated and delete the class
 * handcrafted_new.
 */
namespace cpp_ref_impl::out_of_sync {
}

#endif
