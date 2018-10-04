#ifndef CPP_REF_IMPL_CPP_98_SERIALIZATION_NO_DEFAULT_CTOR_SER_HPP
#define CPP_REF_IMPL_CPP_98_SERIALIZATION_NO_DEFAULT_CTOR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <boost/serialization/split_free.hpp>
#include "cpp_ref_impl/cpp_98/types/no_default_ctor.hpp"

BOOST_SERIALIZATION_SPLIT_FREE(cpp_ref_impl::cpp_98::no_default_ctor)
namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar, const cpp_ref_impl::cpp_98::no_default_ctor& v, unsigned int version);

template<typename Archive>
void load(Archive& ar, cpp_ref_impl::cpp_98::no_default_ctor& v, unsigned int version);

} }

#endif
