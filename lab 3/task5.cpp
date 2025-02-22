// Music player class
#include <iostream>
#include <vector>
#include <string>

class MusicPlayer
{
private:
    std::vector<std::string> playlist;
    std::string currentlyPlayingSong;

public:
    void addSong(const std::string &song)
    {
        playlist.push_back(song);
        std::cout << song << " added to playlist." << std::endl;
    }

    void removeSong(const std::string &song)
    {
        auto it = std::find(playlist.begin(), playlist.end(), song);
        if (it != playlist.end())
        {
            playlist.erase(it);
            std::cout << song << " removed from playlist." << std::endl;
        }
        else
        {
            std::cout << song << " not found in playlist." << std::endl;
        }
    }

    void playSong(const std::string &song)
    {
        auto it = std::find(playlist.begin(), playlist.end(), song);
        if (it != playlist.end())
        {
            currentlyPlayingSong = song;
            std::cout << "Now playing: " << song << std::endl;
        }
        else
        {
            std::cout << song << " is not in the playlist." << std::endl;
        }
    }

    void displayPlaylist()
    {
        std::cout << "Playlist: ";
        for (const auto &song : playlist)
        {
            std::cout << song << " ";
        }
        std::cout << std::endl;
    }
};

int main()
{
    MusicPlayer player;
    player.addSong("Song 1");
    player.addSong("Song 2");
    player.playSong("Song 1");
    player.displayPlaylist();
    player.removeSong("Song 2");
    player.displayPlaylist();
    return 0;
}