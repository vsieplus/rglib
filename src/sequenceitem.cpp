#include "rglib/sequenceitem.h"

namespace rglib {

SequenceItem::SequenceItem(double absTime, double absBeat)
    : absTime{ absTime }
    , absBeat{ absBeat }
{}

SequenceItem::SequenceItem(BeatPos beatpos, const std::vector<TimeInfo>& sections)
    : absTime{  }
    , absBeat{  }
{}


} // rglib
