#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "cpp_ref_impl/cpp_98/serialization/child_ser.hpp"
#include "cpp_ref_impl/cpp_98/serialization/parent_ser.hpp"

BOOST_CLASS_TRACKING(
    cpp_ref_impl::cpp_98::child,
    boost::serialization::track_selectively)

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const cpp_ref_impl::cpp_98::child& v,
    const unsigned int /*version*/) {
    ar << make_nvp("parent", base_object<cpp_ref_impl::cpp_98::parent>(v));

    ar << make_nvp("prop_1", v.prop_1_);
}

template<typename Archive>
void load(Archive& ar,
    cpp_ref_impl::cpp_98::child& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("parent", base_object<cpp_ref_impl::cpp_98::parent>(v));

    ar >> make_nvp("prop_1", v.prop_1_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const cpp_ref_impl::cpp_98::child& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, cpp_ref_impl::cpp_98::child& v, unsigned int version);

template void save(archive::text_oarchive& ar, const cpp_ref_impl::cpp_98::child& v, unsigned int version);
template void load(archive::text_iarchive& ar, cpp_ref_impl::cpp_98::child& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const cpp_ref_impl::cpp_98::child& v, unsigned int version);
template void load(archive::binary_iarchive& ar, cpp_ref_impl::cpp_98::child& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const cpp_ref_impl::cpp_98::child& v, unsigned int version);
template void load(archive::xml_iarchive& ar, cpp_ref_impl::cpp_98::child& v, unsigned int version);

} }
