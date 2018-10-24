#include <ostream>
#include "masd.cpp_ref_impl.cpp_98/io/package1/first_class_io.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {
namespace package1 {

std::ostream& operator<<(std::ostream& s, const first_class& v) {
    s << " { "
      << "\"__type__\": " << "\"masd::cpp_ref_impl::cpp_98::package1::first_class\"" << ", "
      << "\"public_attribute\": " << v.public_attribute() << ", "
      << "\"private_attribute\": " << v.private_attribute()
      << " }";
    return(s);
}

} } } }
