#include "Skybox.h"

#include "gl.h"
#include "stb_image.h"
#include <iostream>
#include "glsl.h"

SkyBox::SkyBox(App *context ,std::vector<std::string> imageFiles){
    this->mContext = context;
    this->cubeImages = imageFiles;
}

void SkyBox::init(){
    bindTextures();

    // skybox VAO VBO
    glGenVertexArrays(1, &skyboxVao);
    glGenBuffers(1, &skyboxVbo);
    glBindVertexArray(skyboxVao);
    glBindBuffer(GL_ARRAY_BUFFER, skyboxVbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

    glBindVertexArray(0);
}

//load image to texture
void SkyBox::bindTextures(){
    glGenTextures(1, &skyTextureId);

    glBindTexture(GL_TEXTURE_CUBE_MAP, skyTextureId);
    int width, height, channels;
    for(int i = 0 ; i < cubeImages.size();i++){
        unsigned char *data = mContext->resLoader->loadAssetsImage(cubeImages[i] , width , height , channels);
        int format = GL_RGB;
        if(channels == 4){ //4通道 
            format = GL_RGBA;
        }

        if(data){
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        }else{
            std::cout << "Cubemap texture failed to load at path: " << cubeImages[i] << std::endl;
        }
        stbi_image_free(data);
    }//end for i

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    setupShader();
}

void SkyBox::setupShader(){
    std::string vertSrc = GLSL(
        layout (location = 0) in vec3 aPos;

        out vec3 TexCoords;

        uniform mat4 projMat;
        uniform mat4 viewMat;

        void main()
        {
            TexCoords = aPos;
            vec4 pos = projMat * viewMat * vec4(aPos, 1.0);
            gl_Position = pos.xyww;
        }
    );

    std::string fragSrc = GLSL(
        out vec4 FragColor;
        in vec3 TexCoords;

        uniform samplerCube skybox;

        void main()
        {    
            FragColor = texture(skybox, TexCoords);
        }
    );

    this->skyboxShader = Shader::buildGPUProgram(vertSrc , fragSrc);
}

void SkyBox::render(long deltaTime){
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
    skyboxShader.useShader();

    //std::cout << "camera is null = " << (mContext->mCamera == nullptr) << std::endl;
    skyboxShader.setUniformMat4("viewMat", mContext->mCamera->getCameraMatrix());
    skyboxShader.setUniformMat4("projMat", mContext->mCamera->getPerspectiveMatrix());

    //render skybox cube
    glBindVertexArray(this->skyboxVao);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->skyTextureId);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    glDepthFunc(GL_LESS);
}

void SkyBox::destory(){
    glDeleteTextures(1 , &skyTextureId);

    glDeleteVertexArrays(1 , &skyboxVao);
    glDeleteBuffers(1 , &skyboxVbo);
}

SkyBox::~SkyBox(){

}


void SykBoxTestApp::init(){
    //do nothing init in resize when get view widht / height
}

void SykBoxTestApp::resize(int width , int height){
    App::resize(width , height);
    mCamera = std::make_shared<Camera>(glm::vec3(0,0,0) , glm::vec3(0,0,-10) , (float)mViewWidth / (float)mViewHeight);
    
    std::string skyImageFolder = "skybox/";
    std::vector<std::string> images = {skyImageFolder + "right.jpg",
                                        skyImageFolder + "left.jpg",
                                        skyImageFolder + "top.jpg",
                                        skyImageFolder + "bottom.jpg",
                                        skyImageFolder + "back.jpg",
                                        skyImageFolder + "front.jpg",
                                        };
    mSkyBox = std::make_shared<SkyBox>(this , images);
    mSkyBox->init();
}

void SykBoxTestApp::update(long deltaTime){
    App::update(deltaTime);

    mSkyBox->render(deltaTime);
}

void SykBoxTestApp::destory(){
    mSkyBox->destory();
    App::destory();
}


