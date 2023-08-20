#include "rglib/timeinfo.h"

#include "rglib/constants.h"

namespace rglib {

double calculateBeatStart(int beatsPerMeasure, BeatPos beatpos, TimeInfo* prevTimeinfo) {
    auto absMeasure = beatpos.measure + (beatpos.split / (float)beatpos.measureSplit);

    if (!prevTimeinfo) {
        return absMeasure * beatsPerMeasure;
    } else {
        auto prevAbsMeasure = prevTimeinfo->beatpos.measure + ((double)prevTimeinfo->beatpos.split / prevTimeinfo->beatpos.measureSplit);
        auto absMeasureDiff = absMeasure - prevAbsMeasure;

        return prevTimeinfo->absBeatStart + (absMeasureDiff * prevTimeinfo->beatsPerMeasure);
    }
}

double calculateTimeStart(double absBeatStart, BeatPos beatpos, TimeInfo* prevTimeinfo) {
    if (!prevTimeinfo) {
        return 0.f;
    } else {
        auto prevSectionBeatLength = absBeatStart - prevTimeinfo->absBeatStart;
        return prevTimeinfo->absTimeStart + prevSectionBeatLength * (constants::SECONDS_PER_MINUTE / prevTimeinfo->bpm);
    }
}

TimeInfo::TimeInfo(int beatsPerMeasure, double bpm, BeatPos beatpos, TimeInfo* prevTimeInfo)
    : beatsPerMeasure{ beatsPerMeasure }
    , bpm{ bpm }
    , beatpos{ beatpos }
    , absBeatStart{ calculateBeatStart(beatsPerMeasure, beatpos, prevTimeInfo) }
    , absTimeStart{ calculateTimeStart(absBeatStart, beatpos, prevTimeInfo) }
{}

bool operator<(const TimeInfo& lhs, const TimeInfo& rhs) {
    return lhs.beatpos < rhs.beatpos;
}

} // rglib
