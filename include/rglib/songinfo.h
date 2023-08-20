#ifndef SONGINFO_H
#define SONGINFO_H

#include <filesystem>
namespace fs = std::filesystem;

#include <string>

namespace rglib {

class SongInfo {
public:
    enum class FileFormat{
        INI,
        JSON,
        CUSTOM,
    };

    SongInfo(fs::path filepath, FileFormat songinfoFormat);
    SongInfo(double previewStart, double previewStop, std::string_view title, std::string_view artist,
        std::string_view genre, fs::path musicFilepath, fs::path artFilepath);

    virtual void save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat);

    double getPreviewStart() const { return previewStart; }
    double getPreviewStop() const { return previewStop; }
    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getGenre() const { return genre; }
    fs::path getMusicFilepath() const { return musicFilepath; }
    fs::path getArtFilepath() const { return artFilepath; }
protected:
    virtual void loadFromINI(fs::path filepath);
    virtual void loadFromJSON(fs::path filepath);
    virtual void loadFromCustom(fs::path filepath);
private:
    double previewStart{};
    double previewStop{};

    std::string title{};
    std::string artist{};
    std::string genre{};

    fs::path musicFilepath{};
    fs::path artFilepath{};
};

} // rglib

#endif // SONGINFO_H
