#include "PlatformAndroid.h"
#include "gl.h"

#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <string>


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

extern AAssetManager* assetManager;

std::string AndroidResLoader::loadAssetsText(std::string path){
	AAsset *file = AAssetManager_open(assetManager , path.c_str() , AASSET_MODE_BUFFER);
	//LOGI("file read1");
	size_t fileSize = AAsset_getLength(file);

	char *fileContentBuf = new char[fileSize + 1];

	AAsset_read(file , fileContentBuf , fileSize);
	fileContentBuf[fileSize] = '\0';

	AAsset_close(file);

	std::string contentStr = std::string(fileContentBuf);

	delete[] fileContentBuf;

//	LOGI("file content = %s" , contentStr.c_str());
	return contentStr;
}

unsigned char* AndroidResLoader::loadAssetsFile(std::string path , long &filesize){
    return nullptr;
}

unsigned char* AndroidResLoader::loadAssetsImage(std::string path, 
                            int &imageWidth , 
                            int &imageHeight , 
                            int &channels){
	const char *filename = path.c_str();
	AAsset *file = AAssetManager_open(assetManager , filename , AASSET_MODE_BUFFER);
    //LOGI("file read1");
    size_t fileSize = AAsset_getLength(file);
    stbi_uc *fileContentBuf = new stbi_uc[fileSize];
    AAsset_read(file , fileContentBuf , fileSize);
    unsigned char *data = stbi_load_from_memory(fileContentBuf , fileSize , 
		&imageWidth ,&imageHeight , &channels , 0);

    LOGI("read image file %s  %d %d %d" , filename , imageWidth , imageHeight , channels);
    delete[] fileContentBuf;
    AAsset_close(file);
    return data;
}

int AndroidInput::getKeyState(int key){
  return APP_KEY_RELEASE;
}



