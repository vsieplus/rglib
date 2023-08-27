#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/constants.h>
#include <rglib/songinfo.h>

#include <string_view>

namespace rglibtest {

namespace songinfo {

constexpr int offsetMS{ 5 };
constexpr double previewStart{ 0.0 };
constexpr double previewStop{ 15.0 };
constexpr std::string_view title{ "Brain Power" };
constexpr std::string_view artist{ "NOMA" };
constexpr std::string_view genre{ "Hardcore" };
const fs::path musicFilepath{ "brainpower.ogg" };
const fs::path artFilepath{ "brainpower.png" };
const fs::path songInfoINIPath{ "data/songinfo.ini" };
const fs::path songInfoJSONPath{ "data/songinfo.json" };

TEST_CASE("SongInfo manual constructor", "[songinfo]") {
    rglib::SongInfo s{ offsetMS, previewStart, previewStop, title, artist, genre, musicFilepath, artFilepath };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getOffsetMS() == offsetMS);
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

TEST_CASE("SongInfo default JSON parser", "[songinfo]") {
    rglib::SongInfo s{ songInfoJSONPath, rglib::FileFormat::JSON };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getOffsetMS() == offsetMS);
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

TEST_CASE("SongInfo default INI parser", "[songinfo]") {
    rglib::SongInfo s{ songInfoINIPath, rglib::FileFormat::INI };

    REQUIRE_THAT(s.getPreviewStart(), Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.getPreviewStop(), Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.getOffsetMS() == offsetMS);
    REQUIRE(s.getTitle() == title);
    REQUIRE(s.getArtist() == artist);
    REQUIRE(s.getGenre() == genre);
    REQUIRE(s.getMusicFilepath() == musicFilepath);
    REQUIRE(s.getArtFilepath() == artFilepath);
}

} // songinfo

} // rglibtest
