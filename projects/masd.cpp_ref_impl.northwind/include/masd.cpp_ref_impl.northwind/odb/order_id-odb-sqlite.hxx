// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDER_ID_ODB_SQLITE_HXX
#define MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDER_ID_ODB_SQLITE_HXX

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

#include "masd.cpp_ref_impl.northwind/types/order_id.hpp"

#include "masd.cpp_ref_impl.northwind/odb/order_id-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // order_id
  //
  template <>
  class access::composite_value_traits< ::masd::cpp_ref_impl::northwind::order_id, id_sqlite >
  {
    public:
    typedef ::masd::cpp_ref_impl::northwind::order_id value_type;

    struct image_type
    {
      // value_
      //
      long long value_value;
      bool value_null;
    };

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static bool
    init (image_type&,
          const value_type&,
          sqlite::statement_kind);

    static void
    init (value_type&,
          const image_type&,
          database*);

    static bool
    get_null (const image_type&);

    static void
    set_null (image_type&,
              sqlite::statement_kind);

    static const std::size_t column_count = 1UL;
  };
}

#include "masd.cpp_ref_impl.northwind/odb/order_id-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // MASD_CPP_REF_IMPL_NORTHWIND_ODB_ORDER_ID_ODB_SQLITE_HXX
