#ifndef CPP_REF_IMPL_FLAT_DIRECTORY_MODE_SERIALIZATION_REGISTRAR_SER_HPP
#define CPP_REF_IMPL_FLAT_DIRECTORY_MODE_SERIALIZATION_REGISTRAR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace cpp_ref_impl {
namespace flat_directory_mode {

template<typename Archive>
void register_types(Archive& ar);

} }

#endif
