#include <iostream>

class Level {
public:
    int levelNumber;

    Level(int num) : levelNumber(num) {}

    void display() {
        std::cout << "Level: " << levelNumber << "\n";
    }
};

class VideoGame {
private:
    Level* levels[10];
    int numLevels;

public:
    VideoGame() : numLevels(0) {}

    void addLevel(int num) {
        if (numLevels < 10) {
            levels[numLevels++] = new Level(num);
        }
    }

    void display() {
        std::cout << "Video Game Levels:\n";
        for (int i = 0; i < numLevels; i++) {
            levels[i]->display();
        }
    }

    ~VideoGame() {
        for (int i = 0; i < numLevels; i++) {
            delete levels[i];
        }
    }
};

int main() {
    VideoGame game;
    game.addLevel(1);
    game.addLevel(2);

    game.display();

    return 0;
}
