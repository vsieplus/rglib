#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

#include <rglib/constants.h>
#include <rglib/sequenceitem.h>
#include <rglib/timeinfo.h>

namespace rglibtest {

TEST_CASE("SequenceItem basic constructor", "[sequenceitem]") {
    rglib::SequenceItem s{ 0.0, 0.0 };

    REQUIRE_THAT(s.absBeat, Catch::Matchers::WithinAbs(0.0, rglib::constants::EPSILON));
    REQUIRE_THAT(s.absTime, Catch::Matchers::WithinAbs(0.0, rglib::constants::EPSILON));
}

TEST_CASE("SequenceItem with beatpos", "[sequenceitem]") {
    rglib::TimeInfo t1 { 4, 120, rglib::BeatPos{ 0, 0, 1 }, nullptr };
    rglib::TimeInfo t2 { 4, 60, rglib::BeatPos{ 1, 0, 1 }, &t1 };

    std::vector<rglib::TimeInfo> sections { t1, t2 };

    rglib::SequenceItem s1{ rglib::BeatPos{ 1, 0, 1 }, sections };
    rglib::SequenceItem s2{ rglib::BeatPos{ 0, 1, 2 }, sections };
    rglib::SequenceItem s3{ rglib::BeatPos{ 1, 1, 2 }, sections };

    SECTION("Beatpos constructor") {
        REQUIRE(s1.beatpos == rglib::BeatPos{ 1, 0, 1 });
        REQUIRE_THAT(s1.absBeat, Catch::Matchers::WithinAbs(4.0, rglib::constants::EPSILON));
        REQUIRE_THAT(s1.absTime, Catch::Matchers::WithinAbs(2.0, rglib::constants::EPSILON));

        REQUIRE(s2.beatpos == rglib::BeatPos{ 0, 1, 2 });
        REQUIRE_THAT(s2.absBeat, Catch::Matchers::WithinAbs(2.0, rglib::constants::EPSILON));
        REQUIRE_THAT(s2.absTime, Catch::Matchers::WithinAbs(1.0, rglib::constants::EPSILON));

        REQUIRE(s3.beatpos == rglib::BeatPos{ 1, 1, 2 });
        REQUIRE_THAT(s3.absBeat, Catch::Matchers::WithinAbs(6.0, rglib::constants::EPSILON));
        REQUIRE_THAT(s3.absTime, Catch::Matchers::WithinAbs(4.0, rglib::constants::EPSILON));
    }

    SECTION("operator<") {
        REQUIRE(s2 < s3);
        REQUIRE(s2 < s1);
        REQUIRE(s1 < s3);
    }
}

} // rglibtest
