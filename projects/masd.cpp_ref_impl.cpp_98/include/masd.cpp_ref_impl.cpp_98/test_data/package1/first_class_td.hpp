#ifndef MASD_CPP_REF_IMPL_CPP_98_TEST_DATA_PACKAGE1_FIRST_CLASS_TD_HPP
#define MASD_CPP_REF_IMPL_CPP_98_TEST_DATA_PACKAGE1_FIRST_CLASS_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "masd.cpp_ref_impl.cpp_98/types/package1/first_class.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {
namespace package1 {

class first_class_generator {
public:
    first_class_generator();

public:
    typedef masd::cpp_ref_impl::cpp_98::package1::first_class result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
public:
    static result_type* create_ptr(const unsigned int position);
};

} } } }

#endif