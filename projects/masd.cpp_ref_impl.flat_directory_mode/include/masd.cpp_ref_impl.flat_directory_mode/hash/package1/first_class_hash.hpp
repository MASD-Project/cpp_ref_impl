#ifndef MASD_CPP_REF_IMPL_FLAT_DIRECTORY_MODE_HASH_PACKAGE1_FIRST_CLASS_HASH_HPP
#define MASD_CPP_REF_IMPL_FLAT_DIRECTORY_MODE_HASH_PACKAGE1_FIRST_CLASS_HASH_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <functional>
#include "masd.cpp_ref_impl.flat_directory_mode/types/package1/first_class.hpp"

namespace masd::cpp_ref_impl::flat_directory_mode::package1 {

struct first_class_hasher {
public:
    static std::size_t hash(const first_class& v);
};

}

namespace std {

template<>
struct hash<masd::cpp_ref_impl::flat_directory_mode::package1::first_class> {
public:
    size_t operator()(const masd::cpp_ref_impl::flat_directory_mode::package1::first_class& v) const {
        return masd::cpp_ref_impl::flat_directory_mode::package1::first_class_hasher::hash(v);
    }
};

}
#endif
