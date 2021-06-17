#include "Shape.h"
#include <string>
#include <iostream>

#include "glsl.h"

void Triangle::onInit(){

    //std::string vertexSrc = "#version 330 es\n layout(location = 0) in vec2 aPos;\n void main() {\n gl_Position = vec4(aPos ,0.0 , 1.0); \n}";
    //std::string fragSrc = "#version 330 es\n out vec4 FragColor;\n void main(){\n FragColor = vec4(1.0f , 0.0f , 0.0f , 1.0f);\n}";

    std::string vertexSrc = GLSL( 
        layout(location = 0) in vec2 aPos;
        void main(){
            gl_Position = vec4(aPos.x , aPos.y ,0.0 , 1.0);
        }
    );

    std::string fragSrc = GLSL(
        out vec4 FragColor;
        void main(){
            FragColor = vec4(0.0f , 1.0f , 1.0f , 1.0f);
        }
    );

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

Cube::Cube(App *appContext){
    this->context = appContext;
}

Cube::~Cube(){
}

void Cube::onInit(int viewWidth , int viewHeight){
    camera = new Camera(glm::vec3(0,3,-5) , glm::vec3(0,0,0) , (float)viewWidth / (float)viewHeight);

    std::string vertexSrc = GLSL( 
        layout(location = 0) in vec3 aPos;
        layout(location = 1) in vec2 aTexCoord;

        uniform mat4 modelMat;
        uniform mat4 viewMat;
        uniform mat4 projMat;

        out vec2 vTexCoord;

        void main() {
            gl_Position = projMat * viewMat * modelMat * vec4(aPos, 1.0);
            vTexCoord = aTexCoord;
        }
    );

    std::string fragSrc = GLSL(
        in vec2 vTexCoord;
        uniform sampler2D imageTexture;

        out vec4 fragColor;

        void main(){
            // fragColor = vec4(0.0 , 0.0 , 1.0 , 1.0);
            //fragColor = vec4(1.0 , 0.0 , 0.0 , 1.0);
            vec4 color1 = texture(imageTexture , vTexCoord);
            fragColor = color1;
        }
    );

    shader = Shader::buildGPUProgram(vertexSrc , fragSrc);

    buildTexture();
    glGenVertexArrays(1 , &vao);
    glGenBuffers(1 , &vbo);
    
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER , vbo);
    glBufferData(GL_ARRAY_BUFFER , sizeof(vertices) , vertices , GL_STATIC_DRAW);

    //set vertex attr
    glVertexAttribPointer(0 , 3 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , (void *)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1 , 2 , GL_FLOAT , GL_FALSE , 5 * sizeof(float) , (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

void Cube::buildTexture(){
    TextureInfo info = context->loadAssetsTexture("box2.png" , true);
    this->textureId = info.textureId;
}

void Cube::onRender(long deltaTime){
    shader.useShader();
    glBindVertexArray(vao);

    glm::mat4 modelMat = glm::mat4(1.0f);
    modelMat = glm::translate(modelMat, this->positon);
    modelMat = glm::rotate(modelMat , this->angleX , glm::vec3(1 ,  0, 0));
    modelMat = glm::rotate(modelMat , this->angleY , glm::vec3(0 ,  1, 0));
    modelMat = glm::rotate(modelMat , this->angleZ , glm::vec3(0 ,  0, 1));

    //std::cout << "deltaTime = " << deltaTime << std::endl; 
    angleY += deltaTime * (this->moveSpeed);
    this->positon.x = glm::sin(angleY);

    //modelMat = glm::scale(modelMat , glm::vec3(3 , 3 , 3));
    glm::vec3 cameraPosition = camera->getPostion();
    cameraPosition[2] += 1.0;
    camera->lookAt(glm::vec3(0,0,0));
    
    shader.setUniformMat4("modelMat" , modelMat);

    glm::vec3 p = camera->getPostion();
    //std::cout << "pos = " << p[0] << " " << p[1] << " " << p[2] << std::endl;
    
    shader.setUniformMat4("viewMat", camera->getCameraMatrix());
    shader.setUniformMat4("projMat", camera->getPerspectiveMatrix());

    glBindTexture(GL_TEXTURE_2D , this->textureId);

    glDrawArrays(GL_TRIANGLES , 0 , 36);
    
    glBindVertexArray(0);
}

void Cube::onDestory(){
    glDeleteVertexArrays(1 , &vao);
    glDeleteBuffers(1 , &vbo);

    if(camera != nullptr){
        delete camera;
        camera = nullptr;
    }
}
