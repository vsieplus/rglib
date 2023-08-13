#ifndef CHARTINFO_H
#define CHARTINFO_H

#include <filesystem>
namespace fs = std::filesystem;

#include <string>
#include <string_view>

namespace rglib {

class ChartInfo {
public:
    ChartInfo(int level, std::string_view author);
private:
    int level{};

    std::string author{};
};

}

#endif // CHARTINFO_H
