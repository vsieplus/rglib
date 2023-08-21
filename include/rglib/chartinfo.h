#ifndef CHARTINFO_H
#define CHARTINFO_H

#include "rglib/fileformat.h"

#include <filesystem>
namespace fs = std::filesystem;

#include <string>
#include <string_view>

namespace rglib {

class ChartInfo {
public:
    ChartInfo(fs::path filepath, FileFormat fileFormat);
    ChartInfo(int level, std::string_view author, std::string_view difficulty);
private:
    int level{};

    std::string author{};
    std::string difficulty{};
};

}

#endif // CHARTINFO_H
