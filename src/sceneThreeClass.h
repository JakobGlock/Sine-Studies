#ifndef SCENETHREECLASS_H
#define SCENETHREECLASS_H

/* This class is for the second scene */

#include "baseshape.h"

/* This class inherits from the baseshape class */

class sceneThreeClass : public BaseShape {
public:

    /* functions */
    sceneThreeClass(float _x, float _y, float _id);
    void update(float _gT);
    void setFreq(int t1, int t2, int t3, int t4);

    /* Variables */
    float prevRadius;
    float f1, f2, f3, f4;
    float g1, g2, g3, g4;

    /* Array */
    float shapeFreq[4] = { 2, 4, 6, 8 };

};

#endif // SCENETHREECLASS_H
