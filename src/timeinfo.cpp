#include "rglib/timeinfo.h"

#include "rglib/constants.h"

namespace rglib {

TimeInfo::TimeInfo(const std::vector<Section> & sections)
    : sections{ sections }
{}

Section& TimeInfo::operator[](int index) {
    return sections[index];
}

Section TimeInfo::operator[](int index) const {
    return sections.at(index);
}

void to_json(json& j, const TimeInfo& ti) {
    auto timeinfo = json::array();
    for (const auto& section : ti.sections) {
        timeinfo.push_back(section);
    }

    j = timeinfo;
}

void from_json(const json& j, TimeInfo& ti) {
    ti.sections.clear();

    Section* prevSection{ nullptr };
    for(const auto& sectionJ : j) {
        Section section { sectionJ.get<Section>() };

        ti.sections.emplace_back(section.beatsPerMeasure, section.bpm, section.beatpos, prevSection);
        prevSection = &ti.sections.back();
    }
}

} // rglib
