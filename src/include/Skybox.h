#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include "App.h"
#include "Camera.h"

#include <memory>

//天空盒
class SkyBox{
public:
    SkyBox(App *context , std::string imageFile);
    ~SkyBox();

    void init();

    void render(long deltaTime);

    void destory();

private:
    App *mContext = nullptr;
};

class SykBoxTestApp:public App{
public:
    virtual void init();

    virtual void update(long delta_time);

    virtual void destory();

    virtual void resize(int width , int height);

private:
    std::shared_ptr<SkyBox> mSkyBox = nullptr;
    std::shared_ptr<Camera> mCamera = nullptr;

};

#endif