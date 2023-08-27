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

namespace rglib {

class ChartInfo {
public:
    ChartInfo(fs::path filepath, FileFormat fileFormat);
    ChartInfo(int level, std::string_view author, std::string_view difficulty);

    virtual void save(fs::path saveDir, std::string_view filename, FileFormat songinfoFormat);

    int getLevel() const { return level; }
    std::string getAuthor() const { return author; }
    std::string getDifficulty() const { return difficulty; }
    const std::vector<TimeInfo> & getSections() const { return sections; }
protected:
    virtual void loadFromJSON(fs::path filepath);
    virtual void loadFromCustom(fs::path filepath);
private:
    int level{};

    std::string author{};
    std::string difficulty{};

    std::vector<TimeInfo> sections{};
};

}

#endif // CHARTINFO_H
