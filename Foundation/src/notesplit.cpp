#include "rglib/notesplit.h"

#include <numeric>
#include <unordered_map>

namespace rglib {

const std::unordered_map<int, NoteSplit> DENOMINATOR_TO_NOTESPLIT {
    { 1, NoteSplit::WHOLE },
    { 2, NoteSplit::HALF },
    { 4, NoteSplit::QUARTER },
    { 8, NoteSplit::EIGHTH },
    { 16, NoteSplit::SIXTEENTH },
    { 32, NoteSplit::THIRTYSECOND },
    { 64, NoteSplit::SIXTYFOURTH },
    { 128, NoteSplit::ONETWENTYEIGHTH },
    { 3, NoteSplit::TWELFTH },
    { 6, NoteSplit::TWELFTH },
    { 12, NoteSplit::TWELFTH },
    { 24, NoteSplit::TWENTYFOURTH },
    { 48, NoteSplit::FORTYEIGHTH },
    { 96, NoteSplit::NINETYSIXTH }
};

NoteSplit computeNoteSplit(int noteSplitNumerator, int noteSplitDenominator) {
    auto gcd = std::gcd(noteSplitNumerator, noteSplitDenominator);
    noteSplitNumerator /= gcd;
    noteSplitDenominator /= gcd;

    if (DENOMINATOR_TO_NOTESPLIT.find(noteSplitDenominator) != DENOMINATOR_TO_NOTESPLIT.end()) {
        return DENOMINATOR_TO_NOTESPLIT.at(noteSplitDenominator);
    }

    return NoteSplit::WHOLE;
}

} // rglib
