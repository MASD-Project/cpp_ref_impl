#ifndef CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_SER_HPP
#define CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "cpp_ref_impl/split_project/types/package1/first_class.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(cpp_ref_impl::split_project::package1::first_class)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

} }

#endif
