// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "cpp_ref_impl.northwind/odb/package/class_0-odb-sqlite.hxx"

#include <cassert>
#include <cstring>  // std::memcpy

#include <odb/schema-catalog-impl.hxx>

#include <odb/sqlite/traits.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/sqlite/transaction.hxx>
#include <odb/sqlite/connection.hxx>
#include <odb/sqlite/statement.hxx>
#include <odb/sqlite/statement-cache.hxx>
#include <odb/sqlite/no-id-object-statements.hxx>
#include <odb/sqlite/container-statements.hxx>
#include <odb/sqlite/exceptions.hxx>
#include <odb/sqlite/no-id-object-result.hxx>

namespace odb
{
  // class_0
  //

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
  grow (image_type& i,
        bool* t)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (t);

    bool grew (false);

    // prop_0_
    //
    t[0UL] = false;

    return grew;
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
  bind (sqlite::bind* b,
        image_type& i,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    std::size_t n (0);

    // prop_0_
    //
    b[n].type = sqlite::bind::integer;
    b[n].buffer = &i.prop_0_value;
    b[n].is_null = &i.prop_0_null;
    n++;
  }

  bool access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
  init (image_type& i,
        const object_type& o,
        sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    bool grew (false);

    // prop_0_
    //
    {
      int const& v =
        o.prop_0 ();

      bool is_null (false);
      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_image (
        i.prop_0_value,
        is_null,
        v);
      i.prop_0_null = is_null;
    }

    return grew;
  }

  void access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // prop_0_
    //
    {
      int v;

      sqlite::value_traits<
          int,
          sqlite::id_integer >::set_value (
        v,
        i.prop_0_value,
        i.prop_0_null);

      o.prop_0 (v);
    }
  }

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::persist_statement[] =
  "INSERT INTO \"CLASS_0\" "
  "(\"PROP_0\") "
  "VALUES "
  "(?)";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::query_statement[] =
  "SELECT "
  "\"CLASS_0\".\"PROP_0\" "
  "FROM \"CLASS_0\"";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::erase_query_statement[] =
  "DELETE FROM \"CLASS_0\"";

  const char access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::table_name[] =
  "\"CLASS_0\"";

  void access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
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

  result< access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::object_type >
  access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
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

    shared_ptr< odb::no_id_object_result_impl<object_type> > r (
      new (shared) sqlite::no_id_object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::cpp_ref_impl::northwind::package::class_0, id_sqlite >::
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
          db.execute ("DROP TABLE IF EXISTS \"CLASS_0\"");
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
          db.execute ("CREATE TABLE \"CLASS_0\" (\n"
                      "  \"PROP_0\" INTEGER NOT NULL)");
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
