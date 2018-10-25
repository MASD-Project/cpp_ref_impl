#include <ostream>
#include "masd.cpp_ref_impl.flat_directory_mode/io/package1/first_class_io.hpp"

namespace masd::cpp_ref_impl::flat_directory_mode::package1 {

std::ostream& operator<<(std::ostream& s, const first_class& v) {
    s << " { "
      << "\"__type__\": " << "\"masd::cpp_ref_impl::flat_directory_mode::package1::first_class\"" << ", "
      << "\"public_attribute\": " << v.public_attribute() << ", "
      << "\"private_attribute\": " << v.private_attribute()
      << " }";
    return(s);
}

}