#ifndef SONGINFO_H
#define SONGINFO_H

#include <filesystem>
namespace fs = std::filesystem;

#include <string>

namespace rglib {

struct SongInfo {
    enum class FileFormat{
        INI,
        JSON,
        UNKNOWN,
    };

    SongInfo(fs::path filepath, FileFormat songinfoFormat);
    SongInfo(float previewStart, float previewStop, std::string_view title, std::string_view artist,
        std::string_view genre, fs::path musicFilepath, fs::path artFilepath);

    void save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat);

    float previewStart{};
    float previewStop{};

    std::string title{};
    std::string artist{};
    std::string genre{};

    fs::path musicFilepath{};
    fs::path artFilepath{};
};

} // rglib

#endif // SONGINFO_H
