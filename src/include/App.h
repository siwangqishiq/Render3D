#ifndef _IAPP_ 
#define _IAPP_

#include <memory>
#include "IResLoader.h"
#include "IInput.h"
#include <map>
#include "Camera.h"

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

    //处理输入事件
    virtual void processInput(int action);

    int mViewWidth;
    int mViewHeight;
    
    std::shared_ptr<IResLoader> resLoader = nullptr;
    std::shared_ptr<IInput> input = nullptr;

    ~App();

    //根据不同平台 注入不同实现
    inline void setResLoader(std::shared_ptr<IResLoader> loader){
        this->resLoader = loader;
    }

    inline void setInput(std::shared_ptr<IInput> _input){
        this->input = _input;
    }

    //载入2D纹理
    TextureInfo loadAssetsTexture(std::string path , bool needReleaseData);

    std::shared_ptr<Camera> mCamera = nullptr;

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

