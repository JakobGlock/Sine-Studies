#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "ofMain.h"

/* This is my base class for my objects, it has some basic functionality which I base my objects on
 * I chose to do it this way because all my objects will have varibales like position, velocity, color
 * and draw update and edges functions, just incase i wanted to use them, I wouldnt need to write these
 * basic things again and again */

class BaseShape{
public:

    /* Functions */
    BaseShape(float _x, float _y, float _id); // Constructor
    void draw();
    void update();
    void edges();

    /* Variables */
    ofVec2f pos, vel, gravity;
    float radius, time, timeStep, id;
    ofColor col;
    bool hitSide, physicsOn;

};

#endif // BASESHAPE_H
