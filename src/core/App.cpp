#include "App.h"
#include <iostream>
#include "gl.h"
#include "stb_image.h"

void App::init(){
    std::cout << "init" << std::endl;
}

void App::resize(int w , int h){
    this->mViewWidth = w;
    this->mViewHeight = h;
    std::cout << "resize " <<mViewWidth << " x " << mViewHeight << std::endl;
}

void App::update(long delta_time){
    //std::cout << "update delta = " << delta_time << std::endl;
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void App::destory(){
    std::cout << "destory" << std::endl;
}

App::~App(){
    
}

TextureInfo App::loadAssetsTexture(std::string path , bool needReleaseData){
    if(loadedTextures.find(path) != loadedTextures.end()){//此filename之前已被载入过
		return loadedTextures[path];
	}

	TextureInfo info;
	stbi_set_flip_vertically_on_load(true);

	unsigned char *imageData = nullptr;
    imageData = this->resLoader->loadAssetsImage(path , info.srcWidth , info.srcHeight , info.channel);
	
	if(imageData){
		info.data = imageData;
	}else{
		std::cout << "load texture " << path << " failed!" << std::endl;
		return info;
	}

	int format;
	if(info.channel == 3){//3通道
		format = GL_RGB;
	}else if(info.channel == 4){ //4通道 
		format = GL_RGBA;
	}

	glGenTextures(1 , &info.textureId);
	glBindTexture(GL_TEXTURE_2D , info.textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	glTexImage2D(GL_TEXTURE_2D , 0 , format , info.srcWidth , info.srcHeight ,0 , format, GL_UNSIGNED_BYTE , info.data);
	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D , 0);

	if(needReleaseData){
		stbi_image_free(imageData);
	}

	//加入map 防止后面重复加载
	loadedTextures[path] = info;
	return info;
}

// void SimpleApp::init(){
//     std::cout << "SimpleApp init" << std::endl;
// }

// void SimpleApp::resize(int w , int h){
//     this->mViewWidth = w;
//     this->mViewHeight = h;
//     std::cout << "resize " <<mViewWidth << " x " << mViewHeight << std::endl;
// }

// void SimpleApp::update(long delta_time){
//     //std::cout << "update delta = " << delta_time << std::endl;
//     glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
// }

// void SimpleApp::destory(){
//     std::cout << "destory" << std::endl;
// }
