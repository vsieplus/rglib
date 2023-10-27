# rglib

[![Windows build](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml)
[![Linux build](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml)
[![MacOS build](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml)

**rglib** is a simple C++ library for rhythm game development, providing functionality for common tasks such as:

* Parsing chart files
* Calculating accurate note timings from tempo information
* Tracking and updating song position in both time and beats

## Building and Installing

**rglib** can be built using [CMake](https://cmake.org/):

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

By default only static libraries are built. To build shared libraries, you can use this instead:

```bash
cmake .. -DBUILD_SHARED_LIBS=1
```

You can refer to the [CMake documentation](https://cmake.org/cmake/help/latest/manual/cmake.1.html) for other customizable options. If you wish, you can install the libraries locally using:

```bash
sudo cmake --install .
```
