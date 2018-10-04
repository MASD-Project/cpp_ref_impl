[![Licence](https://img.shields.io/badge/license-GPL_3-green.svg?dummy)](https://raw.githubusercontent.com/MASD-Project/cpp_ref_impl/master/LICENCE)
[![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)](https://github.com/MASD-Project/cpp_ref_impl/pulse/monthly)
[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/MASD-Project/Lobby)
[![Build Status](https://travis-ci.org/MASD-Project/cpp_ref_impl.svg?branch=master)](https://travis-ci.org/MASD-Project/cpp_ref_impl)
[![Build Status](https://img.shields.io/appveyor/ci/mcraveiro/cpp-ref-impl.svg?label=windows)](https://ci.appveyor.com/project/mcraveiro/cpp-ref-impl)
[![codecov](https://codecov.io/gh/MASD-Project/cpp_ref_impl/branch/master/graph/badge.svg)](https://codecov.io/gh/MASD-Project/cpp_ref_impl)

# MASD C++ Reference Implementation

This project contains the MASD C++ Reference Implementation, generated
using [Dogen
v1.0.08](https://github.com/MASD-Project/dogen/releases/tag/v1.0.08). The
objective of a MASD reference implementation is to exercise all of the
available functionality within Dogen and to unit test it to ensure it
works as specified. The models used to generate the reference
implementation are available under
[projects/models](https://github.com/MASD-Project/cpp_ref_impl/tree/master/projects/models). As
the objective of the reference implementation is to exercise Dogen as
much as possible, the models are available in both Dia and JSON
formats.

# Reporting Problems

If you have found any issues with the generated C++ code, we ask you
to please report it in order to make the code generator
better. Examples of issues with the generated code:

- it may be using non-idiomatic C++, or following old idioms;
- it may work, but you know of a better way of doing it;
- it is just wrong, and we've missed it.

Issues can be submitted using [github
Issues](https://github.com/MASD-Project/cpp_ref_impl/issues).
