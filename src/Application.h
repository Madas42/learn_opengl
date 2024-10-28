//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Scene.h"

class Application {
public:
    void init();
    void createShaders();
    void createModels();
    void run();
    static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

private:
    int width = 800;
    int height = 600;
    GLFWwindow* window;
    Scene scene;
    ShaderProgram* shaderProgram;
    DrawableObject* object;

    static void processInput(GLFWwindow* window);
};



#endif //APPLICATION_H
