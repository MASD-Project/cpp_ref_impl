// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "cpp_ref_impl.northwind/odb/products-odb-sqlite.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/simple-object-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/simple-object-result.hxx>

namespace odb
{
  // products
  //

  struct access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::extra_statement_cache_type
  {
    extra_statement_cache_type (
      sqlite::connection&,
      image_type&,
      id_image_type&,
      sqlite::binding&,
      sqlite::binding&)
    {
    }
  };

  access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::id_type
  access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  id (const image_type& i)
  {
    sqlite::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::init (
        id,
        i.product_id_value,
        db);
    }

    return id;
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // product_id_
    //
    if (composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::grow (
          i.product_id_value, t + 0UL))
      grew = true;

    // product_name_
    //
    if (t[1UL])
    {
      i.product_name_value.capacity (i.product_name_size);
      grew = true;
    }

    // supplier_id_
    //
    if (composite_value_traits< ::cpp_ref_impl::northwind::supplier_id, id_sqlite >::grow (
          i.supplier_id_value, t + 2UL))
      grew = true;

    // category_id_
    //
    if (composite_value_traits< ::cpp_ref_impl::northwind::category_id, id_sqlite >::grow (
          i.category_id_value, t + 3UL))
      grew = true;

    // quantity_per_unit_
    //
    if (t[4UL])
    {
      i.quantity_per_unit_value.capacity (i.quantity_per_unit_size);
      grew = true;
    }

    // unit_price_
    //
    t[5UL] = false;

    // units_in_stock_
    //
    t[6UL] = false;

    // units_in_order_
    //
    t[7UL] = false;

    // reorder_level_
    //
    t[8UL] = false;

    // discontinued_
    //
    t[9UL] = false;

    return grew;
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // product_id_
    //
    if (sk != statement_update)
    {
      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::bind (
        b + n, i.product_id_value, sk);
      n += 1UL;
    }

    // product_name_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.product_name_value.data ();
    b[n].size = &i.product_name_size;
    b[n].capacity = i.product_name_value.capacity ();
    b[n].is_null = &i.product_name_null;
    n++;

    // supplier_id_
    //
    composite_value_traits< ::cpp_ref_impl::northwind::supplier_id, id_sqlite >::bind (
      b + n, i.supplier_id_value, sk);
    n += 1UL;

    // category_id_
    //
    composite_value_traits< ::cpp_ref_impl::northwind::category_id, id_sqlite >::bind (
      b + n, i.category_id_value, sk);
    n += 1UL;

    // quantity_per_unit_
    //
    b[n].type = sqlite::image_traits<
      ::std::string,
      sqlite::id_text>::bind_value;
    b[n].buffer = i.quantity_per_unit_value.data ();
    b[n].size = &i.quantity_per_unit_size;
    b[n].capacity = i.quantity_per_unit_value.capacity ();
    b[n].is_null = &i.quantity_per_unit_null;
    n++;

    // unit_price_
    //
    b[n].type = sqlite::bind::real;
    b[n].buffer = &i.unit_price_value;
    b[n].is_null = &i.unit_price_null;
    n++;

    // units_in_stock_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.units_in_stock_value;
    b[n].is_null = &i.units_in_stock_null;
    n++;

    // units_in_order_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.units_in_order_value;
    b[n].is_null = &i.units_in_order_null;
    n++;

    // reorder_level_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.reorder_level_value;
    b[n].is_null = &i.reorder_level_null;
    n++;

    // discontinued_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.discontinued_value;
    b[n].is_null = &i.discontinued_null;
    n++;
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    sqlite::statement_kind sk (sqlite::statement_select);
    composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::bind (
      b + n, i.id_value, sk);
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // product_id_
    //
    if (sk == statement_insert)
    {
      ::cpp_ref_impl::northwind::product_id const& v =
        o.product_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::init (
        i.product_id_value,
        v,
        sk);
    }

    // product_name_
    //
    {
      ::std::string const& v =
        o.product_name ();

      bool is_null (false);
      std::size_t cap (i.product_name_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.product_name_value,
        i.product_name_size,
        is_null,
        v);
      i.product_name_null = is_null;
      grew = grew || (cap != i.product_name_value.capacity ());
    }

    // supplier_id_
    //
    {
      ::cpp_ref_impl::northwind::supplier_id const& v =
        o.supplier_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::supplier_id, id_sqlite >::init (
        i.supplier_id_value,
        v,
        sk);
    }

    // category_id_
    //
    {
      ::cpp_ref_impl::northwind::category_id const& v =
        o.category_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::category_id, id_sqlite >::init (
        i.category_id_value,
        v,
        sk);
    }

    // quantity_per_unit_
    //
    {
      ::std::string const& v =
        o.quantity_per_unit ();

      bool is_null (false);
      std::size_t cap (i.quantity_per_unit_value.capacity ());
      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_image (
        i.quantity_per_unit_value,
        i.quantity_per_unit_size,
        is_null,
        v);
      i.quantity_per_unit_null = is_null;
      grew = grew || (cap != i.quantity_per_unit_value.capacity ());
    }

    // unit_price_
    //
    {
      double const& v =
        o.unit_price ();

      bool is_null (true);
      sqlite::value_traits<
          double,
          sqlite::id_real >::set_image (
        i.unit_price_value,
        is_null,
        v);
      i.unit_price_null = is_null;
    }

    // units_in_stock_
    //
    {
      int const& v =
        o.units_in_stock ();

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.units_in_stock_value,
        is_null,
        v);
      i.units_in_stock_null = is_null;
    }

    // units_in_order_
    //
    {
      int const& v =
        o.units_in_order ();

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.units_in_order_value,
        is_null,
        v);
      i.units_in_order_null = is_null;
    }

    // reorder_level_
    //
    {
      int const& v =
        o.reorder_level ();

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.reorder_level_value,
        is_null,
        v);
      i.reorder_level_null = is_null;
    }

    // discontinued_
    //
    {
      bool const& v =
        o.discontinued ();

      bool is_null (false);
      sqlite::value_traits<
          bool,
          sqlite::id_integer >::set_image (
        i.discontinued_value,
        is_null,
        v);
      i.discontinued_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // product_id_
    //
    {
      ::cpp_ref_impl::northwind::product_id& v =
        o.product_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::init (
        v,
        i.product_id_value,
        db);
    }

    // product_name_
    //
    {
      ::std::string& v =
        o.product_name ();

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.product_name_value,
        i.product_name_size,
        i.product_name_null);
    }

    // supplier_id_
    //
    {
      ::cpp_ref_impl::northwind::supplier_id& v =
        o.supplier_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::supplier_id, id_sqlite >::init (
        v,
        i.supplier_id_value,
        db);
    }

    // category_id_
    //
    {
      ::cpp_ref_impl::northwind::category_id& v =
        o.category_id ();

      composite_value_traits< ::cpp_ref_impl::northwind::category_id, id_sqlite >::init (
        v,
        i.category_id_value,
        db);
    }

    // quantity_per_unit_
    //
    {
      ::std::string& v =
        o.quantity_per_unit ();

      sqlite::value_traits<
          ::std::string,
          sqlite::id_text >::set_value (
        v,
        i.quantity_per_unit_value,
        i.quantity_per_unit_size,
        i.quantity_per_unit_null);
    }

    // unit_price_
    //
    {
      double v;

      sqlite::value_traits<
          double,
          sqlite::id_real >::set_value (
        v,
        i.unit_price_value,
        i.unit_price_null);

      o.unit_price (v);
    }

    // units_in_stock_
    //
    {
      int v;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.units_in_stock_value,
        i.units_in_stock_null);

      o.units_in_stock (v);
    }

    // units_in_order_
    //
    {
      int v;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.units_in_order_value,
        i.units_in_order_null);

      o.units_in_order (v);
    }

    // reorder_level_
    //
    {
      int v;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.reorder_level_value,
        i.reorder_level_null);

      o.reorder_level (v);
    }

    // discontinued_
    //
    {
      bool v;

      sqlite::value_traits<
          bool,
          sqlite::id_integer >::set_value (
        v,
        i.discontinued_value,
        i.discontinued_null);

      o.discontinued (v);
    }
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  init (id_image_type& i, const id_type& id)
  {
    sqlite::statement_kind sk (sqlite::statement_select);
    {
      composite_value_traits< ::cpp_ref_impl::northwind::product_id, id_sqlite >::init (
        i.id_value,
        id,
        sk);
    }
  }

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::persist_statement[] =
  "INSERT INTO \"NORTHWIND\".\"PRODUCTS\" "
  "(\"PRODUCT_ID\", "
  "\"PRODUCT_NAME\", "
  "\"SUPPLIER_ID\", "
  "\"CATEGORY_ID\", "
  "\"QUANTITY_PER_UNIT\", "
  "\"UNIT_PRICE\", "
  "\"UNITS_IN_STOCK\", "
  "\"UNITS_IN_ORDER\", "
  "\"REORDER_LEVEL\", "
  "\"DISCONTINUED\") "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::find_statement[] =
  "SELECT "
  "\"NORTHWIND\".\"PRODUCTS\".\"PRODUCT_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"PRODUCT_NAME\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"SUPPLIER_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"CATEGORY_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"QUANTITY_PER_UNIT\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNIT_PRICE\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNITS_IN_STOCK\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNITS_IN_ORDER\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"REORDER_LEVEL\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"DISCONTINUED\" "
  "FROM \"NORTHWIND\".\"PRODUCTS\" "
  "WHERE \"NORTHWIND\".\"PRODUCTS\".\"PRODUCT_ID\"=?";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::update_statement[] =
  "UPDATE \"NORTHWIND\".\"PRODUCTS\" "
  "SET "
  "\"PRODUCT_NAME\"=?, "
  "\"SUPPLIER_ID\"=?, "
  "\"CATEGORY_ID\"=?, "
  "\"QUANTITY_PER_UNIT\"=?, "
  "\"UNIT_PRICE\"=?, "
  "\"UNITS_IN_STOCK\"=?, "
  "\"UNITS_IN_ORDER\"=?, "
  "\"REORDER_LEVEL\"=?, "
  "\"DISCONTINUED\"=? "
  "WHERE \"PRODUCT_ID\"=?";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::erase_statement[] =
  "DELETE FROM \"NORTHWIND\".\"PRODUCTS\" "
  "WHERE \"PRODUCT_ID\"=?";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::query_statement[] =
  "SELECT "
  "\"NORTHWIND\".\"PRODUCTS\".\"PRODUCT_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"PRODUCT_NAME\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"SUPPLIER_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"CATEGORY_ID\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"QUANTITY_PER_UNIT\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNIT_PRICE\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNITS_IN_STOCK\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"UNITS_IN_ORDER\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"REORDER_LEVEL\", "
  "\"NORTHWIND\".\"PRODUCTS\".\"DISCONTINUED\" "
  "FROM \"NORTHWIND\".\"PRODUCTS\"";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"NORTHWIND\".\"PRODUCTS\"";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::table_name[] =
  "\"NORTHWIND\".\"PRODUCTS\"";

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    if (init (im, obj, statement_insert))
      im.version++;

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace sqlite;
    using sqlite::update_statement;

    callback (db, obj, callback_event::pre_update);

    sqlite::transaction& tr (sqlite::transaction::current ());
    sqlite::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& idi (sts.id_image ());
    init (idi, id (obj));

    image_type& im (sts.image ());
    if (init (im, obj, statement_update))
      im.version++;

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  erase (database& db, const id_type& id)
  {
    using namespace sqlite;

    ODB_POTENTIALLY_UNUSED (db);

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::pointer_type
  access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  find (database& db, const id_type& id)
  {
    using namespace sqlite;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  reload (database& db, object_type& obj)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    assert (l.locked ()) /* Must be a top-level call. */;

    const id_type& id (object_traits_impl::id (obj));
    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace sqlite;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r == select_statement::truncated)
    {
      if (grow (im, sts.select_image_truncated ()))
        im.version++;

      if (im.version != sts.select_image_version ())
      {
        bind (imb.bind, im, statement_select);
        sts.select_image_version (im.version);
        imb.version++;
        st.refetch ();
      }
    }

    return r != select_statement::no_data;
  }

  result< access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::object_type >
  access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  query (database&, const query_base_type& q)
  {
    using namespace sqlite;
    using odb::details::shared;
    using odb::details::shared_ptr;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) sqlite::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::cpp_ref_impl::northwind::products, id_sqlite >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace sqlite;

    sqlite::connection& conn (
      sqlite::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

namespace odb
{
  static bool
  create_schema (database& db, unsigned short pass, bool drop)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (pass);
    ODB_POTENTIALLY_UNUSED (drop);

    if (drop)
    {
      switch (pass)
      {
        case 1:
        {
          return true;
        }
        case 2:
        {
          db.execute ("DROP TABLE IF EXISTS \"NORTHWIND\".\"PRODUCTS\"");
          return false;
        }
      }
    }
    else
    {
      switch (pass)
      {
        case 1:
        {
          db.execute ("CREATE TABLE \"NORTHWIND\".\"PRODUCTS\" (\n"
                      "  \"PRODUCT_ID\" INTEGER NOT NULL PRIMARY KEY,\n"
                      "  \"PRODUCT_NAME\" TEXT NOT NULL,\n"
                      "  \"SUPPLIER_ID\" INTEGER NULL,\n"
                      "  \"CATEGORY_ID\" INTEGER NULL,\n"
                      "  \"QUANTITY_PER_UNIT\" TEXT NOT NULL,\n"
                      "  \"UNIT_PRICE\" REAL NULL,\n"
                      "  \"UNITS_IN_STOCK\" INTEGER NOT NULL,\n"
                      "  \"UNITS_IN_ORDER\" INTEGER NOT NULL,\n"
                      "  \"REORDER_LEVEL\" INTEGER NOT NULL,\n"
                      "  \"DISCONTINUED\" INTEGER NOT NULL)");
          return false;
        }
      }
    }

    return false;
  }

  static const schema_catalog_create_entry
  create_schema_entry_ (
    id_sqlite,
    "",
    &create_schema);
}

#include <odb/post.hxx>