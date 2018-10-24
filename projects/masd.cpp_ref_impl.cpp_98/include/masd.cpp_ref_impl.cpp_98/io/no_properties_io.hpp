#ifndef MASD_CPP_REF_IMPL_CPP_98_IO_NO_PROPERTIES_IO_HPP
#define MASD_CPP_REF_IMPL_CPP_98_IO_NO_PROPERTIES_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "masd.cpp_ref_impl.cpp_98/types/no_properties.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

std::ostream&
operator<<(std::ostream& s,
     const masd::cpp_ref_impl::cpp_98::no_properties& v);

} } }

#endif
