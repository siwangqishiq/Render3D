#include "CubeApp.h"

void CubeApp::init(){
    cube = new Cube();
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





