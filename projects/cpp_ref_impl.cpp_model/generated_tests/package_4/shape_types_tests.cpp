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
#include <boost/predef.h>
#include <boost/lexical_cast.hpp>
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
#include "cpp_ref_impl.cpp_model/io/package_4/shape_types_io.hpp"
#include "cpp_ref_impl.cpp_model/types/package_4/shape_types.hpp"
#include "cpp_ref_impl.cpp_model/hash/package_4/shape_types_hash.hpp"
#include "cpp_ref_impl.cpp_model/test_data/package_4/shape_types_td.hpp"
#include "cpp_ref_impl.cpp_model/lexical_cast/package_4/shape_types_lc.hpp"
#include "cpp_ref_impl.cpp_model/serialization/package_4/shape_types_ser.hpp"

BOOST_AUTO_TEST_SUITE(shape_types_tests)

BOOST_AUTO_TEST_CASE(inserter_operator_produces_valid_json) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    const auto a(g());
    std::stringstream s;
    s << a;

    boost::property_tree::ptree pt;
    BOOST_REQUIRE_NO_THROW(read_json(s, pt));
}

BOOST_AUTO_TEST_CASE(casting_valid_strings_produces_expected_enumeration) {
    using cpp_ref_impl::cpp_model::package_4::shape_types;
    shape_types r;

    r = boost::lexical_cast<shape_types>(std::string("invalid"));
    BOOST_CHECK(r == shape_types::invalid);
    r = boost::lexical_cast<shape_types>(std::string("shape_types::invalid"));
    BOOST_CHECK(r == shape_types::invalid);

    r = boost::lexical_cast<shape_types>(std::string("triangle"));
    BOOST_CHECK(r == shape_types::triangle);
    r = boost::lexical_cast<shape_types>(std::string("shape_types::triangle"));
    BOOST_CHECK(r == shape_types::triangle);

    r = boost::lexical_cast<shape_types>(std::string("square"));
    BOOST_CHECK(r == shape_types::square);
    r = boost::lexical_cast<shape_types>(std::string("shape_types::square"));
    BOOST_CHECK(r == shape_types::square);

    r = boost::lexical_cast<shape_types>(std::string("rectangle"));
    BOOST_CHECK(r == shape_types::rectangle);
    r = boost::lexical_cast<shape_types>(std::string("shape_types::rectangle"));
    BOOST_CHECK(r == shape_types::rectangle);

    r = boost::lexical_cast<shape_types>(std::string("circle"));
    BOOST_CHECK(r == shape_types::circle);
    r = boost::lexical_cast<shape_types>(std::string("shape_types::circle"));
    BOOST_CHECK(r == shape_types::circle);
}

BOOST_AUTO_TEST_CASE(casting_invalid_string_throws) {
    using cpp_ref_impl::cpp_model::package_4::shape_types;
    BOOST_CHECK_THROW(boost::lexical_cast<shape_types>(std::string("DOGEN_THIS_IS_INVALID_DOGEN")),
        boost::bad_lexical_cast);
}

BOOST_AUTO_TEST_CASE(casting_valid_enumerations_produces_expected_strings) {
    using cpp_ref_impl::cpp_model::package_4::shape_types;
    std::string r;

    r = boost::lexical_cast<std::string>(shape_types::invalid);
    BOOST_CHECK(r == "shape_types::invalid");

    r = boost::lexical_cast<std::string>(shape_types::triangle);
    BOOST_CHECK(r == "shape_types::triangle");

    r = boost::lexical_cast<std::string>(shape_types::square);
    BOOST_CHECK(r == "shape_types::square");

    r = boost::lexical_cast<std::string>(shape_types::rectangle);
    BOOST_CHECK(r == "shape_types::rectangle");

    r = boost::lexical_cast<std::string>(shape_types::circle);
    BOOST_CHECK(r == "shape_types::circle");
}

BOOST_AUTO_TEST_CASE(casting_invalid_enumeration_throws) {
#if BOOST_COMP_GNUC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    using cpp_ref_impl::cpp_model::package_4::shape_types;
    const shape_types r(static_cast<shape_types>(15));
#if BOOST_COMP_GNUC
#pragma GCC diagnostic pop
#endif
    BOOST_CHECK_THROW(boost::lexical_cast<std::string>(r),
        boost::bad_lexical_cast);
}

BOOST_AUTO_TEST_CASE(xml_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    cpp_ref_impl::cpp_model::package_4::shape_types b = cpp_ref_impl::cpp_model::package_4::shape_types();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(text_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    cpp_ref_impl::cpp_model::package_4::shape_types b = cpp_ref_impl::cpp_model::package_4::shape_types();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(binary_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        text_oarchive oa(os);
        oa << a;
    }

    cpp_ref_impl::cpp_model::package_4::shape_types b = cpp_ref_impl::cpp_model::package_4::shape_types();
    std::istringstream is(os.str());
    {
        text_iarchive ia(is);
        ia >> b;
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(equal_enums_generate_the_same_hash) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    g();
    const auto a(g());
    const auto b(a);

    std::hash<cpp_ref_impl::cpp_model::package_4::shape_types> hasher;
    BOOST_CHECK(hasher(a) == hasher(b));
}

BOOST_AUTO_TEST_CASE(different_enums_generate_different_hashes) {
    cpp_ref_impl::cpp_model::package_4::shape_types_generator g;
    g();
    const auto a(g());
    const auto b(g());

    std::hash<cpp_ref_impl::cpp_model::package_4::shape_types> hasher;
    BOOST_CHECK(hasher(a) != hasher(b));
}

BOOST_AUTO_TEST_SUITE_END()