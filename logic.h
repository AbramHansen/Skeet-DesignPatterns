#include "storage.h"

using namespace std;

// Controller
//template <typename T>
class Logic {
public:
    Logic();
    void advance();
    void spawn();
    void input();
    iterator begin();
    iterator end();
    int getFramesLeft();
    int getLevelNumber();
    double getGunAngle();
    bool isPlaying();
    bool isGameOver();
    double getPercentLeft();
    void setDimentions(Position dimentions);

    double getDimensionsX();
    double getDimensionsY();
    bool isBullseye();
private:
    Storage storage;
    iterator iterator;
};

