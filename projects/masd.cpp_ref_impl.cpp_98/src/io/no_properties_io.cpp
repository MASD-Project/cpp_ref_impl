#include <ostream>
#include "masd.cpp_ref_impl.cpp_98/io/no_properties_io.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

std::ostream& operator<<(std::ostream& s, const no_properties&) {
    s << " { "
      << "\"__type__\": " << "\"masd::cpp_ref_impl::cpp_98::no_properties\"" << " }";
    return(s);
}

} } }
