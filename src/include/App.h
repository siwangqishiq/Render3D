#ifndef _IAPP_ 
#define _IAPP_

class App{
public:
    // init when create
    virtual void init();

    // update each frame
    virtual void update(long delta_time);

    // destory when app exit
    virtual void destory();

    // resize when size changed
    virtual void resize(int width , int height);

    int mViewWidth;
    int mViewHeight;
};

class SimpleApp : public App{
public:
    // init when create
    virtual void init();

    // update each frame
    virtual void update(long delta_time);

    // destory when app exit
    virtual void destory();

    virtual void resize(int width , int height);
};


static inline App* createAppInstance(){
    return new SimpleApp();
}

#endif

