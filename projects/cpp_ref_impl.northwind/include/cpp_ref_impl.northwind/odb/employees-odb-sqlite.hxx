// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CPP_REF_IMPL_NORTHWIND_ODB_EMPLOYEES_ODB_SQLITE_HXX
#define CPP_REF_IMPL_NORTHWIND_ODB_EMPLOYEES_ODB_SQLITE_HXX

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

#include "cpp_ref_impl.northwind/types/employees.hpp"

#include "cpp_ref_impl.northwind/odb/employee_id-odb-sqlite.hxx"

#include "cpp_ref_impl.northwind/odb/employees-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // employees
  //
  template <typename A>
  struct query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >
  {
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

    // last_name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    last_name_type_;

    static const last_name_type_ last_name;

    // first_name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    first_name_type_;

    static const first_name_type_ first_name;

    // title
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    title_type_;

    static const title_type_ title;

    // title_of_courtesy
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    title_of_courtesy_type_;

    static const title_of_courtesy_type_ title_of_courtesy;

    // birth_date
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::boost::gregorian::date,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    birth_date_type_;

    static const birth_date_type_ birth_date;

    // hire_date
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::boost::gregorian::date,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    hire_date_type_;

    static const hire_date_type_ hire_date;

    // address
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    address_type_;

    static const address_type_ address;

    // city
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    city_type_;

    static const city_type_ city;

    // region
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    region_type_;

    static const region_type_ region;

    // postal_code
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    postal_code_type_;

    static const postal_code_type_ postal_code;

    // country
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    country_type_;

    static const country_type_ country;

    // home_phone
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    home_phone_type_;

    static const home_phone_type_ home_phone;

    // extension
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    extension_type_;

    static const extension_type_ extension;

    // photo
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    photo_type_;

    static const photo_type_ photo;

    // notes
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    notes_type_;

    static const notes_type_ notes;

    // reports_to
    //
    struct reports_to_class_
    {
      reports_to_class_ ()
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

    static const reports_to_class_ reports_to;
  };

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::employee_id_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::employee_id_class_::
  value (A::table_name, "\"EMPLOYEE_ID\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::employee_id_class_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::employee_id;

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::last_name_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  last_name (A::table_name, "\"LASTNAME\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::first_name_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  first_name (A::table_name, "\"FIRSTNAME\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::title_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  title (A::table_name, "\"TITLE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::title_of_courtesy_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  title_of_courtesy (A::table_name, "\"TITLE_OF_COURTESY\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::birth_date_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  birth_date (A::table_name, "\"BIRTHDATE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::hire_date_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  hire_date (A::table_name, "\"HIREDATE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::address_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  address (A::table_name, "\"ADDRESS\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::city_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  city (A::table_name, "\"CITY\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::region_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  region (A::table_name, "\"REGION\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::postal_code_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  postal_code (A::table_name, "\"POSTAL_CODE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::country_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  country (A::table_name, "\"COUNTRY\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::home_phone_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  home_phone (A::table_name, "\"HOME_PHONE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::extension_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  extension (A::table_name, "\"EXTENSION\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::photo_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  photo (A::table_name, "\"PHOTO\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::notes_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::
  notes (A::table_name, "\"NOTES\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::reports_to_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::reports_to_class_::
  value (A::table_name, "\"REPORTS_TO\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::reports_to_class_
  query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >::reports_to;

  template <typename A>
  struct pointer_query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >:
    query_columns< ::cpp_ref_impl::northwind::employees, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::cpp_ref_impl::northwind::employees, id_sqlite >:
    public access::object_traits< ::cpp_ref_impl::northwind::employees >
  {
    public:
    struct id_image_type
    {
      composite_value_traits< ::cpp_ref_impl::northwind::employee_id, id_sqlite >::image_type id_value;

      std::size_t version;
    };

    struct image_type
    {
      // employee_id_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::employee_id, id_sqlite >::image_type employee_id_value;

      // last_name_
      //
      details::buffer last_name_value;
      std::size_t last_name_size;
      bool last_name_null;

      // first_name_
      //
      details::buffer first_name_value;
      std::size_t first_name_size;
      bool first_name_null;

      // title_
      //
      details::buffer title_value;
      std::size_t title_size;
      bool title_null;

      // title_of_courtesy_
      //
      details::buffer title_of_courtesy_value;
      std::size_t title_of_courtesy_size;
      bool title_of_courtesy_null;

      // birth_date_
      //
      details::buffer birth_date_value;
      std::size_t birth_date_size;
      bool birth_date_null;

      // hire_date_
      //
      details::buffer hire_date_value;
      std::size_t hire_date_size;
      bool hire_date_null;

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

      // home_phone_
      //
      details::buffer home_phone_value;
      std::size_t home_phone_size;
      bool home_phone_null;

      // extension_
      //
      details::buffer extension_value;
      std::size_t extension_size;
      bool extension_null;

      // photo_
      //
      details::buffer photo_value;
      std::size_t photo_size;
      bool photo_null;

      // notes_
      //
      details::buffer notes_value;
      std::size_t notes_size;
      bool notes_null;

      // reports_to_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::employee_id, id_sqlite >::image_type reports_to_value;

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

    static const std::size_t column_count = 17UL;
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

  // employees
  //
}

#include "cpp_ref_impl.northwind/odb/employees-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // CPP_REF_IMPL_NORTHWIND_ODB_EMPLOYEES_ODB_SQLITE_HXX