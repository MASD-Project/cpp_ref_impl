// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // order_details
  //

  inline
  access::object_traits< ::dogen::test_models::northwind::order_details >::id_type
  access::object_traits< ::dogen::test_models::northwind::order_details >::
  id (const object_type& o)
  {
    return o.order_details_key ();
  }

  inline
  void access::object_traits< ::dogen::test_models::northwind::order_details >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::dogen::test_models::northwind::order_details >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

