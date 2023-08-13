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

SongInfo::SongInfo(float previewStart, float previewStop, std::string_view title, std::string_view artist,
    std::string_view genre, fs::path musicFilepath, fs::path artFilepath)
    : previewStart{ previewStart }
    , previewStop{ previewStop }
    , title{ title }
    , artist{ artist }
    , genre{ genre }
    , musicFilepath{ musicFilepath }
    , artFilepath{ artFilepath }
{
}


void SongInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {

}

} // rglib
