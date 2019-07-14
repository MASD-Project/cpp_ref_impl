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
#include "cpp_ref_impl.cpp_model/io/colour_types_io.hpp"
#include "cpp_ref_impl.cpp_model/types/colour_types.hpp"
#include "cpp_ref_impl.cpp_model/hash/colour_types_hash.hpp"
#include "cpp_ref_impl.cpp_model/test_data/colour_types_td.hpp"
#include "cpp_ref_impl.cpp_model/lexical_cast/colour_types_lc.hpp"
#include "cpp_ref_impl.cpp_model/serialization/colour_types_ser.hpp"

BOOST_AUTO_TEST_SUITE(colour_types_tests)

BOOST_AUTO_TEST_CASE(inserter_operator_produces_valid_json) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    const auto a(g());
    std::stringstream s;
    s << a;

    boost::property_tree::ptree pt;
    BOOST_REQUIRE_NO_THROW(read_json(s, pt));
}

BOOST_AUTO_TEST_CASE(casting_valid_strings_produces_expected_enumeration) {
    using cpp_ref_impl::cpp_model::colour_types;
    colour_types r;

    r = boost::lexical_cast<colour_types>(std::string("invalid"));
    BOOST_CHECK(r == colour_types::invalid);
    r = boost::lexical_cast<colour_types>(std::string("colour_types::invalid"));
    BOOST_CHECK(r == colour_types::invalid);

    r = boost::lexical_cast<colour_types>(std::string("red"));
    BOOST_CHECK(r == colour_types::red);
    r = boost::lexical_cast<colour_types>(std::string("colour_types::red"));
    BOOST_CHECK(r == colour_types::red);

    r = boost::lexical_cast<colour_types>(std::string("blue"));
    BOOST_CHECK(r == colour_types::blue);
    r = boost::lexical_cast<colour_types>(std::string("colour_types::blue"));
    BOOST_CHECK(r == colour_types::blue);

    r = boost::lexical_cast<colour_types>(std::string("green"));
    BOOST_CHECK(r == colour_types::green);
    r = boost::lexical_cast<colour_types>(std::string("colour_types::green"));
    BOOST_CHECK(r == colour_types::green);

    r = boost::lexical_cast<colour_types>(std::string("gray"));
    BOOST_CHECK(r == colour_types::gray);
    r = boost::lexical_cast<colour_types>(std::string("colour_types::gray"));
    BOOST_CHECK(r == colour_types::gray);
}

BOOST_AUTO_TEST_CASE(casting_invalid_string_throws) {
    using cpp_ref_impl::cpp_model::colour_types;
    BOOST_CHECK_THROW(boost::lexical_cast<colour_types>(std::string("DOGEN_THIS_IS_INVALID_DOGEN")),
        boost::bad_lexical_cast);
}

BOOST_AUTO_TEST_CASE(casting_valid_enumerations_produces_expected_strings) {
    using cpp_ref_impl::cpp_model::colour_types;
    std::string r;

    r = boost::lexical_cast<std::string>(colour_types::invalid);
    BOOST_CHECK(r == "colour_types::invalid");

    r = boost::lexical_cast<std::string>(colour_types::red);
    BOOST_CHECK(r == "colour_types::red");

    r = boost::lexical_cast<std::string>(colour_types::blue);
    BOOST_CHECK(r == "colour_types::blue");

    r = boost::lexical_cast<std::string>(colour_types::green);
    BOOST_CHECK(r == "colour_types::green");

    r = boost::lexical_cast<std::string>(colour_types::gray);
    BOOST_CHECK(r == "colour_types::gray");
}

BOOST_AUTO_TEST_CASE(casting_invalid_enumeration_throws) {
#if BOOST_COMP_GNUC
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wconversion"
#endif
    using cpp_ref_impl::cpp_model::colour_types;
    const colour_types r(static_cast<colour_types>(15));
#if BOOST_COMP_GNUC
#pragma GCC diagnostic pop
#endif
    BOOST_CHECK_THROW(boost::lexical_cast<std::string>(r),
        boost::bad_lexical_cast);
}

BOOST_AUTO_TEST_CASE(xml_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    cpp_ref_impl::cpp_model::colour_types b = cpp_ref_impl::cpp_model::colour_types();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(text_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        oa << BOOST_SERIALIZATION_NVP(a);
    }

    cpp_ref_impl::cpp_model::colour_types b = cpp_ref_impl::cpp_model::colour_types();
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(binary_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    const auto a(g());

    using namespace boost::archive;
    std::ostringstream os;
    {
        text_oarchive oa(os);
        oa << a;
    }

    cpp_ref_impl::cpp_model::colour_types b = cpp_ref_impl::cpp_model::colour_types();
    std::istringstream is(os.str());
    {
        text_iarchive ia(is);
        ia >> b;
    }
    BOOST_CHECK(a == b);
}

BOOST_AUTO_TEST_CASE(equal_enums_generate_the_same_hash) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    g();
    const auto a(g());
    const auto b(a);

    std::hash<cpp_ref_impl::cpp_model::colour_types> hasher;
    BOOST_CHECK(hasher(a) == hasher(b));
}

BOOST_AUTO_TEST_CASE(different_enums_generate_different_hashes) {
    cpp_ref_impl::cpp_model::colour_types_generator g;
    g();
    const auto a(g());
    const auto b(g());

    std::hash<cpp_ref_impl::cpp_model::colour_types> hasher;
    BOOST_CHECK(hasher(a) != hasher(b));
}

BOOST_AUTO_TEST_SUITE_END()
