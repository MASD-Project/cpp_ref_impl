#ifndef CPP_REF_IMPL_CPP_98_IO_NO_DEFAULT_CTOR_IO_HPP
#define CPP_REF_IMPL_CPP_98_IO_NO_DEFAULT_CTOR_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "cpp_ref_impl/cpp_98/types/no_default_ctor.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

std::ostream&
operator<<(std::ostream& s,
     const cpp_ref_impl::cpp_98::no_default_ctor& v);

} }

#endif
