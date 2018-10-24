#ifndef CPP_REF_IMPL_CPP_98_TEST_DATA_AN_ENUMERATION_TD_HPP
#define CPP_REF_IMPL_CPP_98_TEST_DATA_AN_ENUMERATION_TD_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include "cpp_ref_impl/cpp_98/types/an_enumeration.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

class an_enumeration_generator {
public:
    an_enumeration_generator();

public:
    typedef cpp_ref_impl::cpp_98::an_enumeration result_type;

public:
    static void populate(const unsigned int position, result_type& v);
    static result_type create(const unsigned int position);
    result_type operator()();

private:
    unsigned int position_;
};

} }

#endif
