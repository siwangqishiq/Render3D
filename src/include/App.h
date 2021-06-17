#ifndef _IAPP_ 
#define _IAPP_

#include <memory>
#include "IResLoader.h"
#include <map>

//纹理数据
struct TextureInfo{
    int srcWidth;
	int srcHeight;
	int channel;
	unsigned int textureId;
	unsigned char *data;
};

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
    
    std::shared_ptr<IResLoader> resLoader = nullptr;

    ~App();

    //根据不同平台 注入不同实现
    inline void setResLoader(std::shared_ptr<IResLoader> loader){
        this->resLoader = loader;
    }

    //载入2D纹理
    TextureInfo loadAssetsTexture(std::string path , bool needReleaseData);

private:
    std::map<std::string , TextureInfo> loadedTextures;//记录已载入的纹理文件 防止重复载入
};

// class SimpleApp : public App{
// public:
//     // init when create
//     virtual void init();

//     // update each frame
//     virtual void update(long delta_time);

//     // destory when app exit
//     virtual void destory();

//     virtual void resize(int width , int height);
// };


// static inline App* createAppInstance(){
//     return new SimpleApp();
// }

#endif

