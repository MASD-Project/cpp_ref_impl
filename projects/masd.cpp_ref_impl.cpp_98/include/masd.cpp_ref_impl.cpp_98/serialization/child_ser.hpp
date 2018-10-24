#ifndef MASD_CPP_REF_IMPL_CPP_98_SERIALIZATION_CHILD_SER_HPP
#define MASD_CPP_REF_IMPL_CPP_98_SERIALIZATION_CHILD_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include <boost/type_traits/is_virtual_base_of.hpp>
#include "masd.cpp_ref_impl.cpp_98/types/child.hpp"

namespace boost {

template<>struct
is_virtual_base_of<
    masd::cpp_ref_impl::cpp_98::parent,
    masd::cpp_ref_impl::cpp_98::child
> : public mpl::true_ {};

}

BOOST_SERIALIZATION_SPLIT_FREE(masd::cpp_ref_impl::cpp_98::child)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const masd::cpp_ref_impl::cpp_98::child& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, masd::cpp_ref_impl::cpp_98::child& v, unsigned int version);

} }

#endif
