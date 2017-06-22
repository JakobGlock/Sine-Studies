#include "baseshape.h"

//--------------------------------------------------------------
BaseShape::BaseShape(float _x, float _y, float _id){

    /* This function gets called when the object is created */

    /* Setting varibales */
    pos.set(_x, _y); // Position
    vel.set(ofRandom(-2, 2), ofRandom(-2, 2)); // Random velocity
    gravity.set(0, 0); // Gravity set to zero
    col = ofColor(255); // Color
    radius = 1; // Radius
    time = 0; // time
    timeStep = 0.01; // Amount to increase time by
    hitSide = false; // hitside set to false
    physicsOn = false; // physics set to off
    id = _id; // Id
}

//--------------------------------------------------------------
void BaseShape::update(){
    /* Calling the edges function */
    edges();

    /* If physics is on do the physics stuff, basic Euler intergration */
    if(physicsOn)
    {
    vel += gravity; // Add gravity to velocity
    vel.limit(4); // Limit velocity
    pos += vel; // Add velocity to position
    }

    /* Time keeping inside the object */
    time += timeStep;
}

//--------------------------------------------------------------
void BaseShape::draw(){
    /* Draw function */
    ofSetColor(col);
    ofDrawCircle(pos.x, pos.y, radius);
}

//--------------------------------------------------------------
void BaseShape::edges(){

    /* This function makes shapes bounce off the edge of the screen */
    if(pos.x > ofGetWidth() - radius) // If greater than window width minus radius do something
    {
        pos.x = ofGetWidth() - radius; // Stops objects from getting caught
        vel.x *= -1; // Reverse velocity
        hitSide = true; // Set hitside to true!
    }
    else
    {
        hitSide = false; // Set hitside to false!
    }

    /* The rest are pretty much the same as above, just for the other sides */
    if(pos.x < radius){
        pos.x = radius;
        vel.x *= -1;
        hitSide = true;
    }
    else
    {
        hitSide = false;
    }

    if(pos.y > ofGetHeight() - radius){
        pos.y = ofGetHeight() - radius;
        vel.y *= -1;
        hitSide = true;
    }
    else
    {
        hitSide = false;
    }

    if(pos.y < radius){
        pos.y = radius;
        vel.y *= -1;
        hitSide = true;
    }
    else
    {
        hitSide = false;
    }
}


