// -*- C++ -*-
//
// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // shipper_id
  //

  inline
  bool access::composite_value_traits< ::masd::cpp_ref_impl::northwind::shipper_id, id_sqlite >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.value_null;
    return r;
  }

  inline
  void access::composite_value_traits< ::masd::cpp_ref_impl::northwind::shipper_id, id_sqlite >::
  set_null (image_type& i,
            sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    i.value_null = true;
  }
}

