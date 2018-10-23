#ifndef CPP_REF_IMPL_SPLIT_PROJECT_IO_PACKAGE1_FIRST_CLASS_IO_HPP
#define CPP_REF_IMPL_SPLIT_PROJECT_IO_PACKAGE1_FIRST_CLASS_IO_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include "cpp_ref_impl/split_project/types/package1/first_class.hpp"

namespace cpp_ref_impl::split_project::package1 {

std::ostream&
operator<<(std::ostream& s,
     const cpp_ref_impl::split_project::package1::first_class& v);

}

#endif
