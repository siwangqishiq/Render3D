#include "Shape.h"

#include <string>
#include <iostream>

void Triangle::onInit(){

    std::string vertexSrc = "#version 330 es\n layout(location = 0) in vec2 aPos;\n void main() {\n gl_Position = vec4(aPos ,0.0 , 1.0); \n}";

    std::string fragSrc = "#version 330 es\n out vec4 FragColor;\n void main(){\n FragColor = vec4(1.0f , 0.0f , 0.0f , 1.0f);\n}";

    shader = Shader::buildGPUProgram(vertexSrc , fragSrc);

    glGenVertexArrays(1 , &vao);
    glGenBuffers(1 , &vbo);

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER , vbo);
    glBufferData(GL_ARRAY_BUFFER , sizeof(vertices) , vertices , GL_STATIC_DRAW);

    glVertexAttribPointer(0 , 2 , GL_FLOAT , GL_FALSE , 2 * sizeof(float) , (void *)0);
    glEnableVertexAttribArray(0);
 }

void Triangle::onRender(){
    shader.useShader();

    //std::cout << "shader = " << shader.getProgramId() << std::endl;

    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLE_FAN , 0 , 3);
}
    
void Triangle::onDestory(){
    glDeleteBuffers(1 , &vbo);
}