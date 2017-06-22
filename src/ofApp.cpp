///////////////////////////////////////////////////////
// Workshops in Creative Coding - Final Term Project //
// By Jakob Glock                                    //
///////////////////////////////////////////////////////

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    //----//----//----//----//----//----//----//----//----//----//----//----

    /* Global variables for frameRate, background color, timing */
    fRate = 60; // Framerate
    bgColor = 0; // Background color
    totalSeconds = 180; // Total seconds
    time = 0; // timer/counter
    globalTime = 180; // globalTime

    /* Setting frameRate, background color, etc.. */
    ofSetFrameRate(fRate);
    ofBackground(bgColor);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 1 */

    /* Fill a vector with sceneOneClass objects */
    float myScene1ID = 0; // Varible for ID
    for(int i=0; i<200; i++){
            myScene1ID++; // Increament the Id variable
            myScene1.push_back(sceneOneClass(0, 0, myScene1ID)); // Push an element into the vector
            myScene1[i].physicsOn = true; // Turn physics on when creating
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 2 */

    /* Setting variables for drawing my grid in scene two */
    gridSize = 200;
    spacingX = ofGetWidth() / gridSize;
    spacingY = ofGetHeight() / 8;
    offsetX = spacingX / 2;
    offsetY = spacingY / 2;

    /* Fill a vector with sceneTwoClass objects */
    float myScene2ID = 0;
    for(int j=0; j<8; j++){
        float speed = ofRandom(0.02, 0.04); // random speed
        for(int i=0; i<200; i++){
            myScene2ID++;
            myScene2.push_back(sceneTwoClass(spacingX * i + offsetX, spacingY * j, myScene2ID, speed));
        }
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 3 */

    /* Fill a vector with sceneThreeClass objects */
    float myScene3ID = 0;
    for(int i=0; i<720; i++){
            myScene3ID++;
            myScene3.push_back(sceneThreeClass(0, 0, myScene3ID));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Global Clock */

    /* My timer based on the number of frames */
    time++; // A simple counter
    int numFrames = totalSeconds * 60; // Total number of frames for 60FPS at 180 seconds (3mins)
    globalTime = ofMap(time, 0, numFrames, totalSeconds, 0); // Mapping number of frames to seconds



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 1 */

    /* Loop through myScene1 and call the update function */
    for(int i=0; i<myScene1.size(); i++){
        myScene1[i].update(globalTime);

        /* If the radius of the current myCirlces is less than or equal to zero erase it */
        if(myScene1[i].radius <= 0)
        {
            myScene1.erase(myScene1.begin()+i); // Erase an element from the vector
        }
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 2 */

    /* If there are no myCircle class objects do something */
    if(myScene1.size() == 0)
    {

        /* Loop through myScene2 and call the update function */
        for(int i=0; i<myScene2.size(); i++){
            myScene2[i].update(globalTime); // Passing in globalTime variable

            /* If myScene2 position is outside the left or right of the screen or globalTime is less than 55
             * then remove that instance from the vector */
            if(myScene2[i].pos.x < 0 || myScene2[i].pos.y > ofGetWidth())
            {
                myScene2.erase(myScene2.begin()+i); // Erase from a vector
            }

        }
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 3 */

    /* Only call this if globalTime is less 80 */
    if(globalTime < 80){

        /* Get the remainder of time store it in t*/
        int t = time % 360;

        /* Store some random values */
        float r1 = int(ofRandom(0, 3));
        float r2 = int(ofRandom(0, 3));
        float r3 = int(ofRandom(0, 3));
        float r4 = int(ofRandom(0, 3));

        /* If all the values are equal repick until they are not all equal */
        while(r1 == r2 && r1 == r3 && r1 == r4)
        {
            r1 = int(ofRandom(0, 3));
            r2 = int(ofRandom(0, 3));
            r3 = int(ofRandom(0, 3));
            r4 = int(ofRandom(0, 3));
        }

        /* Loop through myScene3 */
        for(int i=0; i<myScene3.size(); i++){

            /* If t is equal to zero and globalTime is greater or less than, then do something */
            if(t == 0 && globalTime < 55 && globalTime > 15)
            {
                /* Call the function setFreq and pass in my random variables */
                myScene3[i].setFreq(r1, r2, r3, r4);
            }

            /* Call the update function */
            myScene3[i].update(globalTime);

            /* If the radius of the current myScene is less than or equal to zero erase it */
            if(myScene3[i].radius <= 0)
            {
                myScene3.erase(myScene3.begin()+i); // Erase an element from the vector
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 1 */

    /* Loop through myScene1 and call the draw function */
    for(int i=0; i<myScene1.size(); i++){
        myScene1[i].draw();

        /* Loop through again and pass in the pos of every other object check distance
         * and draw a line between the two points if its less than a certain number*/
        for(int j=0; j<myScene1.size(); j++){
            myScene1[i].getDistance(myScene1[j].pos); // This function finds the distance between each particle
        }
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 2 */

    /* Loop through myScene2 and call the draw function, pass in the globalTime variable */
    for(int i=0; i<myScene2.size(); i++){
        myScene2[i].draw(globalTime);
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Scene 3 */

     /* Loop through myScene3 and call the draw function, pass in the globalTime variable */
    for(int i=0; i<myScene3.size(); i++){
        myScene3[i].draw();
    }



    //----//----//----//----//----//----//----//----//----//----//----//----
    /* Exit the application */

    /* Exit the application if globalTime is less than 0 */
    if(globalTime < 0){
        ofExit(0);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
