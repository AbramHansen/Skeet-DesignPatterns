/***********************************************************************
 * Header File:
 *    Fragment : Pieces that fly off a dead bird
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Pieces that fly off a dead bird
 ************************************************************************/

#pragma once
#include "position.h"
#include "Flyer.h"
/**********************
 * Effect: stuff that is not interactive
 **********************/
class Effect : public Flyer
{
protected:
    double age;    // 1.0 = new, 0.0 = dead
public:
    // create a fragment based on the velocity and position of the bullet
   Effect(const Position& pt) : age(0.5) { this->pt = pt; }
    
    // draw it
    virtual void draw() const = 0;
    
    // move it forward with regards to inertia. Let it age
    virtual void move(std::list<Effect*>& effects) = 0;
    
};

/**********************
 * FRAGMENT
 * Pieces that fly off a dead bird
 **********************/
class Fragment : public Effect
{
private:
   Velocity v;    // direction the fragment is flying
   double size;   // size of the fragment
public:
    // create a fragment based on the velocity and position of the bullet
    Fragment(const Position & pt, const Velocity & v);
    
    // draw it
    void draw() const;
    
    // move it forward with regards to inertia. Let it age
    void move(std::list<Effect*>& effects);
};

/**********************
 * STREEK
 * Stuff that trails off the back of shrapnel
 **********************/
class Streek : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Streek(const Position & pt, Velocity v);
    
    // draw it
    void draw() const;
    
    // move it forward with regards to inertia. Let it age
    void move(std::list<Effect*>& effects);
};

/**********************
 * EXHAUST
 * Stuff that comes out the back of a missile when in flight
 **********************/
class Exhaust : public Effect
{
private:
   Position ptEnd;
public:
    // create a fragment based on the velocity and position of the bullet
    Exhaust(const Position & pt, Velocity v);
    
    // draw it
    void draw() const;
    
    // move it forward with regards to inertia. Let it age
    void move(std::list<Effect*>& effects);
};
