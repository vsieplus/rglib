#include "rglib/chartinfo.h"

namespace rglib {

ChartInfo::ChartInfo(int level, std::string_view author)
    : level{ level }
    , author{ author }
{}


} // rglib