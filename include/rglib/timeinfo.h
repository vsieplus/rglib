#ifndef TIMEINFO_H
#define TIMEINFO_H

#include "beatpos.h"

#include <ostream>

namespace rglib {

// Time signature/tempo information for a given section of a song
struct TimeInfo {
    TimeInfo(int beatsPerMeasure, double bpm, BeatPos beatpos, TimeInfo* prevTimeInfo);

    int beatsPerMeasure;

    double bpm;

    BeatPos beatpos;

    double absBeatStart;
    double absTimeStart;    // in seconds
};

bool operator<(const TimeInfo& lhs, const TimeInfo& rhs);

} // rglib

#endif // TIMEINFO_H
