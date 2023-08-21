#include <rglib/songinfo.h>
#include <rglib/chartinfo.h>

#include <iostream>

rglib::SongInfo loadSong() {
    rglib::SongInfo songinfo{ "data/TypingTempo/songinfo.json", rglib::SongInfo::FileFormat::JSON };

    std::cout << "Title: " << songinfo.getTitle() << "\n";
    std::cout << "Artist: " << songinfo.getArtist() << "\n";
    std::cout << "Genre: " << songinfo.getGenre() << "\n";

    std::cout << "Music Preview start: " << songinfo.getPreviewStart() << "\n";
    std::cout << "Music Preview stop: " << songinfo.getPreviewStop() << "\n";

    std::cout << "Music filepath: " << songinfo.getMusicFilepath() << "\n";

    // load audio ...

    std::cout << "Art filepath: " << songinfo.getArtFilepath() << "\n";

    // load art ...

    return songinfo;
}

void loadChart() {

}

int main() {
    auto songinfo = loadSong();

    loadChart();

    return 0;
}
