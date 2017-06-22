#ifndef SCENEONECLASS_H
#define SCENEONECLASS_H

/* This class is for the first scene */

#include "baseshape.h"

/* This class inherits everything from the baseshape class, I can add to or overwrite the baseshape
 * functionality, for example I do not need to create a draw function here as I have acess to the
 * draw function from the baseshape class */

class sceneOneClass : public BaseShape{
    public:

        /* functions */
        sceneOneClass(float _x, float _y, float _id);
        void update(float _gT);
        void getDistance(ofVec2f p);

        /* variables */
        float reduceRadius;

};

#endif // SCENEONECLASS_H
