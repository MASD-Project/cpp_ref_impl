#include "masd.cpp_ref_impl.cpp_98/test_data/child_td.hpp"
#include "masd.cpp_ref_impl.cpp_98/test_data/parent_td.hpp"

namespace {

int create_int(const unsigned int position) {
    return static_cast<int>(position);
}

}

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

void parent_generator::
populate(const unsigned int position, result_type& v) {
    v.prop_0(create_int(position + 0));
}

parent_generator::result_type*
parent_generator::create_ptr(const unsigned int position) {
    return masd::cpp_ref_impl::cpp_98::child_generator::create_ptr(position);
}

} } }
