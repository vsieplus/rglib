#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

namespace fs = std::filesystem;

#include <nlohmann/json.hpp>
using json = nlohmann::json;

#include <rglib/songinfo.h>
#include <rglib/chartinfo.h>

namespace constants {
    constexpr std::string_view KEYBOARD_KEY{ "keyboard" };
    constexpr std::string_view DEFAULT_KEYBOARD{ "qwerty" };

    const fs::path songInfoPath{ "data/TypingTempo/songinfo.json" };
    const fs::path chartPath{ "data/TypingTempo/05.json" };
} // constants

struct TypeChart : public rglib::ChartInfo {
    TypeChart() = default;
    TypeChart(int level, std::string_view author, std::string_view difficulty, std::string_view keyboard)
        : rglib::ChartInfo{ level, author, difficulty }
        , keyboard{ keyboard }
    {}

    std::string keyboard{};
};

void to_json(json& j, const TypeChart& chart) {
    j = static_cast<rglib::ChartInfo>(chart);
    j[constants::KEYBOARD_KEY] = chart.keyboard;
}

void from_json(const json& j, TypeChart& chart) {
    static_cast<rglib::ChartInfo&>(chart) = j;
    chart.keyboard = j.at(constants::KEYBOARD_KEY).get<std::string>();
}

rglib::SongInfo loadSong(fs::path songInfoPath) {
    std::ifstream fp{ songInfoPath };
    json j { json::parse(fp) };
    rglib::SongInfo songinfo{ j.get<rglib::SongInfo>() };

    std::cout << "Title: " << songinfo.title << "\n";
    std::cout << "Artist: " << songinfo.artist << "\n";
    std::cout << "Genre: " << songinfo.genre << "\n";

    std::cout << "Offset: " << songinfo.offsetMS << "\n";

    std::cout << "Music Preview start: " << songinfo.previewStart << "\n";
    std::cout << "Music Preview stop: " << songinfo.previewStop << "\n";

    std::cout << "Music filepath: " << songinfo.musicFilepath << "\n";

    // load audio ...

    std::cout << "Art filepath: " << songinfo.artFilepath << "\n";

    // load art ...

    return songinfo;
}

TypeChart loadChart(fs::path chartPath) {
    TypeChart chartinfo{};

    std::ifstream fp{ chartPath };
    json j { json::parse(fp) };
    chartinfo = j.get<TypeChart>();

    std::cout << "Level: " << chartinfo.level << "\n";
    std::cout << "Author: " << chartinfo.author << "\n";
    std::cout << "Difficulty: " << chartinfo.difficulty << "\n";
    std::cout << "Keyboard: " << chartinfo.keyboard << "\n";

    const auto& timeinfo = chartinfo.timeinfo;
    std::cout << "Sections: " << timeinfo.size() << "\n";
    for(int i = 0; i < timeinfo.size(); i++) {
        const auto& section = timeinfo[i];

        std::cout << "Section " << i << ":\n";
        std::cout << "  BPM: " << section.bpm << "\n";
        std::cout << "  BeatsPerMeasure: " << section.beatsPerMeasure << "\n";
        std::cout << "  BeatPos: " << section.beatpos << "\n";
        std::cout << "  absTime: " << section.absTimeStart << "\n";
        std::cout << "  absBeat: " << section.absBeatStart << "\n";
    }

    return chartinfo;
}

int main() {
    auto songinfo = loadSong(constants::songInfoPath);
    auto chartinfo = loadChart(constants::chartPath);

    return 0;
}
