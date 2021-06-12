/**
 * 基础图元  
 * */

#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "gl.h"
#include "Shader.h"

class Triangle{
private:
    unsigned int vao;
    unsigned int vbo;

    Shader shader;

    float vertices[3 * 2] = {
        -0.5f , -0.5f,
         0.5f , -0.5f,
         0.0f ,  0.5f 
    };

public:
    void onInit();
    void onRender();
    void onDestory();
};

#endif