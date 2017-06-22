#include "sceneOneClass.h"

//--------------------------------------------------------------
/* Call the sceneOneClass constructor and baseShape constructor, whilst passing variables */
sceneOneClass::sceneOneClass(float _x, float _y, float _id) : BaseShape(_x, _y, _id){

    /* Random varibale value so that each particle reduces in size at a differnet rate */
    reduceRadius = ofRandom(0.004, 0.01);

}

//--------------------------------------------------------------
void sceneOneClass::update(float _gT){

    /* Call the baseShape update function aswell */
    BaseShape::update();

    /* Adding functionality */

    /* If _gT is greater than 140 then do something */
    if(_gT > 140)
    {
        /* Slowly increase radius */
        radius = ofMap(_gT, 180, 140, 0, 3);

        /* Set positions based on sin and cos functions */
        pos.x = cos(time + id * 6) * sin(time + id * 12) * 300 + (ofGetWidth() / 2);
        pos.y = sin(time + id * 16) * cos(time + id * 8) * 300 + (ofGetHeight() / 2);
    }
    else
    {
        /* Reduce the radius if _gT is less 140 */
        timeStep = 0;
        radius = ofMap(_gT, 140, 120, 3, 0);
    }
}

//--------------------------------------------------------------
void sceneOneClass::getDistance(ofVec2f p){

    /* Get distance between this position and other one */
    float d = ofDist(pos.x, pos.y, p.x, p.y);

    /* Create a max distance that varies over time */
    float decreaseDist = ofMap(radius, 0, 3, 0, 1, true);
    float maxDist = (ofNoise(time * 0.001) * 80 + 40) * decreaseDist;

    /* If distance is less than maxdist draw a line between both positions */
    if(d < maxDist)
    {
        /* Draw a line */
        ofSetColor(255, 255, 255, 40);
        ofDrawLine(pos.x, pos.y, p.x, p.y);
    }
}
