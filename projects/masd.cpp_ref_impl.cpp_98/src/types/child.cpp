#include <ostream>
#include "masd.cpp_ref_impl.cpp_98/types/child.hpp"
#include "masd.cpp_ref_impl.cpp_98/io/parent_io.hpp"

namespace masd {
namespace cpp_ref_impl {
namespace cpp_98 {

child::child()
    : prop_1_(static_cast<int>(0)) { }

child::child(
    const int prop_0,
    const int prop_1)
    : masd::cpp_ref_impl::cpp_98::parent(prop_0),
      prop_1_(prop_1) { }

void child::to_stream(std::ostream& s) const {
    s << " { "
      << "\"__type__\": " << "\"masd::cpp_ref_impl::cpp_98::child\"" << ", "
      << "\"__parent_0__\": ";
    masd::cpp_ref_impl::cpp_98::parent::to_stream(s);
    s << ", "
      << "\"prop_1\": " << prop_1_
      << " }";
}

void child::swap(child& other) {
    masd::cpp_ref_impl::cpp_98::parent::swap(other);

    using std::swap;
    swap(prop_1_, other.prop_1_);
}

bool child::equals(const masd::cpp_ref_impl::cpp_98::parent& other) const {
    const child* const p(dynamic_cast<const child* const>(&other));
    if (!p) return false;
    return *this == *p;
}

bool child::operator==(const child& rhs) const {
    return masd::cpp_ref_impl::cpp_98::parent::compare(rhs) &&
        prop_1_ == rhs.prop_1_;
}

child& child::operator=(child other) {
    using std::swap;
    swap(*this, other);
    return *this;
}

int child::prop_1() const {
    return prop_1_;
}

void child::prop_1(const int v) {
    prop_1_ = v;
}

} } }
