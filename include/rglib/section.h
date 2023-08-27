#ifndef SECTION_H
#define SECTION_H

#include "beatpos.h"

#include <ostream>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace rglib {

// Time signature/tempo information for a given section of a song
struct Section {
    Section() = default;
    Section(int beatsPerMeasure, double bpm, BeatPos beatpos, Section* prevSection);

    int beatsPerMeasure {};

    double bpm {};

    BeatPos beatpos {};

    double absBeatStart {};
    double absTimeStart {};    // in seconds
};

void to_json(json& j, const Section& ti);
void from_json(const json& j, Section& ti);

bool operator<(const Section& lhs, const Section& rhs);

} // rglib

#endif // SECTION_H
