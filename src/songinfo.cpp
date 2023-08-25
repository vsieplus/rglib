#include "rglib/songinfo.h"

#include "rglib/constants.h"

#include <inipp/inipp.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>

namespace rglib {

SongInfo::SongInfo(fs::path filepath, FileFormat songinfoFormat) {
    switch (songinfoFormat) {
    case FileFormat::INI:       loadFromINI(filepath);  break;
    case FileFormat::JSON:      loadFromJSON(filepath); break;
    case FileFormat::CUSTOM:    loadFromCustom(filepath); break;
    }
}


SongInfo::SongInfo(int offsetMS, double previewStart, double previewStop, std::string_view title,
    std::string_view artist, std::string_view genre, fs::path musicFilepath, fs::path artFilepath)
    : offsetMS { offsetMS }
    , previewStart{ previewStart }
    , previewStop{ previewStop }
    , title{ title }
    , artist{ artist }
    , genre{ genre }
    , musicFilepath{ musicFilepath }
    , artFilepath{ artFilepath }
{}

void SongInfo::loadFromINI(fs::path filepath) {
    std::ifstream fp(filepath);
    inipp::Ini<char> ini;
    ini.parse(fp);

    inipp::get_value(ini.sections["SongInfo"], constants::OFFSET_KEY, offsetMS);
    inipp::get_value(ini.sections["SongInfo"], constants::PREVIEW_START_KEY, previewStart);
    inipp::get_value(ini.sections["SongInfo"], constants::PREVIEW_STOP_KEY, previewStop);
    inipp::get_value(ini.sections["SongInfo"], constants::TITLE_KEY, title);
    inipp::get_value(ini.sections["SongInfo"], constants::ARTIST_KEY, artist);
    inipp::get_value(ini.sections["SongInfo"], constants::GENRE_KEY, genre);
    inipp::get_value(ini.sections["SongInfo"], constants::MUSIC_FILEPATH_KEY, musicFilepath);
    inipp::get_value(ini.sections["SongInfo"], constants::ART_FILEPATH_KEY, artFilepath);
}

void SongInfo::loadFromJSON(fs::path filepath) {
    std::ifstream fp(filepath);
    json j = json::parse(fp);

    offsetMS = j.value(constants::OFFSET_KEY, 0);
    previewStart = j.value(constants::PREVIEW_START_KEY, 0.0);
    previewStop = j.value(constants::PREVIEW_STOP_KEY, 0.0);
    title = j.value(constants::TITLE_KEY, "");
    artist = j.value(constants::ARTIST_KEY, "");
    genre = j.value(constants::GENRE_KEY, "");
    musicFilepath = j.value(constants::MUSIC_FILEPATH_KEY, "");
    artFilepath = j.value(constants::ART_FILEPATH_KEY, "");
}

void SongInfo::loadFromCustom(fs::path filepath) {}


void SongInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {

}

} // rglib
