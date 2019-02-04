// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef MASD_CPP_REF_IMPL_NORTHWIND_ODB_SHIPPERS_ODB_SQLITE_HXX
#define MASD_CPP_REF_IMPL_NORTHWIND_ODB_SHIPPERS_ODB_SQLITE_HXX

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

#include "masd.cpp_ref_impl.northwind/types/shippers.hpp"

#include "masd.cpp_ref_impl.northwind/odb/shipper_id-odb-sqlite.hxx"

#include "masd.cpp_ref_impl.northwind/odb/shippers-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // shippers
  //
  template <typename A>
  struct query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >
  {
    // shipper_id
    //
    struct shipper_id_class_
    {
      shipper_id_class_ ()
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

    static const shipper_id_class_ shipper_id;

    // company_name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    company_name_type_;

    static const company_name_type_ company_name;

    // phone
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    phone_type_;

    static const phone_type_ phone;
  };

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::shipper_id_class_::value_type_
  query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::shipper_id_class_::
  value (A::table_name, "\"SHIPPER_ID\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::shipper_id_class_
  query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::shipper_id;

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::company_name_type_
  query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::
  company_name (A::table_name, "\"COMPANY_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::phone_type_
  query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >::
  phone (A::table_name, "\"PHONE\"", 0);

  template <typename A>
  struct pointer_query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >:
    query_columns< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::masd::cpp_ref_impl::northwind::shippers, id_sqlite >:
    public access::object_traits< ::masd::cpp_ref_impl::northwind::shippers >
  {
    public:
    struct id_image_type
    {
      composite_value_traits< ::masd::cpp_ref_impl::northwind::shipper_id, id_sqlite >::image_type id_value;

      std::size_t version;
    };

    struct image_type
    {
      // shipper_id_
      //
      composite_value_traits< ::masd::cpp_ref_impl::northwind::shipper_id, id_sqlite >::image_type shipper_id_value;

      // company_name_
      //
      details::buffer company_name_value;
      std::size_t company_name_size;
      bool company_name_null;

      // phone_
      //
      details::buffer phone_value;
      std::size_t phone_size;
      bool phone_null;

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

    static const std::size_t column_count = 3UL;
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

  // shippers
  //
}

#include "masd.cpp_ref_impl.northwind/odb/shippers-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // MASD_CPP_REF_IMPL_NORTHWIND_ODB_SHIPPERS_ODB_SQLITE_HXX