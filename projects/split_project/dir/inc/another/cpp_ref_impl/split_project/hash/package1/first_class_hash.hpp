#ifndef CPP_REF_IMPL_SPLIT_PROJECT_HASH_PACKAGE1_FIRST_CLASS_HASH_HPP
#define CPP_REF_IMPL_SPLIT_PROJECT_HASH_PACKAGE1_FIRST_CLASS_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "cpp_ref_impl/split_project/types/package1/first_class.hpp"

namespace cpp_ref_impl::split_project::package1 {

struct first_class_hasher {
public:
    static std::size_t hash(const first_class& v);
};

}

namespace std {

template<>
struct hash<cpp_ref_impl::split_project::package1::first_class> {
public:
    size_t operator()(const cpp_ref_impl::split_project::package1::first_class& v) const {
        return cpp_ref_impl::split_project::package1::first_class_hasher::hash(v);
    }
};

}
#endif
