#ifndef TIMEINFO_H
#define TIMEINFO_H

#include "rglib/section.h"

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace rglib {

struct TimeInfo {
    TimeInfo() = default;
    TimeInfo(const std::vector<Section> & sections);

    Section& operator[](int index);
    Section operator[](int index) const;
    size_t size() const { return sections.size(); }

    std::vector<Section> sections{};
};

void to_json(json& j, const TimeInfo& ti);
void from_json(const json& j, TimeInfo& ti);

} // rglib

#endif // TIMEINFO_H
