#include "App.h"
#include <iostream>
#include "gl.h"

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

void SimpleApp::init(){
    std::cout << "SimpleApp init" << std::endl;
}

void SimpleApp::resize(int w , int h){
    this->mViewWidth = w;
    this->mViewHeight = h;
    std::cout << "resize " <<mViewWidth << " x " << mViewHeight << std::endl;
}

void SimpleApp::update(long delta_time){
    //std::cout << "update delta = " << delta_time << std::endl;
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void SimpleApp::destory(){
    std::cout << "destory" << std::endl;
}
