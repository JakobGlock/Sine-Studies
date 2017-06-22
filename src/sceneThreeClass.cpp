#include "sceneThreeClass.h"

//--------------------------------------------------------------
/* Call the sceneThreeClass constructor and baseShape constructor, whilst passing variables */
sceneThreeClass::sceneThreeClass(float _x, float _y, float _id) : BaseShape(_x, _y, _id){

    /* Set some defualt values */
    col = ofColor(255, 255, 255, 10);
    prevRadius = 0; // Varibale to store my max radius in

    /* Variables for my smoothing */
    f1 = 4;
    f2 = 4;
    f3 = 2;
    f4 = 2;

    /* Frequency values for my sin/cos functions */
    g1 = 4;
    g2 = 4;
    g3 = 2;
    g4 = 2;
}

//--------------------------------------------------------------
void sceneThreeClass::update(float _gT){

    BaseShape::update();

    /* Mapping _gT to some other range */
    float rAmt = ofMap(_gT, 80, 10, 0, 50, true);
    float rFreq = ofMap(_gT, 80, 10, 16, 1, true);

    /* Basic smoothing */
    f1 =  0.95f * f1 + 0.05f * g1;
    f2 =  0.95f * f2 + 0.05f * g2;
    f3 =  0.95f * f3 + 0.05f * g3;
    f4 =  0.95f * f4 + 0.05f * g4;

    /* Only change the radius in between a certain time range */
    if(_gT < 80 && _gT > 10)
    {
        radius = abs(sin(time + ofMap(id, 0, 720, 0, TWO_PI) * rFreq) * rAmt);
        prevRadius = radius; // Store the max radius here
    }
    else if(_gT < 10 && radius > 0)
    {
        radius = ofMap(_gT, 10, 0, prevRadius, 0); // Decrease the radius
    }

    /* My sin/cos drawing thing */
    pos.x = sin(time + ofMap(id, 0, 720, 0, TWO_PI) * f1) * cos(time + ofMap(id, 0, 720, 0, TWO_PI) * f3) * 300 + (ofGetWidth() / 2);
    pos.y = cos(time + ofMap(id, 0, 720, 0, TWO_PI) * f2) * sin(time + ofMap(id, 0, 720, 0, TWO_PI) * f4) * 300 + (ofGetHeight() / 2);

}

//--------------------------------------------------------------
void sceneThreeClass::setFreq(int t1, int t2, int t3, int t4){

    /* This function sets some values */
    g1 = shapeFreq[t1];
    g2 = shapeFreq[t2];
    g3 = shapeFreq[t3];
    g4 = shapeFreq[t4];

}
