#include <ostream>
#include "cpp_ref_impl/cpp_98/io/parent_io.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

std::ostream& operator<<(std::ostream& s, const parent& v) {
    v.to_stream(s);
    return(s);
}

} }
