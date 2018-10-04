#include <boost/serialization/nvp.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include "cpp_ref_impl/split_project/serialization/package1/first_class_ser.hpp"

namespace boost {
namespace serialization {

template<typename Archive>
void save(Archive& ar,
    const cpp_ref_impl::split_project::package1::first_class& v,
    const unsigned int /*version*/) {
    ar << make_nvp("public_attribute", v.public_attribute_);
    ar << make_nvp("private_attribute", v.private_attribute_);
}

template<typename Archive>
void load(Archive& ar,
    cpp_ref_impl::split_project::package1::first_class& v,
    const unsigned int /*version*/) {
    ar >> make_nvp("public_attribute", v.public_attribute_);
    ar >> make_nvp("private_attribute", v.private_attribute_);
}

} }

namespace boost {
namespace serialization {

template void save(archive::polymorphic_oarchive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);
template void load(archive::polymorphic_iarchive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template void save(archive::text_oarchive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);
template void load(archive::text_iarchive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template void save(archive::binary_oarchive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);
template void load(archive::binary_iarchive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

template void save(archive::xml_oarchive& ar, const cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);
template void load(archive::xml_iarchive& ar, cpp_ref_impl::split_project::package1::first_class& v, unsigned int version);

} }
