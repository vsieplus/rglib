#ifndef BEATPOS_H
#define BEATPOS_H

#include <ostream>

namespace rglib {

// A 3-tuple representation of an entity's 'beat position' in a song

struct BeatPos {
    int measure{ 0 };          // 0-indexed
    int split{ 0 };            // 0-indexed
    int measureSplit{ 1 };     // > 0

    friend std::ostream& operator<<(std::ostream& os, const BeatPos& bp);
};

BeatPos operator+(const BeatPos & lhs, const BeatPos & rhs);
BeatPos operator-(const BeatPos & lhs, const BeatPos & rhs);

bool operator==(const BeatPos & lhs, const BeatPos & rhs);
bool operator<(const BeatPos & lhs, const BeatPos & rhs);
bool operator!=(const BeatPos& lhs, const BeatPos& rhs);
bool operator>(const BeatPos& lhs, const BeatPos& rhs);
bool operator<=(const BeatPos& lhs, const BeatPos& rhs);
bool operator>=(const BeatPos& lhs, const BeatPos& rhs);

} // rglib

#endif // BEATPOS_H
