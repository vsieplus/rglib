#include "rglib/beatpos.h"

#include <numeric>

namespace rglib {

BeatPos::operator double() const {
    return measure + (split / (double)measureSplit);
}

BeatPos operator+(const BeatPos& lhs, const BeatPos& rhs) {
    // find lcd of lhs / rhs measureSplit
    auto measureSplit = std::lcm(lhs.measureSplit, rhs.measureSplit);

    // scale split accordingly
    auto lhsSplit = lhs.split * (measureSplit / lhs.measureSplit);
    auto rhsSplit = rhs.split * (measureSplit / rhs.measureSplit);

    // treat beatpos as a mixed number, compute accordingly
    // measure + split / measureSplit
    auto measure = lhs.measure + rhs.measure;
    auto split = lhsSplit + rhsSplit;

    if (split >= measureSplit) {
        measure += (double)split / measureSplit;
        split %= measureSplit;
    }

    return BeatPos{ measure, split, measureSplit };
}

BeatPos operator-(const BeatPos& lhs, const BeatPos& rhs) {
    // find lcd of lhs / rhs measureSplit
    auto measureSplit = std::lcm(lhs.measureSplit, rhs.measureSplit);

    // scale split accordingly
    auto lhsSplit = lhs.split * (measureSplit / lhs.measureSplit);
    auto rhsSplit = rhs.split * (measureSplit / rhs.measureSplit);

    auto measure = lhs.measure - rhs.measure;
    auto split = lhsSplit - rhsSplit;

    if (split < 0) {
        measure -= 1;
        split += measureSplit;
    }

    return BeatPos{ measure, split , measureSplit };
}

bool operator==(const BeatPos& lhs, const BeatPos& rhs) {
    bool equalSplit = lhs.measureSplit == rhs.measureSplit;
    
    if (lhs.measureSplit > 0 && rhs.measureSplit > 0) {
        auto measureSplit = std::lcm(lhs.measureSplit, rhs.measureSplit);
        auto lhsSplit = lhs.split * (measureSplit / lhs.measureSplit);
        auto rhsSplit = rhs.split * (measureSplit / rhs.measureSplit);

        equalSplit = lhsSplit == rhsSplit;
    }

    return lhs.measure == rhs.measure && equalSplit;
}

bool operator<(const BeatPos& lhs, const BeatPos& rhs) {
    return (lhs.measure < rhs.measure)
        || (lhs.measure == rhs.measure
            && ((double)lhs.split / lhs.measureSplit) < ((double)rhs.split / rhs.measureSplit));
}

bool operator!=(const BeatPos& lhs, const BeatPos& rhs) {
    return !(lhs == rhs);
}

bool operator>(const BeatPos& lhs, const BeatPos& rhs) {
    return rhs < lhs;
}

bool operator<=(const BeatPos& lhs, const BeatPos& rhs) {
    return !(rhs < lhs);
}

bool operator>=(const BeatPos& lhs, const BeatPos& rhs) {
    return !(lhs < rhs);
}

std::ostream& operator<<(std::ostream& os, const BeatPos& bp) {
    os << bp.measure << " " << bp.split << "/" << bp.measureSplit;
    return os;
}

} // rglib
