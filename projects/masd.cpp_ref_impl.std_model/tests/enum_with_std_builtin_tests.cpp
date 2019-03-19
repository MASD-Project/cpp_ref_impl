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
#include <string>
#include <sstream>
#include <boost/test/unit_test.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "masd.cpp_ref_impl.std_model/io/enum_with_std_builtin_io.hpp"
#include "masd.cpp_ref_impl.std_model/types/enum_with_std_builtin.hpp"
#include "masd.cpp_ref_impl.std_model/hash/enum_with_std_builtin_hash.hpp"
#include "masd.cpp_ref_impl.std_model/test_data/enum_with_std_builtin_td.hpp"
#include "masd.cpp_ref_impl.std_model/serialization/enum_with_std_builtin_ser.hpp"

BOOST_AUTO_TEST_SUITE(enum_with_std_builtin_tests)

BOOST_AUTO_TEST_CASE(inserter_operator_produces_valid_json) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    const auto a(g());
    std::stringstream s;
    s << a;

    boost::property_tree::ptree pt;
    BOOST_REQUIRE_NO_THROW(read_json(s, pt));
}

BOOST_AUTO_TEST_CASE(xml_roundtrip_produces_the_same_entity) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    masd::cpp_ref_impl::std_model::enum_with_std_builtin b = masd::cpp_ref_impl::std_model::enum_with_std_builtin();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(text_roundtrip_produces_the_same_entity) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    masd::cpp_ref_impl::std_model::enum_with_std_builtin b = masd::cpp_ref_impl::std_model::enum_with_std_builtin();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(binary_roundtrip_produces_the_same_entity) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        text_oarchive oa(os);
        oa << a;
    }

    masd::cpp_ref_impl::std_model::enum_with_std_builtin b = masd::cpp_ref_impl::std_model::enum_with_std_builtin();
    std::istringstream is(os.str());
    {
        text_iarchive ia(is);
        ia >> b;
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(equal_enums_generate_the_same_hash) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    g();
    const auto a(g());
    const auto b(a);

    std::hash<masd::cpp_ref_impl::std_model::enum_with_std_builtin> hasher;
    BOOST_CHECK(hasher(a) == hasher(b));
}

BOOST_AUTO_TEST_CASE(different_enums_generate_different_hashes) {
    masd::cpp_ref_impl::std_model::enum_with_std_builtin_generator g;
    g();
    const auto a(g());
    const auto b(g());

    std::hash<masd::cpp_ref_impl::std_model::enum_with_std_builtin> hasher;
    BOOST_CHECK(hasher(a) != hasher(b));
}

BOOST_AUTO_TEST_SUITE_END()
