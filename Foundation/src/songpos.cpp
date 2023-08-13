#include "rglib/songpos.h"

namespace rglib {

void SongPos::start() {
    started { true };
    paused{ false };
}

void SongPos::stop() {
    absTime{ 0.0 };
    absBeat{ 0.0 };

    started{ false };
    paused{ false };
}

void SongPos::pause() {
    //pauseCounter = SDL_GetPerformanceCounter();
    paused = true;
}

void SongPos::unpause() {
    //now = SDL_GetPerformanceCounter();
    //songStart += (now - pauseCounter);

    paused = false;
}

void SongPos::setSongTimePosition(double absTime) {
    double timeDiff = absTime - this->absTime;
    
    //double counterDiff = (timeDiff * SDL_GetPerformanceFrequency());
    //songStart -= counterDiff;

    this->absTime = absTime;

    /*int i = 0;
    for (auto const& tInfo : timeinfo) {
        if (absTime < tInfo.absTimeStart) {
            break;
        }

        i++;
    }

    currentSection = std::max(0, i - 1);
    prevSectionBeats = timeinfo.at(currentSection).absBeatStart;
    prevSectionTime = timeinfo.at(currentSection).absTimeStart;

    currSpb = 60.0 / timeinfo.at(currentSection).bpm;*/
}

void SongPos::setSongBeatPosition(double absBeat) {
    /*if (!timeinfo.empty()) {
        // calculate absTime from absBeat
        double absBeatTime = 0;
        double prevAbsBeatStart = 0.0;
        double prevSpb = 60.0 / timeinfo.front().bpm;

        for (auto const& tInfo : timeinfo) {
            if (absBeat >= tInfo.absBeatStart) {
                absBeatTime += prevSpb * (tInfo.absBeatStart - prevAbsBeatStart);

                prevAbsBeatStart = tInfo.absBeatStart;
                prevSpb = (60.0 / tInfo.bpm);
            }
            else {
                break;
            }
        }

        // add the remainder
        absBeatTime += prevSpb * (absBeat - prevAbsBeatStart);
        this->absBeat = absBeat;
        setSongTimePosition(absBeatTime);

        //printf("Setting song beat pos to %.8f, %.4f\n", absBeat, absBeatTime);
    }*/
}

void SongPos::update() {
    /*if (!paused && started) {
        now = SDL_GetPerformanceCounter();
        absTime = (((double)(now - songStart)) / SDL_GetPerformanceFrequency()) - (offsetMS / 1000.0);

        updateBeatPos();

        // updateBPM(); disable for now until figuring out a solution

        updateSection();
        updateSkips();

        //printf("Songpos: %.4f, %.4f\n", absTime, absBeat);
    }*/
}

void SongPos::updateBPM() {
    /*if (bpmInterpolating && currentSection < timeinfo.size() - 1) {
        int nextSection = currentSection + 1;

        float timeUntilNextSection = timeinfo.at(nextSection).absTimeStart - absTime;
        float bpmInterplationProgress = 1 - (timeUntilNextSection / ((timeinfo.at(nextSection).interpolateBeatDuration) * currSpb));
        bpmInterplationProgress = std::min(1.f, bpmInterplationProgress);
        bpmInterplationProgress = std::max(0.f, bpmInterplationProgress);

        float currBpm = bpmInterpolateStart + bpmInterplationProgress * (bpmInterpolateEnd - bpmInterpolateStart);
        currSpb = 60.0 / currBpm;
        prevSectionTime = absTime;
        prevSectionBeats = absBeat;
    }*/
}

void SongPos::updateBeatPos() {
    /*if (beatSkipped) {
        auto timeSinceSkip = (now - currSkipBegin) / (double)SDL_GetPerformanceFrequency();

        // check if full skip passed, or if still 'skipping'
        if (timeSinceSkip > currSkipDuration) {
            beatSkipped = false;
            beatSkiptimePassed = false;
        }
        else if (!beatSkiptimePassed) {
            if (timeSinceSkip < currSkipTime) {
                absBeat = prevSectionBeats + ((currSkipStartTimePosition - prevSectionTime) / currSpb) +
                    (timeSinceSkip / currSkipSpb);
            }
            else {
                absBeat = prevSectionBeats + ((currSkipStartTimePosition - prevSectionTime + currSkipDuration) / currSpb);
                beatSkiptimePassed = true;
            }
        }
    }
    else {
        absBeat = prevSectionBeats + ((absTime - prevSectionTime) / currSpb);
    }*/
}

void SongPos::updateSection() {
    /*if (currentSection < timeinfo.size() - 1) {
        int nextSection = currentSection + 1;

        auto& nextTimeinfo = timeinfo.at(nextSection);

        if (!bpmInterpolating && nextTimeinfo.interpolateBeatDuration > FLT_EPSILON) {
            if (absTime >= nextTimeinfo.absTimeStart - (nextTimeinfo.interpolateBeatDuration * currSpb)) {
                bpmInterpolating = true;
                bpmInterpolateStart = timeinfo.at(currentSection).bpm;
                bpmInterpolateEnd = timeinfo.at(nextSection).bpm;
            }
        }
        else if (absTime >= nextTimeinfo.absTimeStart) {
            currentSection = nextSection;

            prevSectionBeats = timeinfo.at(currentSection).absBeatStart;
            prevSectionTime = absTime;

            currSpb = 60.0 / timeinfo.at(currentSection).bpm;

            bpmInterpolating = false;
        }
    }*/
}


} // rglib
