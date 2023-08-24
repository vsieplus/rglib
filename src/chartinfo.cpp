#include "rglib/chartinfo.h"

namespace rglib {

ChartInfo::ChartInfo(fs::path filepath, FileFormat chartFormat) {
    switch (chartFormat) {
    case FileFormat::JSON:
        //loadFromJSON(filepath);
        break;
    default:
        break;
    }
}

ChartInfo::ChartInfo(int level, std::string_view author, std::string_view difficulty)
    : level{ level }
    , author{ author }
    , difficulty{ difficulty }
{}


} // rglib