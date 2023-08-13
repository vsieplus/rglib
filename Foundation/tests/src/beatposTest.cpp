#include <catch2/catch_test_macros.hpp>

#include <rglib/beatpos.h>
#include <rglib/songinfo.h>

namespace rglibtest {

TEST_CASE("BeatPos default constructor", "[beatpos]") {
    rglib::BeatPos b{};
    REQUIRE(b.measure == 0);
    REQUIRE(b.split == 0);
    REQUIRE(b.measureSplit == 1);
}

TEST_CASE("BeatPos comparison operators", "[beatpos]") {
    rglib::BeatPos b1{ 0, 1, 2 };
    rglib::BeatPos b2{ 0, 1, 2 };
    rglib::BeatPos b3{ 0, 2, 4 };
    rglib::BeatPos b4{ 0, 1, 3 };
    rglib::BeatPos b5{ 1, 2, 8 };

    SECTION("operator==/!=") {
        REQUIRE(b1 == b2);
        REQUIRE(b1 == b3);
        REQUIRE(b1 != b4);
        REQUIRE(b1 != b5);
    }

    SECTION("operator<") {
        REQUIRE(b4 < b1);
        REQUIRE(b3 < b5);
    }

    SECTION("operator<=") {
        REQUIRE(b1 <= b2);
        REQUIRE(b1 <= b3);
        REQUIRE(b4 <= b1);
        REQUIRE(b3 <= b5);
    }
}

TEST_CASE("BeatPos operator+/-", "[beatpos]") {
    rglib::BeatPos b1{ 0, 1, 2 };
    rglib::BeatPos b2{ 0, 1, 2 };
    rglib::BeatPos b3{ 0, 2, 4 };
    rglib::BeatPos b4{ 1, 1, 4 };

    SECTION("operator+") {
        REQUIRE(b1 + b2 == rglib::BeatPos{ 1, 0, 1 });
        REQUIRE(b1 + b3 == rglib::BeatPos{ 1, 0, 1 });
        REQUIRE(b1 + b4 == rglib::BeatPos{ 1, 3, 4 });
    }

    SECTION("operator-") {
        REQUIRE(b1 - b2 == rglib::BeatPos{ 0, 0, 1 });
        REQUIRE(b3 - b2 == rglib::BeatPos{ 0, 0, 1 });
        REQUIRE(b4 - b2 == rglib::BeatPos{ 0, 3, 4 });
    }
}

} // rglibtest
