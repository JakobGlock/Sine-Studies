#pragma once

#include "ofMain.h"

/* Includes go here */
#include "sceneOneClass.h"
#include "sceneTwoClass.h"
#include "sceneThreeClass.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    /* Vectors to store my objects */
    vector<sceneOneClass> myScene1;
    vector<sceneTwoClass> myScene2;
    vector<sceneThreeClass> myScene3;

    /* My variables */
    int time;
    float bgColor, fRate, totalSeconds, globalTime;
    float gridSize, spacingX, spacingY, offsetX, offsetY;


};
