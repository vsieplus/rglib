#include "rglib/chartinfo.h"

#include "rglib/constants.h"

#include <inipp/inipp.h>

#include <fstream>

namespace rglib {

ChartInfo::ChartInfo(int level, std::string_view author, std::string_view difficulty)
    : level{ level }
    , author{ author }
    , difficulty{ difficulty }
{}

void ChartInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {
    // ...
}

void to_json(json& j, const ChartInfo& ci) {
    j[constants::LEVEL_KEY] = ci.level;
    j[constants::AUTHOR_KEY] = ci.author;
    j[constants::DIFFICULTY_KEY] = ci.difficulty;
    j[constants::TIMEINFO_KEY] = ci.timeinfo;
}

void from_json(const json& j, ChartInfo& ci) {
    ci.level = j.value(constants::LEVEL_KEY, 0);
    ci.author = j.value(constants::AUTHOR_KEY, "");
    ci.difficulty = j.value(constants::DIFFICULTY_KEY, "");

    if(j.contains(constants::TIMEINFO_KEY)) {
        ci.timeinfo = j[constants::TIMEINFO_KEY].get<TimeInfo>();
    }
}

} // rglib
