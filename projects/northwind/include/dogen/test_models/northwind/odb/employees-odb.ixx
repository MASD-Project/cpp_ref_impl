// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // employees
  //

  inline
  access::object_traits< ::dogen::test_models::northwind::employees >::id_type
  access::object_traits< ::dogen::test_models::northwind::employees >::
  id (const object_type& o)
  {
    return o.employee_id ();
  }

  inline
  void access::object_traits< ::dogen::test_models::northwind::employees >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::dogen::test_models::northwind::employees >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

