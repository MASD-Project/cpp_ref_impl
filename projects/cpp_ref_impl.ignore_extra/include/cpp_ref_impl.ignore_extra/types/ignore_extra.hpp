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
#ifndef CPP_REF_IMPL_IGNORE_EXTRA_TYPES_IGNORE_EXTRA_HPP
#define CPP_REF_IMPL_IGNORE_EXTRA_TYPES_IGNORE_EXTRA_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

/**
 * @brief This model is designed to test extra files. These are named:
 *
 * - expected_ignore: files we do not want to delete.
 * - unexpected_remove: files we want to delete, but will ignore because
 *   delete extra files is set to false.
 */
namespace cpp_ref_impl::ignore_extra {
}

#endif
