#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/beatpos.h>
#include <rglib/constants.h>
#include <rglib/chartinfo.h>

#include <string_view>

namespace rglibtest {

namespace chartinfo {

constexpr int level{ 1 };
constexpr std::string_view author{ "abc" };
constexpr std::string_view difficulty{ "Easy" };

const fs::path chartPath{ "data/chartinfo.json" };

TEST_CASE("Chartinfo manual constructor", "[chartinfo]") {
    rglib::ChartInfo c{ level, author, difficulty };

    REQUIRE(c.getLevel() == level);
    REQUIRE(c.getAuthor() == author);
    REQUIRE(c.getDifficulty() == difficulty);
}

TEST_CASE("ChartInfo default JSON parser", "[chartinfo]") {
    rglib::ChartInfo c{ chartPath, rglib::FileFormat::JSON };

    REQUIRE(c.getLevel() == level);
    REQUIRE(c.getAuthor() == author);
    REQUIRE(c.getDifficulty() == difficulty);

    const auto& sections = c.getTimeInfo();
    REQUIRE(sections.size() == 3);

    REQUIRE(sections[0].bpm == 120);
    REQUIRE(sections[0].beatsPerMeasure == 4);
    REQUIRE(sections[0].beatpos == rglib::BeatPos{ 0, 0, 1 });
    REQUIRE_THAT(sections[0].absTimeStart, Catch::Matchers::WithinAbs(0.0, rglib::constants::EPSILON));
    REQUIRE_THAT(sections[0].absBeatStart, Catch::Matchers::WithinAbs(0.0, rglib::constants::EPSILON));

    REQUIRE(sections[1].bpm == 160);
    REQUIRE(sections[1].beatsPerMeasure == 2);
    REQUIRE(sections[1].beatpos == rglib::BeatPos{ 1, 0, 1 });
    REQUIRE_THAT(sections[1].absTimeStart, Catch::Matchers::WithinAbs(2.0, rglib::constants::EPSILON));
    REQUIRE_THAT(sections[1].absBeatStart, Catch::Matchers::WithinAbs(4.0, rglib::constants::EPSILON));

    REQUIRE(sections[2].bpm == 90);
    REQUIRE(sections[2].beatsPerMeasure == 3);
    REQUIRE(sections[2].beatpos == rglib::BeatPos{ 2, 0, 1 });
    REQUIRE_THAT(sections[2].absTimeStart, Catch::Matchers::WithinAbs(2.75, rglib::constants::EPSILON));
    REQUIRE_THAT(sections[2].absBeatStart, Catch::Matchers::WithinAbs(6.0, rglib::constants::EPSILON));
}

} // chartinfo

} // rglibtest
