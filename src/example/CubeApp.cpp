#include "CubeApp.h"
#include <iostream>

#include "stb_image.h"

void CubeApp::init(){
    cube = new Cube(this);
    // std::string content = resLoader->loadAssetsText("hello.txt");
    // std::cout << content << std::endl;

    // int width , height , channel;
    // unsigned char *data = resLoader->loadAssetsImage("box2.png",width , height , channel);
    // std::cout << "size " <<width << " x "<< height<< " channel = " << channel << std::endl;
    // stbi_image_free(data);
    
}

void CubeApp::resize(int width , int height){
    App::resize(width , height);
    cube->onInit(width , height);
}

void CubeApp::update(long delta_time){
    App::update(delta_time);
    cube->onRender(delta_time);
}

void CubeApp::destory(){
    cube->onDestory();
}





