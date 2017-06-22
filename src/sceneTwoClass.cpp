#include "sceneTwoClass.h"

//--------------------------------------------------------------
/* Call the sceneTwoClass constructor and baseShape constructor, whilst passing variables */
sceneTwoClass::sceneTwoClass(float _x, float _y, float _id, float _tS) : BaseShape(_x, _y, _id){

    /* Initialize variables */
    timeStep = _tS;
    vel.set(ofRandom(-100, 100), 0); // Random velocity on x axis only
    lineHeight = ofGetHeight() / 8; // Line height is total height divided by 8 as I have 8 rows of lines
    velAmt = 0;
    alpha = 255; // Alpha set to 255 by default
}

//--------------------------------------------------------------
void sceneTwoClass::update(float _gT){

    /* Speed gets faster over a period of time */
    pos += (vel * ofMap(_gT, 110, 90, 0, 0.01, true));
    time += timeStep;
}

//--------------------------------------------------------------
void sceneTwoClass::draw(float _gT){

    /* If global time is less than 90 slowly fade out */
    if(_gT < 90)
    {
        alpha = ofMap(_gT, 90, 60, 255, 20, true);
    }

    /* Set color based on sin function and positon */
    float offset = ofMap((int(id) % 200), 0, 200, 0, TWO_PI);
    col = ofMap(sin(offset + time * 4 + (PI/2)), -1, 1, 0, 255) * ofMap(_gT, 140, 110, 0, 1, true);

    /* Draw some lines */
    ofSetColor(col, alpha);
    ofDrawLine(pos.x, pos.y, pos.x, pos.y+lineHeight);
}

//--------------------------------------------------------------
/* This function sets the velocity */
void sceneTwoClass::setVelAmt(float _vA){
    velAmt = _vA;
}
