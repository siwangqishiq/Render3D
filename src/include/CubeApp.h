//
//
#ifndef _CUBEAPP_H_
#define _CUBEAPP_H_

#include "App.h"
#include "Shape.h"

class CubeApp : public App{
private:
    Cube *cube;

public:
    virtual void resize(int width , int height);

    virtual void init();

    virtual void update(long delta_time);

    virtual void destory();

};


#endif