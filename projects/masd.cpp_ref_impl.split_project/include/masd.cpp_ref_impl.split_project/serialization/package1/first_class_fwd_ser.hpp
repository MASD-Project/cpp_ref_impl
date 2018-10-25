#ifndef MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_FWD_SER_HPP
#define MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_PACKAGE1_FIRST_CLASS_FWD_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "masd.cpp_ref_impl.split_project/types/package1/first_class_fwd.hpp"

namespace boost {
namespace serialization {

template<class Archive>
void save(Archive& ar, const masd::cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template<class Archive>
void load(Archive& ar, masd::cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

} }

#endif