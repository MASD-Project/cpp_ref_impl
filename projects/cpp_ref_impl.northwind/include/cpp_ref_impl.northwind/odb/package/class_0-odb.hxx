// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_HXX
#define CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_HXX

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

#include "cpp_ref_impl.northwind/types/package/class_0.hpp"

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
#include <odb/no-id-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // class_0
  //
  template <>
  struct class_traits< ::cpp_ref_impl::northwind::package::class_0 >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::cpp_ref_impl::northwind::package::class_0 >
  {
    public:
    typedef ::cpp_ref_impl::northwind::package::class_0 object_type;
    typedef ::boost::shared_ptr< ::cpp_ref_impl::northwind::package::class_0 > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef void id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_id_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_id_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };
}

#include "cpp_ref_impl.northwind/odb/package/class_0-odb.ixx"

#include <odb/post.hxx>

#endif // CPP_REF_IMPL_NORTHWIND_ODB_PACKAGE_CLASS_0_ODB_HXX
