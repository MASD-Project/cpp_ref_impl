#ifndef CPP_REF_IMPL_SPLIT_PROJECT_TYPES_PACKAGE1_FIRST_CLASS_HPP
#define CPP_REF_IMPL_SPLIT_PROJECT_TYPES_PACKAGE1_FIRST_CLASS_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <algorithm>
#include "cpp_ref_impl/split_project/serialization/package1/first_class_fwd_ser.hpp"

namespace cpp_ref_impl::split_project::package1 {

class first_class final {
public:
    first_class(const first_class&) = default;
    first_class(first_class&&) = default;
    ~first_class() = default;

public:
    first_class();

public:
    first_class(
        const int public_attribute,
        const int private_attribute);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

public:
    int public_attribute() const;
    void public_attribute(const int v);

    int private_attribute() const;
    void private_attribute(const int v);

public:
    bool operator==(const first_class& rhs) const;
    bool operator!=(const first_class& rhs) const {
        return !this->operator==(rhs);
    }

public:
    void swap(first_class& other) noexcept;
    first_class& operator=(first_class other);

private:
    int public_attribute_;
    int private_attribute_;
};

}

namespace std {

template<>
inline void swap(
    cpp_ref_impl::split_project::package1::first_class& lhs,
    cpp_ref_impl::split_project::package1::first_class& rhs) {
    lhs.swap(rhs);
}

}

#endif
