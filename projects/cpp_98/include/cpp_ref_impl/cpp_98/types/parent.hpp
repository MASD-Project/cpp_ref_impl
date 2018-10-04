#ifndef CPP_REF_IMPL_CPP_98_TYPES_PARENT_HPP
#define CPP_REF_IMPL_CPP_98_TYPES_PARENT_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <iosfwd>
#include <algorithm>
#include "cpp_ref_impl/cpp_98/serialization/parent_fwd_ser.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

class parent {
public:
    parent();

    virtual ~parent() = 0;

public:
    explicit parent(const int prop_0);

private:
    template<typename Archive>
    friend void boost::serialization::save(Archive& ar, const cpp_ref_impl::cpp_98::parent& v, unsigned int version);

    template<typename Archive>
    friend void boost::serialization::load(Archive& ar, cpp_ref_impl::cpp_98::parent& v, unsigned int version);

public:
    virtual void to_stream(std::ostream& s) const;

public:
    int prop_0() const;
    void prop_0(const int v);

protected:
    bool compare(const parent& rhs) const;
public:
    virtual bool equals(const parent& other) const = 0;

protected:
    void swap(parent& other);

private:
    int prop_0_;
};

inline parent::~parent() { }

inline bool operator==(const parent& lhs, const parent& rhs) {
    return lhs.equals(rhs);
}

} }

#endif
