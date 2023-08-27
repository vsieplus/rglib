#include "rglib/section.h"

#include "rglib/beatpos.h"
#include "rglib/constants.h"

namespace rglib {

double calculateBeatStart(int beatsPerMeasure, BeatPos beatpos, Section* prevSection) {
    auto absMeasure = static_cast<double>(beatpos);

    if(!prevSection) {
        return absMeasure * beatsPerMeasure;
    } else {
        auto prevAbsMeasure = static_cast<double>(prevSection->beatpos);
        auto absMeasureDiff = absMeasure - prevAbsMeasure;

        return prevSection->absBeatStart + (absMeasureDiff * prevSection->beatsPerMeasure);
    }
}

double calculateTimeStart(double absBeatStart, BeatPos beatpos, Section* prevSection) {
    if(!prevSection) {
        return 0.f;
    } else {
        auto prevSectionBeatLength = absBeatStart - prevSection->absBeatStart;
        return prevSection->absTimeStart + prevSectionBeatLength * (constants::SECONDS_PER_MINUTE / prevSection->bpm);
    }
}

Section::Section(int beatsPerMeasure, double bpm, BeatPos beatpos, Section* prevSection)
    : beatsPerMeasure{ beatsPerMeasure }
    , bpm{ bpm }
    , beatpos{ beatpos }
    , absBeatStart{ calculateBeatStart(beatsPerMeasure, beatpos, prevSection) }
    , absTimeStart{ calculateTimeStart(absBeatStart, beatpos, prevSection) }
{}

void to_json(json& j, const Section& ti) {
    j = json{ { constants::BEATS_PER_MEASURE_KEY, ti.beatsPerMeasure },
              { constants::BPM_KEY, ti.bpm },
              { constants::BEATPOS_KEY, ti.beatpos } };
}

void from_json(const json& j, Section& ti) {
    ti.beatsPerMeasure = j.value(constants::BEATS_PER_MEASURE_KEY, constants::DEFAULT_BEATS_PER_MEASURE);
    ti.bpm = j.value(constants::BPM_KEY, constants::DEFAULT_BPM);

    auto beatposJSON = j[constants::BEATPOS_KEY];
    if (!beatposJSON.is_array() || !beatposJSON.size() == constants::BEATPOS_SIZE) {
        return;
    }

    ti.beatpos = beatposJSON.get<BeatPos>();
}

bool operator<(const Section& lhs, const Section& rhs) {
    return lhs.beatpos < rhs.beatpos;
}

} // rglib
