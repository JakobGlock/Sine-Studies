#ifndef SCENETWOCLASS_H
#define SCENETWOCLASS_H

/* This class is for the second scene */

#include "baseshape.h"

/* This class also inherits from the baseshape class */

class sceneTwoClass : public BaseShape {
public:

    /* Functions */
    sceneTwoClass(float _x, float _y, float _id, float _tS);
    void draw(float _gT);
    void update(float _gT);
    void setVelAmt(float _vA);

    /* Variables */
    float lineHeight, velAmt, alpha;

};

#endif // SCENETWOCLASS_H
