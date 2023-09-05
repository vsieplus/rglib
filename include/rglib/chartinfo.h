#ifndef CHARTINFO_H
#define CHARTINFO_H

#include "rglib/fileformat.h"
#include "rglib/sequenceitem.h"
#include "rglib/timeinfo.h"

#include <filesystem>
namespace fs = std::filesystem;

#include <string>
#include <string_view>
#include <vector>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

namespace rglib {

struct ChartInfo {
    ChartInfo() = default;
    ChartInfo(int level, std::string_view author, std::string_view difficulty);

    virtual void save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat);

    int level{};

    std::string author{};
    std::string difficulty{};

    TimeInfo timeinfo{};
};

void to_json(json& j, const ChartInfo& ci);
void from_json(const json& j, ChartInfo& ci);

}

#endif // CHARTINFO_H
