#include "Skybox.h"

SkyBox::SkyBox(App *context ,std::string imageFile){
    this->mContext = context;
}

void SkyBox::init(){
    
}

void SkyBox::render(long deltaTime){

}

void SkyBox::destory(){

}

SkyBox::~SkyBox(){
}


void SykBoxTestApp::init(){
    //do nothing init in resize when get view widht / height
}

void SykBoxTestApp::resize(int width , int height){
    App::resize(width , height);
    mCamera = std::make_shared<Camera>(glm::vec3(0,0,0) , glm::vec3(0,0,-10) , (float)mViewWidth / (float)mViewHeight);
    
    mSkyBox = std::make_shared<SkyBox>(this , "");
    mSkyBox->init();
}

void SykBoxTestApp::update(long deltaTime){
    App::update(deltaTime);

    mSkyBox->render();
}

void SykBoxTestApp::destory(){
    mSkyBox->destory();
    App::destory();
}


