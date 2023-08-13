#ifndef SONGPOS_H
#define SONGPOS_H

namespace rglib {

class SongPos {
public:
    void start();
    void stop();
    void pause();
    void unpause();

    void update();
    void updateBPM();
    void updateBeatPos();
    void updateSection();

    void setSongTimePosition(double absTime);
    void setSongBeatPosition(double absBeat);
private:
    bool started{ false };
    bool paused{ false };

    int offsetMS{ 0 };

    double spb{ 0.0 };

    double absTime{ 0.0 };
    double absBeat{ 0.0 };

    double prevSectionTime{ 0.0 };
    double prevSectionBeats{ 0.0 };

    // SDL dependent
    // Uint64 now = 0;
    // Uint64 songStart = 0;
    // Uint64 pauseCounter = 0;

    // unsigned int currentSection = 0;

    // std::vector<Timeinfo> timeinfo;
};

}; // rglib

#endif // SONGPOS_H
