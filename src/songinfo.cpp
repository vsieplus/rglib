#include "rglib/songinfo.h"

#include "rglib/constants.h"

#include <fstream>

namespace rglib {

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

bool SongInfo::loadFromJSON(fs::path filepath) {
    try {
        std::ifstream fp(filepath);
        json j = json::parse(fp);
        from_json(j, *this);
    } catch (const std::ifstream::failure& e) {
        return false;
    }

return true;
}

bool SongInfo::loadFromINI(fs::path filepath) {
    inipp::Ini<char> ini;
    try {
        std::ifstream fp(filepath);
        ini.parse(fp);
    } catch (const std::ifstream::failure& e) {
        return false;
    }

    inipp::get_value(ini.sections["SongInfo"], constants::OFFSET_KEY, offsetMS);
    inipp::get_value(ini.sections["SongInfo"], constants::PREVIEW_START_KEY, previewStart);
    inipp::get_value(ini.sections["SongInfo"], constants::PREVIEW_STOP_KEY, previewStop);
    inipp::get_value(ini.sections["SongInfo"], constants::TITLE_KEY, title);
    inipp::get_value(ini.sections["SongInfo"], constants::ARTIST_KEY, artist);
    inipp::get_value(ini.sections["SongInfo"], constants::GENRE_KEY, genre);
    inipp::get_value(ini.sections["SongInfo"], constants::MUSIC_FILEPATH_KEY, musicFilepath);
    inipp::get_value(ini.sections["SongInfo"], constants::ART_FILEPATH_KEY, artFilepath);
    
    return true;
}

void SongInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {
    fs::path savePath { saveDir / filename };

    switch(songinfoFormat) {
    case FileFormat::JSON:  break;
    case FileFormat::INI:   savePath.replace_extension(".ini"); break;
    default:                break;
    }
}

void to_json(json& j, const SongInfo& ti) {
    j[constants::OFFSET_KEY] = ti.offsetMS;
    j[constants::PREVIEW_START_KEY] = ti.previewStart;
    j[constants::PREVIEW_STOP_KEY] = ti.previewStop;
    j[constants::TITLE_KEY] = ti.title;
    j[constants::ARTIST_KEY] = ti.artist;
    j[constants::GENRE_KEY] = ti.genre;
    j[constants::MUSIC_FILEPATH_KEY] = ti.musicFilepath;
    j[constants::ART_FILEPATH_KEY] = ti.artFilepath;
}

void from_json(const json& j, SongInfo& ti) {
    ti.offsetMS = j.value(constants::OFFSET_KEY, 0);
    ti.previewStart = j.value(constants::PREVIEW_START_KEY, 0.0);
    ti.previewStop = j.value(constants::PREVIEW_STOP_KEY, 0.0);
    ti.title = j.value(constants::TITLE_KEY, "");
    ti.artist = j.value(constants::ARTIST_KEY, "");
    ti.genre = j.value(constants::GENRE_KEY, "");
    ti.musicFilepath = j.value(constants::MUSIC_FILEPATH_KEY, "");
    ti.artFilepath = j.value(constants::ART_FILEPATH_KEY, "");
}

} // rglib
