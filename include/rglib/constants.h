#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace rglib::constants {

constexpr int DEFAULT_BEATS_PER_MEASURE{ 4 };
constexpr int BEATPOS_SIZE{ 3 };

constexpr double DEFAULT_BPM{ 120.0 };
constexpr double SECONDS_PER_MINUTE{ 60.0 };
constexpr double EPSILON { 0.000001 };

constexpr std::string_view PREVIEW_START_KEY { "musicPreviewStart" };
constexpr std::string_view PREVIEW_STOP_KEY { "musicPreviewStop" };
constexpr std::string_view OFFSET_KEY { "offset" };
constexpr std::string_view TITLE_KEY { "title" };
constexpr std::string_view ARTIST_KEY { "artist" };
constexpr std::string_view GENRE_KEY { "genre" };
constexpr std::string_view MUSIC_FILEPATH_KEY { "music" };
constexpr std::string_view ART_FILEPATH_KEY { "art" };

constexpr std::string_view LEVEL_KEY { "level" };
constexpr std::string_view AUTHOR_KEY { "author" };
constexpr std::string_view DIFFICULTY_KEY { "difficulty" };
constexpr std::string_view TIMEINFO_KEY { "timeinfo" };

constexpr std::string_view BPM_KEY { "bpm" };
constexpr std::string_view BEATS_PER_MEASURE_KEY { "beatsPerMeasure" };
constexpr std::string_view BEATPOS_KEY { "pos" };

} // rglib

#endif // CONSTANTS_H