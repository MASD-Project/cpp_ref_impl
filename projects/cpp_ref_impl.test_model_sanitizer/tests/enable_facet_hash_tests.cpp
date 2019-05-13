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
#include <boost/test/unit_test.hpp>
#include "cpp_ref_impl.utility/io/vector_io.hpp"
#include "cpp_ref_impl.utility/test/logging.hpp"
#include "cpp_ref_impl.utility/test/canned_tests.hpp"
#include "cpp_ref_impl.enable_facet_hash/types/all.hpp"

namespace {

const std::string empty;
const std::string test_module("cpp_ref_impl.test_model_sanitizer.tests");
const std::string test_suite("enable_facet_hash_tests");

class first_class_generator {
public:
    typedef cpp_ref_impl::enable_facet_hash::package1::first_class result_type;

public:
    result_type operator()() {
        result_type r;
        r.public_attribute(static_cast<int>(15 + pos_++));
        return r;
    }

private:
    unsigned int pos_ = 0;
};

}

namespace std {

template<>
class hash<cpp_ref_impl::enable_facet_hash::package1::first_class> {
public:
    size_t operator()(const cpp_ref_impl::enable_facet_hash::package1::first_class& v) const {
        return static_cast<size_t>(v.public_attribute());
    }
};

}

namespace cpp_ref_impl::enable_facet_hash::package1 {

std::ostream& operator<<(std::ostream& o, const first_class& v) {
    o << "outputting first class: " << v.public_attribute() << std::endl;
    return o;
}

}

using namespace cpp_ref_impl::enable_facet_hash;
using namespace cpp_ref_impl::enable_facet_hash::package1;
using namespace cpp_ref_impl::utility::test;

BOOST_AUTO_TEST_SUITE(enable_facet_hash_tests)

BOOST_AUTO_TEST_CASE(validate_equality) {
    SETUP_TEST_LOG("validate_equality");
    test_equality<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_hashing) {
    SETUP_TEST_LOG("validate_hashing");
    test_hashing<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_swap) {
    SETUP_TEST_LOG("validate_swap");
    test_swap<first_class_generator>();
}

BOOST_AUTO_TEST_CASE(validate_move_assignment_copy) {
    SETUP_TEST_LOG("validate_move_assignment_copy");
    test_move_assignment_copy<first_class_generator>();
}

BOOST_AUTO_TEST_SUITE_END()
