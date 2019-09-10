// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef CPP_REF_IMPL_NORTHWIND_ODB_PRODUCTS_ODB_SQLITE_HXX
#define CPP_REF_IMPL_NORTHWIND_ODB_PRODUCTS_ODB_SQLITE_HXX

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

#include "cpp_ref_impl.northwind/types/products.hpp"

#include "cpp_ref_impl.northwind/odb/category_id-odb-sqlite.hxx"
#include "cpp_ref_impl.northwind/odb/product_id-odb-sqlite.hxx"
#include "cpp_ref_impl.northwind/odb/supplier_id-odb-sqlite.hxx"

#include "cpp_ref_impl.northwind/odb/products-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>

namespace odb
{
  // products
  //
  template <typename A>
  struct query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >
  {
    // product_id
    //
    struct product_id_class_
    {
      product_id_class_ ()
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

    static const product_id_class_ product_id;

    // product_name
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    product_name_type_;

    static const product_name_type_ product_name;

    // supplier_id
    //
    struct supplier_id_class_
    {
      supplier_id_class_ ()
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

    static const supplier_id_class_ supplier_id;

    // category_id
    //
    struct category_id_class_
    {
      category_id_class_ ()
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

    static const category_id_class_ category_id;

    // quantity_per_unit
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        ::std::string,
        sqlite::id_text >::query_type,
      sqlite::id_text >
    quantity_per_unit_type_;

    static const quantity_per_unit_type_ quantity_per_unit;

    // unit_price
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        double,
        sqlite::id_real >::query_type,
      sqlite::id_real >
    unit_price_type_;

    static const unit_price_type_ unit_price;

    // units_in_stock
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    units_in_stock_type_;

    static const units_in_stock_type_ units_in_stock;

    // units_in_order
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    units_in_order_type_;

    static const units_in_order_type_ units_in_order;

    // reorder_level
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    reorder_level_type_;

    static const reorder_level_type_ reorder_level;

    // discontinued
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        bool,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    discontinued_type_;

    static const discontinued_type_ discontinued;
  };

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::product_id_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::product_id_class_::
  value (A::table_name, "\"PRODUCT_ID\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::product_id_class_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::product_id;

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::product_name_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  product_name (A::table_name, "\"PRODUCT_NAME\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::supplier_id_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::supplier_id_class_::
  value (A::table_name, "\"SUPPLIER_ID\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::supplier_id_class_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::supplier_id;

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::category_id_class_::value_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::category_id_class_::
  value (A::table_name, "\"CATEGORY_ID\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::category_id_class_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::category_id;

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::quantity_per_unit_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  quantity_per_unit (A::table_name, "\"QUANTITY_PER_UNIT\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::unit_price_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  unit_price (A::table_name, "\"UNIT_PRICE\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::units_in_stock_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  units_in_stock (A::table_name, "\"UNITS_IN_STOCK\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::units_in_order_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  units_in_order (A::table_name, "\"UNITS_IN_ORDER\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::reorder_level_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  reorder_level (A::table_name, "\"REORDER_LEVEL\"", 0);

  template <typename A>
  const typename query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::discontinued_type_
  query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >::
  discontinued (A::table_name, "\"DISCONTINUED\"", 0);

  template <typename A>
  struct pointer_query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >:
    query_columns< ::cpp_ref_impl::northwind::products, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >:
    public access::object_traits< ::cpp_ref_impl::northwind::products >
  {
    public:
    struct id_image_type
    {
      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::image_type id_value;

      std::size_t version;
    };

    struct image_type
    {
      // product_id_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::image_type product_id_value;

      // product_name_
      //
      details::buffer product_name_value;
      std::size_t product_name_size;
      bool product_name_null;

      // supplier_id_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::supplier_id, id_sqlite >::image_type supplier_id_value;

      // category_id_
      //
      composite_value_traits< ::cpp_ref_impl::northwind::category_id, id_sqlite >::image_type category_id_value;

      // quantity_per_unit_
      //
      details::buffer quantity_per_unit_value;
      std::size_t quantity_per_unit_size;
      bool quantity_per_unit_null;

      // unit_price_
      //
      double unit_price_value;
      bool unit_price_null;

      // units_in_stock_
      //
      long long units_in_stock_value;
      bool units_in_stock_null;

      // units_in_order_
      //
      long long units_in_order_value;
      bool units_in_order_null;

      // reorder_level_
      //
      long long reorder_level_value;
      bool reorder_level_null;

      // discontinued_
      //
      long long discontinued_value;
      bool discontinued_null;

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

    static const std::size_t column_count = 10UL;
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

  // products
  //
}

#include "cpp_ref_impl.northwind/odb/products-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // CPP_REF_IMPL_NORTHWIND_ODB_PRODUCTS_ODB_SQLITE_HXX
