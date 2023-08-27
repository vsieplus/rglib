#include "rglib/chartinfo.h"

#include "rglib/constants.h"

#include <inipp/inipp.h>
#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <fstream>

namespace rglib {

ChartInfo::ChartInfo(fs::path filepath, FileFormat chartFormat) {
    switch (chartFormat) {
        case FileFormat::JSON:      loadFromJSON(filepath); break;
        case FileFormat::CUSTOM:    loadFromCustom(filepath); break;
        default:                    break;
    }
}

ChartInfo::ChartInfo(int level, std::string_view author, std::string_view difficulty)
    : level{ level }
    , author{ author }
    , difficulty{ difficulty }
{}

void ChartInfo::save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat) {
    // ...
}

void ChartInfo::loadFromJSON(fs::path filepath) {
    std::ifstream fp(filepath);
    json j = json::parse(fp);

    level = j.value(constants::LEVEL_KEY, 0);
    author = j.value(constants::AUTHOR_KEY, "");
    difficulty = j.value(constants::DIFFICULTY_KEY, "");

    if(j.contains(constants::TIMEINFO_KEY)) {
        timeinfo = j[constants::TIMEINFO_KEY].get<TimeInfo>();
    }
}

void ChartInfo::loadFromCustom(fs::path filepath) {}

} // rglib
