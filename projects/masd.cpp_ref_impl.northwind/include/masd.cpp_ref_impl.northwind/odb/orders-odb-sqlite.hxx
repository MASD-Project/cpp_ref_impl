// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDERS_ODB_SQLITE_HXX
#define MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDERS_ODB_SQLITE_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2045900 // 2.5.0-b.9
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/optional/wrapper-traits.hxx>
#include <odb/boost/unordered/container-traits.hxx>
#include <odb/boost/date-time/sqlite/gregorian-traits.hxx>
#include <odb/boost/date-time/sqlite/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/sqlite/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20459UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "masd.cpp_ref_impl.northwind/types/orders.hpp"

#include "masd.cpp_ref_impl.northwind/odb/customer_id-odb-sqlite.hxx"
#include "masd.cpp_ref_impl.northwind/odb/employee_id-odb-sqlite.hxx"
#include "masd.cpp_ref_impl.northwind/odb/order_id-odb-sqlite.hxx"

#include "masd.cpp_ref_impl.northwind/odb/orders-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // orders
  //
  template <typename A>
  struct query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >
  {
    // order_id
    //
    struct order_id_class_
    {
      order_id_class_ ()
      {
      }

      // value
      //
      typedef
      sqlite::query_column<
        sqlite::value_traits<
          int,
          sqlite::id_integer >::query_type,
        sqlite::id_integer >
      value_type_;

      static const value_type_ value;
    };

    static const order_id_class_ order_id;

    // customer_id
    //
    struct customer_id_class_
    {
      customer_id_class_ ()
      {
      }

      // value
      //
      typedef
      sqlite::query_column<
        sqlite::value_traits<
          int,
          sqlite::id_integer >::query_type,
        sqlite::id_integer >
      value_type_;

      static const value_type_ value;
    };

    static const customer_id_class_ customer_id;

    // employee_id
    //
    struct employee_id_class_
    {
      employee_id_class_ ()
      {
      }

      // value
      //
      typedef
      sqlite::query_column<
        sqlite::value_traits<
          int,
          sqlite::id_integer >::query_type,
        sqlite::id_integer >
      value_type_;

      static const value_type_ value;
    };

    static const employee_id_class_ employee_id;

    // order_date
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::boost::gregorian::date,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    order_date_type_;

    static const order_date_type_ order_date;

    // required_date
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::boost::gregorian::date,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    required_date_type_;

    static const required_date_type_ required_date;

    // shipped_date
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::boost::gregorian::date,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    shipped_date_type_;

    static const shipped_date_type_ shipped_date;

    // ship_via
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    ship_via_type_;

    static const ship_via_type_ ship_via;

    // freight
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    freight_type_;

    static const freight_type_ freight;

    // ship_name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_name_type_;

    static const ship_name_type_ ship_name;

    // ship_address
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_address_type_;

    static const ship_address_type_ ship_address;

    // ship_city
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_city_type_;

    static const ship_city_type_ ship_city;

    // ship_region
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_region_type_;

    static const ship_region_type_ ship_region;

    // ship_postal_code
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_postal_code_type_;

    static const ship_postal_code_type_ ship_postal_code;

    // ship_country
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    ship_country_type_;

    static const ship_country_type_ ship_country;
  };

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::order_id_class_::value_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::order_id_class_::
  value (A::table_name, "\"ORDER_ID\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::order_id_class_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::order_id;

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::customer_id_class_::value_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::customer_id_class_::
  value (A::table_name, "\"CUSTOMER_ID\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::customer_id_class_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::customer_id;

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::employee_id_class_::value_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::employee_id_class_::
  value (A::table_name, "\"EMPLOYEE_ID\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::employee_id_class_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::employee_id;

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::order_date_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  order_date (A::table_name, "\"ORDER_DATE\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::required_date_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  required_date (A::table_name, "\"REQUIRED_DATE\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::shipped_date_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  shipped_date (A::table_name, "\"SHIPPED_DATE\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_via_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_via (A::table_name, "\"SHIP_VIA\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::freight_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  freight (A::table_name, "\"FREIGHT\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_name_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_name (A::table_name, "\"SHIP_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_address_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_address (A::table_name, "\"SHIP_ADDRESS\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_city_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_city (A::table_name, "\"SHIP_CITY\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_region_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_region (A::table_name, "\"SHIP_REGION\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_postal_code_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_postal_code (A::table_name, "\"SHIP_POSTAL_CODE\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::ship_country_type_
  query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >::
  ship_country (A::table_name, "\"SHIP_COUNTRY\"", 0);

  template <typename A>
  struct pointer_query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >:
    query_columns< ::masd::cpp_ref_impl::northwind::orders, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::masd::cpp_ref_impl::northwind::orders, id_sqlite >:
    public access::object_traits< ::masd::cpp_ref_impl::northwind::orders >
  {
    public:
    struct id_image_type
    {
      composite_value_traits< ::masd::cpp_ref_impl::northwind::order_id, id_sqlite >::image_type id_value;

      std::size_t version;
    };

    struct image_type
    {
      // order_id_
      //
      composite_value_traits< ::masd::cpp_ref_impl::northwind::order_id, id_sqlite >::image_type order_id_value;

      // customer_id_
      //
      composite_value_traits< ::masd::cpp_ref_impl::northwind::customer_id, id_sqlite >::image_type customer_id_value;

      // employee_id_
      //
      composite_value_traits< ::masd::cpp_ref_impl::northwind::employee_id, id_sqlite >::image_type employee_id_value;

      // order_date_
      //
      details::buffer order_date_value;
      std::size_t order_date_size;
      bool order_date_null;

      // required_date_
      //
      details::buffer required_date_value;
      std::size_t required_date_size;
      bool required_date_null;

      // shipped_date_
      //
      details::buffer shipped_date_value;
      std::size_t shipped_date_size;
      bool shipped_date_null;

      // ship_via_
      //
      long long ship_via_value;
      bool ship_via_null;

      // freight_
      //
      double freight_value;
      bool freight_null;

      // ship_name_
      //
      details::buffer ship_name_value;
      std::size_t ship_name_size;
      bool ship_name_null;

      // ship_address_
      //
      details::buffer ship_address_value;
      std::size_t ship_address_size;
      bool ship_address_null;

      // ship_city_
      //
      details::buffer ship_city_value;
      std::size_t ship_city_size;
      bool ship_city_null;

      // ship_region_
      //
      details::buffer ship_region_value;
      std::size_t ship_region_size;
      bool ship_region_null;

      // ship_postal_code_
      //
      details::buffer ship_postal_code_value;
      std::size_t ship_postal_code_size;
      bool ship_postal_code_null;

      // ship_country_
      //
      details::buffer ship_country_value;
      std::size_t ship_country_size;
      bool ship_country_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static void
    bind (sqlite::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          sqlite::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef sqlite::object_statements<object_type> statements_type;

    typedef sqlite::query_base query_base_type;

    static const std::size_t column_count = 14UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  // orders
  //
}

#include "masd.cpp_ref_impl.northwind/odb/orders-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDERS_ODB_SQLITE_HXX
