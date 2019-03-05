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
#include <algorithm>
#include <boost/test/unit_test.hpp>
#include <odb/result.hxx>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/pgsql/database.hxx>
#include <odb/schema-catalog.hxx>
#include "masd.cpp_ref_impl.utility/test/asserter.hpp"
#include "masd.cpp_ref_impl.utility/io/vector_io.hpp"
#include "masd.cpp_ref_impl.utility/test/logging.hpp"
#include "masd.cpp_ref_impl.northwind/types/all.hpp"
#include "masd.cpp_ref_impl.northwind/io/all_io.hpp"
#include "masd.cpp_ref_impl.northwind/test_data/all_td.hpp"
#include "masd.cpp_ref_impl.northwind/odb/customers-odb-pgsql.hxx"
#include "masd.cpp_ref_impl.northwind/odb/customers-odb.hxx"

namespace  {

const std::string test_module("northwind_tests");
const std::string test_suite("odb_pgsql_tests");

struct create_db_fixture {
    create_db_fixture() {
        using namespace odb;
        using odb::pgsql::database;
        auto db(std::make_unique<database>(
                "build", "build", "musseque", "localhost"));

        transaction t(db->begin());
        schema_catalog::create_schema(*db);
        t.commit();
    }
};
BOOST_GLOBAL_FIXTURE(create_db_fixture);

odb::pgsql::database* setup_postgres_db() {
    return new odb::pgsql::database("build", "build", "musseque", "localhost");
}

template<typename T>
unsigned long long delete_rows(odb::pgsql::database& db) {
    odb::transaction t(db.begin());
    const auto r(db.erase_query<T>());
    t.commit();
    return r;
}

template<typename Sequence>
std::vector<typename Sequence::result_type>
generate(const unsigned int how_many) {
    std::vector<typename Sequence::result_type> r;
    r.reserve(how_many);
    Sequence sequence;
    std::generate_n(std::back_inserter(r), how_many, sequence);
    return r;
}

template<typename T>
void persist(odb::pgsql::database& db, const std::vector<T>& v) {
    odb::transaction t(db.begin());
    for (const auto e : v)
        db.persist(e);
    t.commit();
}

template<typename T>
void update(odb::pgsql::database& db, const std::vector<T>& v) {
    odb::transaction t(db.begin());
    for (const auto e : v)
        db.update(e);
    t.commit();
}

}

BOOST_AUTO_TEST_SUITE(odb_pgsql_tests)

BOOST_AUTO_TEST_CASE(crud_test_customers_produces_expected_results) {
    SETUP_TEST_LOG_SOURCE("crud_test_customers_produces_expected_results");

    using namespace masd::cpp_ref_impl::northwind;
    std::unique_ptr<odb::pgsql::database> db_ptr(setup_postgres_db());
    auto& db(*db_ptr);
    auto del_rows(delete_rows<customers>(db));
    BOOST_LOG_SEV(lg, debug) << "Deleted existing rows. Total: " << del_rows;

    const unsigned int count(5);
    const auto original(generate<customers_generator>(count));
    BOOST_LOG_SEV(lg, debug) << "Original: " << original;

    persist(db, original);
    BOOST_LOG_SEV(lg, debug) << "Persisted original.";

    typedef odb::result<customers> result;
    {
        odb::transaction t(db.begin());
        result r(db.query<customers>());
        for (const auto& c : r) {
            BOOST_LOG_SEV(lg, debug) << "Actual: " << c;
            bool found(false);
            for (const auto e : original) {
                if (e == c) {
                    found = true;
                    BOOST_LOG_SEV(lg, debug) << "Found actual.";
                    continue;
                }
            }
            BOOST_CHECK(found);
        }
        t.commit();
    }

    {
        std::vector<customers> transformed;
        std::transform(original.begin(), original.end(),
            std::back_inserter(transformed), [](customers c) -> customers {
                c.country("Angola");
                return c;
            });
        BOOST_LOG_SEV(lg, debug) << "Transformed: " << transformed;
        update(db, transformed);
        BOOST_LOG_SEV(lg, debug) << "Updated database.";

        odb::transaction t(db.begin());
        result r(db.query<customers>());
        for (const auto& c : r) {
            BOOST_LOG_SEV(lg, debug) << "Actual: " << c;
            BOOST_CHECK(c.country() == "Angola");
        }
        t.commit();
    }

    del_rows = delete_rows<customers>(db);
    BOOST_CHECK(del_rows == count);
    BOOST_LOG_SEV(lg, debug) << "Deleted expected rows: " << count;
}

BOOST_AUTO_TEST_SUITE_END()
