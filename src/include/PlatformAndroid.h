//
//
#ifndef _PLATFORM_ANDROID_H_
#define _PLATFORM_ANDROID_H_

#include "IResLoader.h"
#include "IInput.h"

class AndroidResLoader : public IResLoader{
public:
    //载入文件
    virtual unsigned char* loadAssetsFile(std::string path , long &filesize);

    //载入图片资源
    virtual unsigned char* loadAssetsImage(std::string path , int &imageWidth , int &imageHeight , 
                            int &channels);

    //读取文本文件
    virtual std::string loadAssetsText(std::string path);
};

//windows 输入读取 
class AndroidInput: public IInput{
public:
    AndroidInput(){
    }

    virtual int getKeyState(int key);
};

#endif
