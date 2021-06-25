//
//
#ifndef _PLATFORM_WINDOWS_H_
#define _PLATFORM_WINDOWS_H_

#include "IResLoader.h"
#include "IInput.h"
#include <GLFW/glfw3.h>

//windows下实现
class WindowsResLoader : public IResLoader{
public:
    const std::string ASSETS_DIR = "assets/";
    //载入文件
    virtual unsigned char* loadAssetsFile(std::string path , long &filesize);

    //载入图片资源
    virtual unsigned char* loadAssetsImage(std::string path , 
                            int &imageWidth , int &imageHeight , 
                            int &channels);

    //读取文本文件
    virtual std::string loadAssetsText(std::string path);

    std::string buildFilePath(std::string path);
};

//windows 输入读取 
class WindowsInput: public IInput{
public:
    WindowsInput(GLFWwindow *_window){
        this->window = _window;
    }

    virtual int getKeyState(int key);
private:
    GLFWwindow *window;
};

#endif
