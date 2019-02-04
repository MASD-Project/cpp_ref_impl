// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef MASD_CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_HXX
#define MASD_CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_HXX

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
#include <odb/boost/multi-index/container-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20459UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "masd.cpp_ref_impl.northwind/types/customers.hpp"

#include "masd.cpp_ref_impl.northwind/odb/customer_id-odb.hxx"

#include <memory>
#include <cstddef>
#include <utility>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // customers
  //
  template <>
  struct class_traits< ::masd::cpp_ref_impl::northwind::customers >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::masd::cpp_ref_impl::northwind::customers >
  {
    public:
    typedef ::masd::cpp_ref_impl::northwind::customers object_type;
    typedef ::boost::shared_ptr< ::masd::cpp_ref_impl::northwind::customers > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::masd::cpp_ref_impl::northwind::customer_id id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include "masd.cpp_ref_impl.northwind/odb/customers-odb.ixx"

#include <odb/post.hxx>

#endif // MASD_CPP_REF_IMPL_NORTHWIND_ODB_CUSTOMERS_ODB_HXX
