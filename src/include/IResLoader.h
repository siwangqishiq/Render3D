//不同平台统一资源访问接口

#ifndef _IRES_LOADER_
#define _IRES_LOADER_

#include <string>

class IResLoader{
public:
    //载入文件
    virtual unsigned char* loadAssetsFile(std::string path , long &filesize) = 0;

    //载入图片资源
    virtual unsigned char* loadAssetsImage(std::string path , 
                            int &imageWidth , 
                            int &imageHeight , 
                            int &channels) = 0;
    
    //读取文本文件
    virtual std::string loadAssetsText(std::string path) = 0;
};

#endif