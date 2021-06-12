#include "TriangleApp.h"

void TriangleApp::init(){
    mTriangle.onInit();
}

void TriangleApp::update(long delta_time){
    App::update(delta_time);
    
    mTriangle.onRender();
}

void TriangleApp::destory(){
    mTriangle.onDestory();
}





