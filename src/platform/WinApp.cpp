#include "gl.h"
#include <GLFW/glfw3.h>
#include "App.h"
#include <iostream>
#include <chrono>

long long lastRenderTime;

App app;

static void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
		return;
    }
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    app.resize(width , height);
}

long long currentTime(){
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
	return ms.count();
}

int main(int argc , char **argv){
    GLFWwindow *window = nullptr;

    glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // --------------------
    window = glfwCreateWindow(800, 600, "Yoki Windows", nullptr, nullptr);
	
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

	glEnable(GL_DEPTH_TEST);//开启深度测试

    app.init();

    //main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

		
		long long deltaTime = 0;
		long long currentTimeM = currentTime();
		if(lastRenderTime > 0){
			deltaTime = currentTimeM - lastRenderTime;
		}
		lastRenderTime = currentTimeM;
		
        app.update(deltaTime);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	app.destory();

	glfwTerminate();
    return 0;
}