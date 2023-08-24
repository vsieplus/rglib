#include "rglib/sequenceitem.h"

#include "rglib/constants.h"

namespace rglib {

double calculateAbsBeat(BeatPos beatpos, const std::vector<TimeInfo>& sections) {
    double absBeat{};
    double absMeasure{ static_cast<double>(beatpos) };

    double lastMeasureStart{ 0.0 };
    double lastBeatsPerMeasure{ 4.0 };
    std::size_t j { 0 };
    for(const auto & section : sections) {
        double measureStart = static_cast<double>(section.beatpos);

        if(absMeasure < measureStart || j == sections.size() - 1) {
            absBeat += lastBeatsPerMeasure * (absMeasure - lastMeasureStart);
        } else {
            absBeat += lastBeatsPerMeasure * (measureStart - lastMeasureStart);
        }

        lastMeasureStart = measureStart;
        lastBeatsPerMeasure = section.beatsPerMeasure;
        ++j;
    }

    return absBeat;
}

double calculateAbsTime(double absBeat, BeatPos beatpos, const std::vector<TimeInfo>& sections) {
    double sectionBeatStart{};
    double sectionTimeStart{};
    double spb{};

    for(const auto & section : sections) {
        if(absBeat > section.absBeatStart) {
            sectionBeatStart = section.absBeatStart;
            sectionTimeStart = section.absTimeStart;
            spb = constants::SECONDS_PER_MINUTE / section.bpm;
        } else {
            break;
        }
    }

    double currSectionTime { (absBeat - sectionBeatStart) * spb };
    return sectionTimeStart + currSectionTime;
}

SequenceItem::SequenceItem(double absTime, double absBeat)
    : absBeat{ absBeat }
    , absTime{ absTime }
{}

SequenceItem::SequenceItem(BeatPos beatpos, const std::vector<TimeInfo>& sections)
    : absBeat{ calculateAbsBeat(beatpos, sections) }
    , absTime{ calculateAbsTime(absBeat, beatpos, sections) }
{}


} // rglib
