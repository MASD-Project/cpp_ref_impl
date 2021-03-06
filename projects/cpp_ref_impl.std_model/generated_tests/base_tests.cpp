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
#include <boost/shared_ptr.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "cpp_ref_impl.std_model/io/base_io.hpp"
#include "cpp_ref_impl.std_model/types/base.hpp"
#include "cpp_ref_impl.std_model/hash/base_hash.hpp"
#include "cpp_ref_impl.std_model/test_data/base_td.hpp"
#include "cpp_ref_impl.std_model/serialization/base_ser.hpp"
#include "cpp_ref_impl.std_model/serialization/registrar_ser.hpp"

BOOST_AUTO_TEST_SUITE(base_tests)

BOOST_AUTO_TEST_CASE(inserter_operator_produces_valid_json) {
    cpp_ref_impl::std_model::base_generator g;
    const boost::shared_ptr<cpp_ref_impl::std_model::base> a(g.create_ptr(1));
    std::stringstream s;
    s << *a;

    boost::property_tree::ptree pt;
    BOOST_REQUIRE_NO_THROW(read_json(s, pt));
}

BOOST_AUTO_TEST_CASE(xml_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::std_model::base_generator g;
    const boost::shared_ptr<cpp_ref_impl::std_model::base> a(g.create_ptr(1));

    using namespace boost::archive;
    std::ostringstream os;
    {
        xml_oarchive oa(os);
        cpp_ref_impl::std_model::registrar::register_types<xml_oarchive>(oa);

        oa << BOOST_SERIALIZATION_NVP(a);
    }

    boost::shared_ptr<cpp_ref_impl::std_model::base> b;
    std::istringstream is(os.str());
    {
        xml_iarchive ia(is);
        cpp_ref_impl::std_model::registrar::register_types<xml_iarchive>(ia);
        ia >> BOOST_SERIALIZATION_NVP(b);
    }

    BOOST_REQUIRE(a);
    BOOST_REQUIRE(b);
    BOOST_CHECK(*a == *b);
}

BOOST_AUTO_TEST_CASE(text_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::std_model::base_generator g;
    const boost::shared_ptr<cpp_ref_impl::std_model::base> a(g.create_ptr(1));

    using namespace boost::archive;
    std::ostringstream os;
    {
        text_oarchive oa(os);
        cpp_ref_impl::std_model::registrar::register_types<text_oarchive>(oa);
        oa << a;
    }

    boost::shared_ptr<cpp_ref_impl::std_model::base> b;
    std::istringstream is(os.str());
    {
        text_iarchive ia(is);
        cpp_ref_impl::std_model::registrar::register_types<text_iarchive>(ia);
        ia >> b;
    }

    BOOST_REQUIRE(a);
    BOOST_REQUIRE(b);
    BOOST_CHECK(*a == *b);
}

BOOST_AUTO_TEST_CASE(binary_roundtrip_produces_the_same_entity) {
    cpp_ref_impl::std_model::base_generator g;
    const boost::shared_ptr<cpp_ref_impl::std_model::base> a(g.create_ptr(1));

    using namespace boost::archive;
    std::ostringstream os;
    {
        binary_oarchive oa(os);
        cpp_ref_impl::std_model::registrar::register_types<binary_oarchive>(oa);
        oa << a;
    }

    boost::shared_ptr<cpp_ref_impl::std_model::base> b;
    std::istringstream is(os.str());
    {
        binary_iarchive ia(is);
        cpp_ref_impl::std_model::registrar::register_types<binary_iarchive>(ia);
        ia >> b;
    }

    BOOST_REQUIRE(a);
    BOOST_REQUIRE(b);
    BOOST_CHECK(*a == *b);
}

BOOST_AUTO_TEST_SUITE_END()
