# rglib

[![Windows build](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-windows-release.yml)
[![Linux build](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-linux-release.yml)
[![MacOS build](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml/badge.svg)](https://github.com/vsieplus/rglib/actions/workflows/cmake-macos-release.yml)

**rglib** is a simple C++ library for rhythm game development, providing functionality for common tasks such as:

* Parsing song and chart files
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

## Examples

### Parsing a chart file

```json
{
    "title": "Brain Power",
    "artist": "NOMA",
    "genre": "Hardcore",
    "music": "brainpower.ogg",
    "art": "brainpower.png",
    "musicPreviewStart": 0.0,
    "musicPreviewStop": 15.0,
    "offset": 5
}

```

```cpp
#include <rglib/rglib.h

// ...

std::ifstream fp{ "songinfo.json" };
json j = json::parse(fp);
rglib::SongInfo songinfo{ j.get<rglib::SongInfo>() };

std::cout << "Title: " << songinfo.title << "\n";
std::cout << "Artist: " << songinfo.artist << "\n";
std::cout << "Genre: " << songinfo.genre << "\n";
std::cout << "Offset: " << songinfo.offsetMS << "\n";
std::cout << "Music Preview start: " << songinfo.previewStart << "\n";
std::cout << "Music Preview stop: " << songinfo.previewStop << "\n";
std::cout << "Music filepath: " << songinfo.musicFilepath << "\n";
std::cout << "Art filepath: " << songinfo.artFilepath << "\n";
```
