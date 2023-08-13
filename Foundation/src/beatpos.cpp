#include "rglib/beatpos.h"

#include <numeric>

namespace rglib {

BeatPos operator+(const BeatPos& lhs, const BeatPos& rhs) {
    // find lcd of lhs / rhs measureSplit
    int measureSplit = std::lcm(lhs.measureSplit, rhs.measureSplit);

    // scale split accordingly
    int lhsSplit = lhs.split * (measureSplit / lhs.measureSplit);
    int rhsSplit = rhs.split * (measureSplit / rhs.measureSplit);

    // treat beatpos as a mixed number, compute accordingly
    // measure + split / measureSplit
    auto measure = lhs.measure + rhs.measure;
    auto split = lhsSplit + rhsSplit;

    if (split >= measureSplit) {
        measure += (double)split / measureSplit;
        split %= measureSplit;
    }

    return BeatPos{ measure, measureSplit, split };
}

BeatPos operator-(const BeatPos& lhs, const BeatPos& rhs) {
    // find lcd of lhs / rhs measureSplit
    int measureSplit = std::lcm(lhs.measureSplit, rhs.measureSplit);

    // scale split accordingly
    int lhsSplit = lhs.split * (measureSplit / lhs.measureSplit);
    int rhsSplit = rhs.split * (measureSplit / rhs.measureSplit);

    auto measure = lhs.measure - rhs.measure;
    auto split = lhsSplit - rhsSplit;

    if (split < 0) {
        measure -= 1;
        split += measureSplit;
    }

    return BeatPos{ measure, measureSplit, split };
}

bool operator==(const BeatPos& lhs, const BeatPos& rhs) {
    return lhs.measure == rhs.measure
        && lhs.split == rhs.split
        && lhs.measureSplit == rhs.measureSplit;
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
