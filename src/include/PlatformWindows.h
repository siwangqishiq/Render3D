//
//
#ifndef _PLATFORM_WINDOWS_H_
#define _PLATFORM_WINDOWS_H_

#include "IResLoader.h"

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

#endif
