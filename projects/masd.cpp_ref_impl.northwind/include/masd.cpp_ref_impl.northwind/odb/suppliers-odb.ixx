// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // suppliers
  //

  inline
  access::object_traits< ::masd::cpp_ref_impl::northwind::suppliers >::id_type
  access::object_traits< ::masd::cpp_ref_impl::northwind::suppliers >::
  id (const object_type& o)
  {
    return o.supplier_id ();
  }

  inline
  void access::object_traits< ::masd::cpp_ref_impl::northwind::suppliers >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::masd::cpp_ref_impl::northwind::suppliers >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

