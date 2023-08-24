#ifndef SEQUENCEITEM_H
#define SEQUENCEITEM_H

#include "rglib/beatpos.h"
#include "rglib/timeinfo.h"

#include <vector>

namespace rglib {

// basic representation of an item in a rhythm game level,
// such as a note, a hold, a mine, etc.
struct SequenceItem {
    SequenceItem(double absTime, double absBeat);
    SequenceItem(BeatPos beatpos, const std::vector<TimeInfo> & sections);

    BeatPos beatpos{};

    // beat position from the start of the song
    double absBeat{};

    // time in seconds from the start of the song
    double absTime{};
};

bool operator<(const SequenceItem & lhs, const SequenceItem & rhs);

} // rglib

#endif // SEQUENCEITEM_H
