# rglib

[![Windows build](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml)
[![Linux build](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml)
[![MacOS build](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml)

**rglib** is a simple C++ library for rhythm game development, providing functionality for common tasks such as:

* Parsing chart files
* Calculating event, note timings

## Building and Installing

**rglib** can be built using [CMake](https://cmake.org/):

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

By default only static libraries are built. To build shared libraries, you can append `-DBUILD_SHARED_LIBS=1` to the end of `cmake .. `. Once built, you can complete installation with

```bash
sudo cmake --install .
```

## Examples

```cpp

```

