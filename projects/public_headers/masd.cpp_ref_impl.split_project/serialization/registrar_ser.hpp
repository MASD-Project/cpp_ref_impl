#ifndef MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_REGISTRAR_SER_HPP
#define MASD_CPP_REF_IMPL_SPLIT_PROJECT_SERIALIZATION_REGISTRAR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace masd::cpp_ref_impl::split_project {

template<typename Archive>
void register_types(Archive& ar);

}

#endif