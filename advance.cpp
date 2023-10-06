#include "advance.h"
#include <iostream>
void Inertia::advance(Bird & bird, int points)
{
    bird.getVelocity() *= 0.995;
    // inertia
    bird.getPosition().add(bird.getVelocity());

    // out of bounds checker
    if (bird.isOutOfBounds())
    {
        bird.kill();
        points *= -1; // points go negative when it is missed!
        bird.setPoints(points);
    }
}

void Buoyancy::advance(Bird & bird, int points)
{
    bird.getVelocity() *= 0.990;
    bird.getPosition().add(bird.getVelocity());
    bird.getVelocity().addDy(0.05);

    // out of bounds checker
    if (bird.isOutOfBounds())
    {
        bird.kill();
        points *= -1; // points go negative when it is missed!
        bird.setPoints(points);
    }
}

void Gravity::advance(Bird & bird, int points)
{
    bird.getVelocity().addDy(-0.07);
    bird.getPosition().add(bird.getVelocity());
    // out of bounds checker
    if (bird.isOutOfBounds())
    {
        bird.kill();
        points *= -1; // points go negative when it is missed!
        bird.setPoints(points);
    }
}

void Chaos::advance(Bird & bird, int points)
{
    if (randomInt(0, 15) == 0)
        {
            bird.getVelocity().addDy(randomFloat(-1.5, 1.5));
            bird.getVelocity().addDx(randomFloat(-1.5, 1.5));
        }
    bird.getPosition().add(bird.getVelocity());
    // out of bounds checker
    if (bird.isOutOfBounds())
    {
        bird.kill();
        points *= -1; // points go negative when it is missed!
        bird.setPoints(points);
    }
}
