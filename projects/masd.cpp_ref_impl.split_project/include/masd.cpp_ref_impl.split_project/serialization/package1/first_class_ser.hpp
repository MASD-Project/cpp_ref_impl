#ifndef MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_SER_HPP
#define MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "masd.cpp_ref_impl.split_project/types/package1/first_class.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(masd::cpp_ref_impl::split_project::package1::first_class)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const masd::cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, masd::cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

} }

#endif
