#include <ostream>
#include "cpp_ref_impl/cpp_98/io/child_io.hpp"
#include "cpp_ref_impl/cpp_98/io/parent_io.hpp"

namespace cpp_ref_impl {
namespace cpp_98 {

std::ostream& operator<<(std::ostream& s, const child& v) {
    v.to_stream(s);
    return(s);
}

} }
