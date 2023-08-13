#include "rglib/songinfo.hpp"

namespace rglib {

SongInfo::SongInfo(fs::path filepath, FileFormat songinfoFormat) {
    switch (songinfoFormat) {
    case FileFormat::INI:
        break;
    case FileFormat::JSON:
        break;
    default:
        break;
    }
}

void SongInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {

}

} // rglib
