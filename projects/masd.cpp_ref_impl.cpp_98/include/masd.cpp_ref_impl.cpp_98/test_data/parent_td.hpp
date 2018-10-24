#ifndef CPP_REF_IMPL_CPP_98_TEST_DATA_PARENT_TD_HPP
#define CPP_REF_IMPL_CPP_98_TEST_DATA_PARENT_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "cpp_ref_impl/cpp_98/types/parent.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

class parent_generator {
public:
    parent_generator();

public:
    typedef cpp_ref_impl::cpp_98::parent result_type;

public:
    static void populate(const unsigned int position, result_type& v);
public:
    static result_type* create_ptr(const unsigned int position);
};

} }

#endif
