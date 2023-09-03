#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/constants.h>
#include <rglib/songinfo.h>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>
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

    REQUIRE_THAT(s.previewStart, Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.previewStop, Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.offsetMS == offsetMS);
    REQUIRE(s.title == title);
    REQUIRE(s.artist == artist);
    REQUIRE(s.genre == genre);
    REQUIRE(s.musicFilepath == musicFilepath);
    REQUIRE(s.artFilepath == artFilepath);
}

TEST_CASE("SongInfo default JSON parser", "[songinfo]") {
    rglib::SongInfo s{};

    SECTION("loadFromJSON()") {
        s.loadFromJSON(songInfoJSONPath);
    }

    SECTION("using json::get<SongInfo>()") {
        std::ifstream fp{ songInfoJSONPath };
        json j { json::parse(fp) };
        s = j.get<rglib::SongInfo>();
    };

    REQUIRE_THAT(s.previewStart, Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.previewStop, Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.offsetMS == offsetMS);
    REQUIRE(s.title == title);
    REQUIRE(s.artist == artist);
    REQUIRE(s.genre == genre);
    REQUIRE(s.musicFilepath == musicFilepath);
    REQUIRE(s.artFilepath == artFilepath);
}

TEST_CASE("SongInfo default INI parser", "[songinfo]") {
    rglib::SongInfo s{};
    s.loadFromINI(songInfoINIPath);

    REQUIRE_THAT(s.previewStart, Catch::Matchers::WithinAbs(previewStart, rglib::constants::EPSILON));
    REQUIRE_THAT(s.previewStop, Catch::Matchers::WithinAbs(previewStop, rglib::constants::EPSILON));
    REQUIRE(s.offsetMS == offsetMS);
    REQUIRE(s.title == title);
    REQUIRE(s.artist == artist);
    REQUIRE(s.genre == genre);
    REQUIRE(s.musicFilepath == musicFilepath);
    REQUIRE(s.artFilepath == artFilepath);
}

} // songinfo

} // rglibtest
