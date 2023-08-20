#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/constants.h>
#include <rglib/songinfo.h>

namespace rglibtest {

constexpr double previewStart{ 0.0 };
constexpr double previewStop{ 15.0 };
const std::string title{ "Brain Power" };
const std::string artist{ "NOMA" };
const std::string genre{ "Hardcore" };
const std::string musicFilepath{ "brainpower.ogg" };
const std::string artFilepath{ "brainpower.png" };
const fs::path songInfoINIPath{ "data/songinfo.ini" };
const fs::path songInfoJSONPath{ "data/songinfo.json" };

TEST_CASE("SongInfo manual constructor", "[songinfo]") {
    rglib::SongInfo s{ previewStart, previewStop, title, artist, genre, musicFilepath, artFilepath };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

TEST_CASE("SongInfo default JSON parser", "[songinfo]") {
    rglib::SongInfo s{ songInfoJSONPath, rglib::SongInfo::FileFormat::JSON };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

TEST_CASE("SongInfo default INI parser", "[songinfo]") {
    rglib::SongInfo s{ songInfoINIPath, rglib::SongInfo::FileFormat::INI };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

} // rglibtest
