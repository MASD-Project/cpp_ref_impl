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
#ifndef MASD_CPP_REF_IMPL_DO_NOT_DELETE_EMPTY_DIRS_TYPES_DO_NOT_DELETE_EMPTY_DIRS_HPP
#define MASD_CPP_REF_IMPL_DO_NOT_DELETE_EMPTY_DIRS_TYPES_DO_NOT_DELETE_EMPTY_DIRS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

/**
 * @brief This model is designed to test that setting delete empty directory to
 * false does not delete directories.
 *
 * Because git does not version control empty directories, the model
 * requires some additional setup in order to be tested. You need to
 * generate this model into a folder, programmatically create some empty
 * directories and then check to see if they are deleted on generation.
 *
 * A similar test for the flag set to true can be done with any test
 * model as they all have it.
 */
namespace masd::cpp_ref_impl::do_not_delete_empty_dirs {
}

#endif
