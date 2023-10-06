#include "bird.h"

class Advance {
    public:
    virtual void advance(Bird & bird, int points) = 0;
};

class Inertia : public Advance {
    public:
    void advance(Bird & bird, int points);
};

class Buoyancy : public Advance {
    public:
    void advance(Bird & bird, int points);
};

class Gravity : public Advance {
    public:
    void advance(Bird & bird, int points);
};

class Chaos : public Advance {
    public:
    void advance(Bird & bird, int points);
};