#ifndef CPP_REF_IMPL_CPP_98_IO_PACKAGE1_FIRST_CLASS_IO_HPP
#define CPP_REF_IMPL_CPP_98_IO_PACKAGE1_FIRST_CLASS_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "cpp_ref_impl/cpp_98/types/package1/first_class.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {
namespace package1 {

std::ostream&
operator<<(std::ostream& s,
     const cpp_ref_impl::cpp_98::package1::first_class& v);

} } }

#endif
