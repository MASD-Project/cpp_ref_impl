// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_SQLITE_HXX
#define CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_SQLITE_HXX

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
#include <odb/boost/date-time/sqlite/gregorian-traits.hxx>
#include <odb/boost/date-time/sqlite/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/sqlite/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20465UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "cpp_ref_impl.northwind/types/package/class_0.hpp"

#include "cpp_ref_impl.northwind/odb/package/class_0-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // class_0
  //
  template <typename A>
  struct query_columns< ::cpp_ref_impl::northwind::package::class_0, id_sqlite, A >
  {
    // prop_0
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    prop_0_type_;

    static const prop_0_type_ prop_0;
  };

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::package::class_0, id_sqlite, A >::prop_0_type_
  query_columns< ::cpp_ref_impl::northwind::package::class_0, id_sqlite, A >::
  prop_0 (A::table_name, "\"PROP_0\"", 0);

  template <typename A>
  struct pointer_query_columns< ::cpp_ref_impl::northwind::package::class_0, id_sqlite, A >:
    query_columns< ::cpp_ref_impl::northwind::package::class_0, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >:
    public access::object_traits< ::cpp_ref_impl::northwind::package::class_0 >
  {
    public:
    struct image_type
    {
      // prop_0_
      //
      long long prop_0_value;
      bool prop_0_null;

      std::size_t version;
    };

    using object_traits<object_type>::id;

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static bool
    init (image_type&,
          const object_type&,
          sqlite::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    typedef sqlite::no_id_object_statements<object_type> statements_type;

    typedef sqlite::query_base query_base_type;

    static const std::size_t column_count = 1UL;
    static const std::size_t id_column_count = 0UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
  };

  // class_0
  //
}

#include "cpp_ref_impl.northwind/odb/package/class_0-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_SQLITE_HXX
