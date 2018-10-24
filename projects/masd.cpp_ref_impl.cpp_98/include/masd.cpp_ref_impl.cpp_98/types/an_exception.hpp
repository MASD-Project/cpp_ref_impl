#ifndef MASD_CPP_REF_IMPL_CPP_98_TYPES_AN_EXCEPTION_HPP
#define MASD_CPP_REF_IMPL_CPP_98_TYPES_AN_EXCEPTION_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#include <string>
#include <boost/exception/info.hpp>

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

class an_exception : public virtual std::exception, public virtual boost::exception {
public:
    an_exception() {}
    ~an_exception() {}

public:
    explicit an_exception(const std::string& message) : message_(message) { }

public:
    const char* what() const BOOST_NOEXCEPT { return(message_.c_str()); }

private:
    const std::string message_;
};

} } }

#endif
