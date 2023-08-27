#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/beatpos.h>
#include <rglib/constants.h>
#include <rglib/section.h>

namespace rglibtest {

TEST_CASE("Section starting section", "[section]") {
    rglib::Section t{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    REQUIRE(t.beatsPerMeasure == 4);
    REQUIRE(t.bpm == 120);
    REQUIRE(t.beatpos == rglib::BeatPos{ 0, 0, 1 });
    REQUIRE_THAT(t.absBeatStart, Catch::Matchers::WithinAbs(0, rglib::constants::EPSILON));
    REQUIRE_THAT(t.absTimeStart, Catch::Matchers::WithinAbs(0, rglib::constants::EPSILON));
}

TEST_CASE("Section multiple sections", "[section]") {
    rglib::Section t1{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    rglib::Section t2{ 2, 240, rglib::BeatPos{ 1, 0, 1 }, &t1 };
    rglib::Section t3{ 4, 120, rglib::BeatPos{ 2, 1, 2 }, &t2 };

    REQUIRE_THAT(t2.absBeatStart, Catch::Matchers::WithinAbs(4.0, rglib::constants::EPSILON));
    REQUIRE_THAT(t2.absTimeStart, Catch::Matchers::WithinAbs(2.0, rglib::constants::EPSILON));

    REQUIRE_THAT(t3.absBeatStart, Catch::Matchers::WithinAbs(7.0, rglib::constants::EPSILON));
    REQUIRE_THAT(t3.absTimeStart, Catch::Matchers::WithinAbs(2.75, rglib::constants::EPSILON));
}

TEST_CASE("Section operator<", "[section]") {
    rglib::Section t1{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    rglib::Section t2{ 2, 240, rglib::BeatPos{ 1, 0, 1 }, &t1 };

    REQUIRE(t1 < t2);
}

} // rglibtest
