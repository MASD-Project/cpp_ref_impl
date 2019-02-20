[![Licence](https://img.shields.io/badge/license-GPL_3-green.svg?dummy)](https://raw.githubusercontent.com/MASD-Project/cpp_ref_impl/master/LICENCE)
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2FMASD-Project%2Fcpp_ref_impl.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2FMASD-Project%2Fcpp_ref_impl?ref=badge_shield)
[![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)](https://github.com/MASD-Project/cpp_ref_impl/pulse/monthly)
[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/MASD-Project/Lobby)
[![Issues](https://img.shields.io/github/issues/MASD-Project/cpp_ref_impl.svg)](https://github.com/MASD-Project/cpp_ref_impl/issues)
[![Code Quality: Cpp](https://img.shields.io/lgtm/grade/cpp/g/MASD-Project/cpp_ref_impl.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/MASD-Project/cpp_ref_impl/context:cpp)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/5d998ea32f27479392c2c7b2309bd84a)](https://www.codacy.com/app/marco-craveiro/cpp_ref_impl?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=MASD-Project/cpp_ref_impl&amp;utm_campaign=Badge_Grade)
[![Build Dashboard](https://img.shields.io/badge/cdash-dashboard-00cc00.svg)](https://my.cdash.org/index.php?project=MASD+Project+-+C%2B%2B+Reference+Implementation)
[![Build Status](https://travis-ci.org/MASD-Project/cpp_ref_impl.svg?branch=master)](https://travis-ci.org/MASD-Project/cpp_ref_impl)
[![Build Status](https://img.shields.io/appveyor/ci/mcraveiro/cpp-ref-impl.svg?label=windows)](https://ci.appveyor.com/project/mcraveiro/cpp-ref-impl)
[![Coverage Status](https://coveralls.io/repos/github/MASD-Project/cpp_ref_impl/badge.svg?branch=master)](https://coveralls.io/github/MASD-Project/cpp_ref_impl?branch=master)
[![codecov](https://codecov.io/gh/MASD-Project/cpp_ref_impl/branch/master/graph/badge.svg)](https://codecov.io/gh/MASD-Project/cpp_ref_impl)
[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://www.openhub.net/p/dogen/analyses/latest/languages_summary)
[![C++](https://img.shields.io/badge/std-C++17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![gcc-8](https://img.shields.io/badge/GCC-8-blue.svg)](https://www.gnu.org/software/gcc/gcc-8)
[![clang-7](https://img.shields.io/badge/CLANG-7-blue.svg)](http://releases.llvm.org/7.0.0/tools/clang/docs/ReleaseNotes.html)
[![msvc2017](https://img.shields.io/badge/MSVC-2017-blue.svg)](https://visualstudio.microsoft.com/vs/whatsnew/)

# MASD C++ Reference Implementation

This project contains the MASD C++ Reference Implementation, generated
using the [latest version of
Dogen](https://github.com/MASD-Project/dogen/releases). The objective
of a MASD reference implementation is to exercise all of the available
functionality within Dogen and to unit test it to ensure it works as
specified. The models used to generate the reference implementation
are available under
[projects/models](https://github.com/MASD-Project/cpp_ref_impl/tree/master/projects/models). As
the objective of the reference implementation is to exercise Dogen as
much as possible, the models are available in both Dia and JSON
formats.

# Building

In order to build the MASD C++ Reference Implementation you will need
a C++ toolchain. On Linux and OSX, you'll need a recent compiler with
C++ 17 support, such as [GCC
8](https://www.gnu.org/software/gcc/gcc-8) or [Clang
7](https://img.shields.io/badge/CLANG-7-cyan.svg) - and
[Ninja](https://ninja-build.org/manual.html) or [GNU
Make](https://www.gnu.org/software/make/). On Windows you'll need
[Visual Studio
2017](https://visualstudio.microsoft.com/vs/whatsnew/). Older
compilers may work, but we try to always use the most recent releases
in MASD. So, if you can, please try using to those.

MASD C++ Reference Implementation has the following additional
dependencies, across all operative systems:

| Name   | Type      | Version                | Description                             |
|--------|-----------|------------------------|-----------------------------------------|
| [CMake](https://cmake.org/)  | Mandatory | 3.12 or later.  | Required to generate the build files. Earlier versions may also work.  |
| [Boost](https://boost.org)  | Mandatory | 1.61 or later. | Earlier versions may also work, but patches may be required. **Very Important**: We link statically against Boost at present, so be sure to build and install the static libraries.|
| [LibXml2](http://xmlsoft.org/) | Mandatory | 2.9.4 | Earlier versions may work but haven't been tested.|
| [ODB](https://www.codesynthesis.com/products/odb/) | Optional | 2.5.0 | Required to build the ORM test model. Note that ODB 2.5 is a beta version. |

Though the C++ Reference Implementation should build fine with package
manager supplied libraries - or even with hand-built dependencies -
the easiest way to setup a development environment on all supported
platforms is by using [vcpkg](https://github.com/Microsoft/vcpkg). We
have a vcpkg fork with a [MASD
Branch](https://github.com/MASD-Project/vcpkg/commits/masd) that is
setup correctly to build both Dogen and the C++ Reference
Implementation and is used/validated by our CI. If at all possible,
please use this instead of the mainline vcpkg because it contains a
few changes that cannot be easily mainlined (C++ 17 on all
dependencies, ODB 2.5, etc).

Either way, you can compile vcpkg as per [vcpkg
documentation](https://github.com/Microsoft/vcpkg/blob/master/README.md),
and then install packages by running:

```
./vcpkg install boost-system boost-serialization boost-date-time boost-log boost-filesystem boost-program-options boost-test libodb libodb-pgsql libodb-sqlite cpp-redis
```

---
**Notes**

- The default vcpkg triplet on windows [is 32-bit
dynamic](https://github.com/Microsoft/vcpkg/issues/1254) whereas we
build with ```--triplet x64-windows-static```. If you are experiencing
[weird and wonderful build
errors](https://github.com/Microsoft/vcpkg/issues/4447), check your
triplet.
- If you are on OSX, you probably should rely on the system's LibXML2
(e.g. remove it from the vpkg list above) or else you may see [some
interesting linking
errors](https://github.com/Microsoft/vcpkg/issues/4476) related to ```iconv```.
- Remember that the recommended compiler for OSX is Homebrew's GCC. If
you do decide to use Clang, beware that for some reason [boost does
not
default](https://github.com/Microsoft/vcpkg/issues/4476#issuecomment-430175834)
to C++ 14. You'll need to add ```cxxstd=14```.
- You can skip the ODB libs (e.g. ```libodb libodb-pgsql
libodb-sqlite```) if you are not targeting ORM support. **Very
important**: vcpkg at present only has ODB 2.4 support, but our test
project requires ODB 2.5 because it uses C++ 17 features. If you are
using mainline vcpkg, please have a look at the patches in the [MASD
Branch](https://github.com/MASD-Project/vcpkg/commits/masd) of our
vcpkg fork.

---

Once you have all dependencies set up, you can then clone the
repository and create the build directory:

```
git clone https://github.com/MASD-Project/cpp_ref_impl.git
cd cpp_ref_impl/build
mkdir output
cd output
```

On Linux and OSX, you can build using GNU Make as follows:

```
cmake -DCMAKE_TOOLCHAIN_FILE=${PATH_TO_VCPKG_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake ../..
make -j${CORES}
```

Where ```PATH_TO_VCPKG_DIR``` is the directory in which you've
downloaded and built vcpkg and ```CORES``` is the number of cores
available on your machine. Alternatively, you can use Ninja:

```
cmake -DCMAKE_TOOLCHAIN_FILE=${PATH_TO_VCPKG_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake ../.. -G Ninja
ninja -j${CORES}
```

On Windows, the incantation is slightly different:

```
cmake -DCMAKE_TOOLCHAIN_FILE=${PATH_TO_VCPKG_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake ../.. -DCMAKE_BUILD_TYPE=Release -G 'Visual Studio 14 2015 Win64'
cmake --build . --config Release --target ALL_BUILD
```

---
**Notes**

On all platforms, if you are **not** using vcpkg, you can omit
```-DCMAKE_TOOLCHAIN_FILE```. However if the dependencies are not on
the standard paths, you must then set ```CMAKE_INCLUDE_PATH``` and ```CMAKE_LIBRARY_PATH```
accordingly, e.g.:

```
CMAKE_INCLUDE_PATH=/my/boost/include/path CMAKE_LIBRARY_PATH=/my/boost/lib/path cmake ../..
```

---

## Running Tests

If you'd like to run the project tests, execute the target
```run_all_tests``` or its abbreviation ```rat```.

## Regenerating Models

If you'd like to run Dogen to regenerate all models, you can do so by
using the target ```generate_all``` or its abbreviation ```ga```. This is
useful, for example, to update the Reference Implementation to the
latest version of Dogen, or just to see how Dogen works. However, note
that Dogen must be on the path for the target to become available. If you
installed Dogen via a package, it's probably already in the right
location. If not, you need to tell CMake of its location by setting
```CMAKE_PROGRAM_PATH```:

```
CMAKE_PROGRAM_PATH=/path/to/dogen/binary cmake ../..
```

After regeneration, you can then use ```git diff``` to inspect the
differences produced by regeneration, if any. The build directory
contains all of the logs, under the directory ```log```.

If you'd like to regenerate ODB code, you can use the target
```odb_all``` or the abbreviated target ```oa```. Note that

# Test Models

The Reference Implementation is composed of a number of test
models. These can be summarised as follows:

| Name                    | Description                                        |
|-------------------------|----------------------------------------------------|
| boost_model             | Tests for all of the supported Boost types.        |
| compressed              | Uses a compressed Dia diagram as input.            |
| cpp_98                  | Model in C++ 98. All other models are in C++ 17.   |
| cpp_model               | Model testing core C++ language features.          |
| std_model               | Model exercising types from Standard Library.      |
| directory_settings      | Exercises all file and directory settings in MASD. |
| disable_cmakelists      | Model without CMake support.                       |
| disable_facet_folders   | Model without folders for facets (flat directory)  |
| enable_facet_*          | Models exercising single facets.                   |
| lam_model               | Language Agnostic Model targeting C++.             |
| northwind               | ODB test model based on Microsoft's Northwind      |
| split_project           | Project with multiple roots.                       |
| two_layers_with_objects | Model with multiple layers in Dia.                 |

The objective of this project is to ensure these models compile. In
addition, a set of model specific tests is present in
```test_model_sanitizer```, which exercises functionality such as
serialisation, IO etc.

# Reporting Problems

If you have found any issues with the generated C++ code, we ask you
to please report it in order to make the code generator
better. Examples of issues with the generated code:

- it may be using non-idiomatic C++, or following old idioms;
- it may work, but you know of a better way of doing it;
- it is just wrong, and we've missed it.

Issues can be submitted using [github
Issues](https://github.com/MASD-Project/cpp_ref_impl/issues).
