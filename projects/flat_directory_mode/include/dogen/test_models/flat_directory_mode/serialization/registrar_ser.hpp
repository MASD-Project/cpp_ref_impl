#ifndef DOGEN_TEST_MODELS_FLAT_DIRECTORY_MODE_SERIALIZATION_REGISTRAR_SER_HPP
#define DOGEN_TEST_MODELS_FLAT_DIRECTORY_MODE_SERIALIZATION_REGISTRAR_SER_HPP

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

namespace dogen {
namespace test_models {
namespace flat_directory_mode {

template<typename Archive>
void register_types(Archive& ar);

} } }

#endif
