#ifndef CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_REGISTRAR_SER_HPP
#define CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_REGISTRAR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace cpp_ref_impl {
namespace split_project {

template<typename Archive>
void register_types(Archive& ar);

} }

#endif
