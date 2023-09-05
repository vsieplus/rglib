#ifndef SONGINFO_H
#define SONGINFO_H

#include "rglib/fileformat.h"

#include <filesystem>
namespace fs = std::filesystem;
#include <string>

#include <inipp/inipp.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace rglib {

struct SongInfo {
    SongInfo() = default;
    SongInfo(int offsetMS, double previewStart, double previewStop, std::string_view title,
        std::string_view artist, std::string_view genre, fs::path musicFilepath, fs::path artFilepath);

    void loadFromINI(inipp::Ini<char>& ini);

    virtual void save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat);

    // MS from the start of the audio file to the first beat
    int offsetMS{};

    double previewStart{};
    double previewStop{};

    std::string title{};
    std::string artist{};
    std::string genre{};

    fs::path musicFilepath{};
    fs::path artFilepath{};
};

void to_json(json& j, const SongInfo& ti);
void from_json(const json& j, SongInfo& ti);

} // rglib

#endif // SONGINFO_H
