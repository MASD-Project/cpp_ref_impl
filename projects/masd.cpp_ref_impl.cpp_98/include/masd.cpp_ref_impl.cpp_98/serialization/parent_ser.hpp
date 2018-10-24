#ifndef MASD_CPP_REF_IMPL_CPP_98_SERIALIZATION_PARENT_SER_HPP
#define MASD_CPP_REF_IMPL_CPP_98_SERIALIZATION_PARENT_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include "masd.cpp_ref_impl.cpp_98/types/parent.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(masd::cpp_ref_impl::cpp_98::parent)
BOOST_SERIALIZATION_ASSUME_ABSTRACT(masd::cpp_ref_impl::cpp_98::parent)

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const masd::cpp_ref_impl::cpp_98::parent& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, masd::cpp_ref_impl::cpp_98::parent& v, unsigned int version);

} }

#endif
