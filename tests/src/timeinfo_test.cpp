#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/constants.h>
#include <rglib/timeinfo.h>

namespace rglibtest {

TEST_CASE("TimeInfo starting section", "[timeinfo]") {
    rglib::TimeInfo t{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    REQUIRE(t.beatsPerMeasure == 4);
    REQUIRE(t.bpm == 120);
    REQUIRE(t.beatpos == rglib::BeatPos{ 0, 0, 1 });
    REQUIRE_THAT(t.absBeatStart, Catch::Matchers::WithinAbs(0, rglib::constants::EPSILON));
    REQUIRE_THAT(t.absTimeStart, Catch::Matchers::WithinAbs(0, rglib::constants::EPSILON));
}

TEST_CASE("TimeInfo multiple sections", "[timeinfo]") {
    rglib::TimeInfo t1{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    rglib::TimeInfo t2{ 2, 240, rglib::BeatPos{ 1, 0, 1 }, &t1 };
    rglib::TimeInfo t3{ 4, 120, rglib::BeatPos{ 2, 1, 2 }, &t2 };

    REQUIRE_THAT(t2.absBeatStart, Catch::Matchers::WithinAbs(4.0, rglib::constants::EPSILON));
    REQUIRE_THAT(t2.absTimeStart, Catch::Matchers::WithinAbs(2.0, rglib::constants::EPSILON));

    REQUIRE_THAT(t3.absBeatStart, Catch::Matchers::WithinAbs(7.0, rglib::constants::EPSILON));
    REQUIRE_THAT(t3.absTimeStart, Catch::Matchers::WithinAbs(2.75, rglib::constants::EPSILON));
}

TEST_CASE("TimeInfo operator<", "[timeinfo]") {
    rglib::TimeInfo t1{ 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    rglib::TimeInfo t2{ 2, 240, rglib::BeatPos{ 1, 0, 1 }, &t1 };

    REQUIRE(t1 < t2);
}

} // rglibtest
