#ifndef NOTESPLIT_H
#define NOTESPLIT_H

namespace rglib {

enum class NoteSplit {
    WHOLE,
    HALF,
    QUARTER,
    EIGHTH,
    SIXTEENTH,
    THIRTYSECOND,
    SIXTYFOURTH,
    ONETWENTYEIGHTH,
    TWOFIFTYSIXTH,
    TWELFTH,
    TWENTYFOURTH,
    FORTYEIGHTH,
    NINETYSIXTH,
};

NoteSplit computeNoteSplit(int noteSplitNumerator, int noteSplitDenominator);

} // rglib

#endif // NOTESPLIT_H
