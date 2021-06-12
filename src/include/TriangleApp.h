#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "App.h"
#include "Shape.h"

class TriangleApp : public App{
private:
    Triangle mTriangle;

public:
    virtual void init();

    virtual void update(long delta_time);

    virtual void destory();

};


#endif