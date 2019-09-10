// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_PGSQL_HXX
#define CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_PGSQL_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2046500 // 2.5.0-b.15
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/optional/wrapper-traits.hxx>
#include <odb/boost/unordered/container-traits.hxx>
#include <odb/boost/date-time/pgsql/gregorian-traits.hxx>
#include <odb/boost/date-time/pgsql/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/pgsql/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20465UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "cpp_ref_impl.northwind/types/customers.hpp"

#include "cpp_ref_impl.northwind/odb/customer_id-odb-pgsql.hxx"

#include "cpp_ref_impl.northwind/odb/customers-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/pgsql/version.hxx>
#include <odb/pgsql/forward.hxx>
#include <odb/pgsql/binding.hxx>
#include <odb/pgsql/pgsql-types.hxx>
#include <odb/pgsql/query.hxx>

namespace odb
{
  // customers
  //
  template <typename A>
  struct query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >
  {
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
      pgsql::query_column<
        pgsql::value_traits<
          int,
          pgsql::id_integer >::query_type,
        pgsql::id_integer >
      value_type_;

      static const value_type_ value;
    };

    static const customer_id_class_ customer_id;

    // customer_code
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    customer_code_type_;

    static const customer_code_type_ customer_code;

    // company_name
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    company_name_type_;

    static const company_name_type_ company_name;

    // contact_name
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    contact_name_type_;

    static const contact_name_type_ contact_name;

    // contact_title
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    contact_title_type_;

    static const contact_title_type_ contact_title;

    // address
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    address_type_;

    static const address_type_ address;

    // city
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    city_type_;

    static const city_type_ city;

    // region
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    region_type_;

    static const region_type_ region;

    // postal_code
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    postal_code_type_;

    static const postal_code_type_ postal_code;

    // country
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    country_type_;

    static const country_type_ country;

    // phone
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    phone_type_;

    static const phone_type_ phone;

    // fax
    //
    typedef
    pgsql::query_column<
      pgsql::value_traits<
        ::std::string,
        pgsql::id_string >::query_type,
      pgsql::id_string >
    fax_type_;

    static const fax_type_ fax;
  };

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::customer_id_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::customer_id_class_::
  value (A::table_name, "\"CUSTOMER_ID\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::customer_id_class_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::customer_id;

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::customer_code_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  customer_code (A::table_name, "\"CUSTOMER_CODE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::company_name_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  company_name (A::table_name, "\"COMPANY_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::contact_name_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  contact_name (A::table_name, "\"CONTACT_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::contact_title_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  contact_title (A::table_name, "\"CONTACT_TITLE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::address_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  address (A::table_name, "\"ADDRESS\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::city_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  city (A::table_name, "\"CITY\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::region_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  region (A::table_name, "\"REGION\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::postal_code_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  postal_code (A::table_name, "\"POSTAL_CODE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::country_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  country (A::table_name, "\"COUNTRY\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::phone_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  phone (A::table_name, "\"PHONE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::fax_type_
  query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >::
  fax (A::table_name, "\"FAX\"", 0);

  template <typename A>
  struct pointer_query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >:
    query_columns< ::cpp_ref_impl::northwind::customers, id_pgsql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::cpp_ref_impl::northwind::customers, id_pgsql >:
    public access::object_traits< ::cpp_ref_impl::northwind::customers >
  {
    public:
    struct id_image_type
    {
      composite_value_traits< ::cpp_ref_impl::northwind::customer_id, id_pgsql >::image_type id_value;

      std::size_t version;
    };

    struct image_type
    {
      // customer_id_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::customer_id, id_pgsql >::image_type customer_id_value;

      // customer_code_
      //
      details::buffer customer_code_value;
      std::size_t customer_code_size;
      bool customer_code_null;

      // company_name_
      //
      details::buffer company_name_value;
      std::size_t company_name_size;
      bool company_name_null;

      // contact_name_
      //
      details::buffer contact_name_value;
      std::size_t contact_name_size;
      bool contact_name_null;

      // contact_title_
      //
      details::buffer contact_title_value;
      std::size_t contact_title_size;
      bool contact_title_null;

      // address_
      //
      details::buffer address_value;
      std::size_t address_size;
      bool address_null;

      // city_
      //
      details::buffer city_value;
      std::size_t city_size;
      bool city_null;

      // region_
      //
      details::buffer region_value;
      std::size_t region_size;
      bool region_null;

      // postal_code_
      //
      details::buffer postal_code_value;
      std::size_t postal_code_size;
      bool postal_code_null;

      // country_
      //
      details::buffer country_value;
      std::size_t country_size;
      bool country_null;

      // phone_
      //
      details::buffer phone_value;
      std::size_t phone_size;
      bool phone_null;

      // fax_
      //
      details::buffer fax_value;
      std::size_t fax_size;
      bool fax_null;

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
    bind (pgsql::bind*,
          image_type&,
          pgsql::statement_kind);

    static void
    bind (pgsql::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          pgsql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef pgsql::object_statements<object_type> statements_type;

    typedef pgsql::query_base query_base_type;

    static const std::size_t column_count = 12UL;
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

    static const char persist_statement_name[];
    static const char find_statement_name[];
    static const char update_statement_name[];
    static const char erase_statement_name[];
    static const char query_statement_name[];
    static const char erase_query_statement_name[];

    static const unsigned int persist_statement_types[];
    static const unsigned int find_statement_types[];
    static const unsigned int update_statement_types[];

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  // customers
  //
}

#include "cpp_ref_impl.northwind/odb/customers-odb-pgsql.ixx"

#include <odb/post.hxx>

#endif // CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_PGSQL_HXX
