#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace fs = std::filesystem;

#include <nlohmann/json.hpp>
using json = nlohmann::json;
using ordered_json = nlohmann::ordered_json;

#include <rglib/chartinfo.h>
#include <rglib/constants.h>
#include <rglib/songinfo.h>

namespace constants {
    constexpr std::string_view KEY_KEY{ "key" };
    constexpr std::string_view KEYBOARD_KEY{ "keyboard" };
    constexpr std::string_view NOTES_KEY{ "notes" };
    constexpr std::string_view DEFAULT_KEYBOARD{ "qwerty" };

    const fs::path songInfoPath{ "data/TypingTempo/songinfo.json" };
    const fs::path chartPath{ "data/TypingTempo/05.json" };
} // constants

namespace typingtempo {
    struct Note : public rglib::SequenceItem {
        Note(double absTime, double absBeat, std::string_view key)
            : rglib::SequenceItem{ absTime, absBeat }
            , key{ key }
        {}

        Note(rglib::BeatPos beatpos, const rglib::TimeInfo& timeinfo, std::string_view key)
            : rglib::SequenceItem{ beatpos, timeinfo }
            , key{ key }
        {}

        std::string key{};
    };

    struct TypeChart : public rglib::ChartInfo {
        TypeChart() = default;
        TypeChart(int level, std::string_view author, std::string_view difficulty, std::string_view keyboard)
            : rglib::ChartInfo{ level, author, difficulty }
            , keyboard{ keyboard }
        {}

        std::string keyboard{};

        std::vector<Note> notes{};
    };

    void to_json(json& j, const TypeChart& chart) {
        j = static_cast<rglib::ChartInfo>(chart);
        j[constants::KEYBOARD_KEY] = chart.keyboard;
        
        j[constants::NOTES_KEY] = ordered_json::array();
        for(const auto& note : chart.notes) {
            json noteJSON;
            noteJSON[rglib::constants::BEATPOS_KEY] = note.beatpos;
            noteJSON[constants::KEY_KEY] = note.key;

            j[constants::NOTES_KEY].push_back(noteJSON);
        }
    }

    void from_json(const json& j, TypeChart& chart) {
        static_cast<rglib::ChartInfo&>(chart) = j;

        chart.keyboard = j.at(constants::KEYBOARD_KEY).get<std::string>();

        chart.notes.clear();
        auto notesJSON = j.at(constants::NOTES_KEY);
        if(notesJSON.is_array()) {
            for(const auto& noteJSON : notesJSON) {
                auto notePos = noteJSON.at(rglib::constants::BEATPOS_KEY).get<rglib::BeatPos>();
                auto noteKey = noteJSON.at(constants::KEY_KEY).get<std::string>();

                chart.notes.emplace_back(notePos, chart.timeinfo, noteKey);
            }
        }
    }

    rglib::SongInfo loadSong(fs::path songInfoPath) {
        std::ifstream fp{ songInfoPath };
        json j = json::parse(fp);
        rglib::SongInfo songinfo{ j.get<rglib::SongInfo>() };

        return songinfo;
    }

    TypeChart loadChart(fs::path chartPath) {
        TypeChart chartinfo{};

        std::ifstream fp{ chartPath };
        json j{ json::parse(fp) };
        chartinfo = j.get<TypeChart>();

        return chartinfo;
    }

} // typingtempo

int main() {
    auto songinfo = typingtempo::loadSong(constants::songInfoPath);
    auto chartinfo = typingtempo::loadChart(constants::chartPath);

    // songinfo

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

    // chartinfo

    std::cout << "Level: " << chartinfo.level << "\n";
    std::cout << "Author: " << chartinfo.author << "\n";
    std::cout << "Difficulty: " << chartinfo.difficulty << "\n";
    std::cout << "Keyboard: " << chartinfo.keyboard << "\n";

    const auto& timeinfo = chartinfo.timeinfo;
    std::cout << "Sections: " << timeinfo.size() << "\n";
    for (int i = 0; i < timeinfo.size(); i++) {
        const auto& section = timeinfo[i];

        std::cout << "Section " << i << ":\n";
        std::cout << "  BPM: " << section.bpm << "\n";
        std::cout << "  BeatsPerMeasure: " << section.beatsPerMeasure << "\n";
        std::cout << "  BeatPos: " << section.beatpos << "\n";
        std::cout << "  absTime: " << section.absTimeStart << "\n";
        std::cout << "  absBeat: " << section.absBeatStart << "\n";
    }

    std::cout << "Notes: " << chartinfo.notes.size() << "\n";
    for(const auto& note : chartinfo.notes) {
        std::cout << "  Key: " << note.key << "\n";
        std::cout << "  BeatPos: " << note.beatpos << "\n";
        std::cout << "  absTime: " << note.absTime << "\n";
        std::cout << "  absBeat: " << note.absBeat << "\n";
    }

    return 0;
}
