#ifndef MASD_CPP_REF_IMPL_CPP_98_TEST_DATA_CHILD_TD_HPP
#define MASD_CPP_REF_IMPL_CPP_98_TEST_DATA_CHILD_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "masd.cpp_ref_impl.cpp_98/types/child.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

class child_generator {
public:
    child_generator();

public:
    typedef masd::cpp_ref_impl::cpp_98::child result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
public:
    static result_type* create_ptr(const unsigned int position);
};

} } }

#endif