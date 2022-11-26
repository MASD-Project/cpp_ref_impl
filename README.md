[![Licence](https://img.shields.io/badge/license-GPL_3-green.svg?dummy)](https://raw.githubusercontent.com/MASD-Project/cpp_ref_impl/master/LICENCE)
[![FOSSA Status](https://app.fossa.io/api/projects/git%2Bgithub.com%2FMASD-Project%2Fcpp_ref_impl.svg?type=shield)](https://app.fossa.io/projects/git%2Bgithub.com%2FMASD-Project%2Fcpp_ref_impl?ref=badge_shield)
[![Status](https://img.shields.io/badge/status-active-brightgreen.svg?style=flat)](https://github.com/MASD-Project/cpp_ref_impl/pulse/monthly)
[![Gitter](https://img.shields.io/gitter/room/nwjs/nw.js.svg)](https://gitter.im/MASD-Project/Lobby)
[![Issues](https://img.shields.io/github/issues/MASD-Project/cpp_ref_impl.svg)](https://github.com/MASD-Project/cpp_ref_impl/issues)
[![Code Quality:
Cpp](https://img.shields.io/lgtm/grade/cpp/g/MASD-Project/cpp_ref_impl.svg?logo=lgtm&logoWidth=18)](https://lgtm.com/projects/g/MASD-Project/cpp_ref_impl/context:cpp)
[![Continuous Linux](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-linux.yml/badge.svg)](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-linux.yml)
[![Continuous Windows](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-windows.yml/badge.svg)](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-windows.yml)
[![Continuous MacOS](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-macos.yml/badge.svg)](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/continuous-macos.yml)
[![Nightly Build](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/nightly-linux.yml/badge.svg)](https://github.com/MASD-Project/cpp_ref_impl/actions/workflows/nightly-linux.yml)
[![Build Dashboard](https://img.shields.io/badge/cdash-dashboard-00cc00.svg)](https://my.cdash.org/index.php?project=MASD+Project+-+C%2B%2B+Reference+Implementation)
[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://www.openhub.net/p/dogen/analyses/latest/languages_summary)
[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://www.openhub.net/p/dogen/analyses/latest/languages_summary)
[![C++](https://img.shields.io/badge/std-C++17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![gcc-11](https://img.shields.io/badge/GCC-11-blue.svg)](https://www.gnu.org/software/gcc/gcc-11)
[![clang-14](https://img.shields.io/badge/CLANG-14-blue.svg)](https://releases.llvm.org/14.0.0/tools/clang/docs/ReleaseNotes.html)
[![msvc2022](https://img.shields.io/badge/MSVC-2022-blue.svg)](https://visualstudio.microsoft.com/vs/whatsnew/)
[![TODOs](https://badgen.net/https/api.tickgit.com/badgen/github.com/MASD-Project/cpp_ref_impl)](https://www.tickgit.com/browse?repo=github.com/MASD-Project/cpp_ref_impl)

# MASD C++ Reference Implementation

This project contains the MASD C++ Reference Implementation, generated using the
[latest version of Dogen](https://github.com/MASD-Project/dogen/releases). The
objective of a MASD reference implementation is to exercise all of the available
functionality within Dogen and to unit test it to ensure it works as specified.
The models used to generate the reference implementation are available under
[projects/models](https://github.com/MASD-Project/cpp_ref_impl/tree/master/projects/models).
As the objective of the reference implementation is to exercise Dogen as much as
possible, the models are available in both Dia and JSON formats.

# Building From Source

By design, the steps to build the MASD C++ product reference implementation from
source are exactly the same as those of
[Dogen](https://github.com/MASD-Project/dogen/releases).

## Running Tests

If you'd like to run the project tests, execute the target ```run_all_tests```
or its abbreviation ```rat```.

## Regenerating Models

If you'd like to run Dogen to regenerate all models, you can do so by using the
target ```generate_all_dia``` or its abbreviation ```gad```. This is useful, for
example, to update the Reference Implementation to the latest version of Dogen,
or just to see how Dogen works. However, note that Dogen must be on the path for
the target to become available. If you installed Dogen via a package, it's
probably already in the right location. If not, you need to tell CMake of its
location by setting ```CMAKE_PROGRAM_PATH```:

```
CMAKE_PROGRAM_PATH=/path/to/dogen/binary cmake ../..
```

After regeneration, you can then use ```git diff``` to inspect the differences
produced by regeneration, if any. The build directory contains all of the logs,
under the directory ```log```.

If you'd like to regenerate ODB code, you can use the target ```odb_all``` or
the abbreviated target ```oa```. Note that

# Test Models

The Reference Implementation is composed of a number of test models. These can
be summarised as follows:

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

The objective of this project is to ensure these models compile. In addition, a
set of model specific tests is present in ```test_model_sanitizer```, which
exercises functionality such as serialisation, IO etc.

# Reporting Problems

If you have found any issues with the generated C++ code, we ask you to please
report it in order to make the code generator better. Examples of issues with
the generated code:

- it may be using non-idiomatic C++, or following old idioms;
- it may work, but you know of a better way of doing it;
- it is just wrong, and we've missed it.

Issues can be submitted using [github
Issues](https://github.com/MASD-Project/cpp_ref_impl/issues).
