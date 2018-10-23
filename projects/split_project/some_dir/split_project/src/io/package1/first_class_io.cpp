#include <ostream>
#include "cpp_ref_impl/split_project/io/package1/first_class_io.hpp"

namespace cpp_ref_impl::split_project::package1 {

std::ostream& operator<<(std::ostream& s, const first_class& v) {
    s << " { "
      << "\"__type__\": " << "\"cpp_ref_impl::split_project::package1::first_class\"" << ", "
      << "\"public_attribute\": " << v.public_attribute() << ", "
      << "\"private_attribute\": " << v.private_attribute()
      << " }";
    return(s);
}

}
