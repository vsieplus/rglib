#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string_view>

namespace rglib::constants {

constexpr double SECONDS_PER_MINUTE{ 60.0 };
constexpr double EPSILON = { 0.000001 };

constexpr std::string_view PREVIEW_START_KEY { "musicPreviewStart" };
constexpr std::string_view PREVIEW_STOP_KEY { "musicPreviewStop" };
constexpr std::string_view OFFSET_KEY { "offset" };
constexpr std::string_view TITLE_KEY { "title" };
constexpr std::string_view ARTIST_KEY { "artist" };
constexpr std::string_view GENRE_KEY { "genre" };
constexpr std::string_view MUSIC_FILEPATH_KEY { "music" };
constexpr std::string_view ART_FILEPATH_KEY { "art" };

} // rglib

#endif // CONSTANTS_H