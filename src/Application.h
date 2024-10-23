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
    void run();

private:
    void static framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);

};



#endif //APPLICATION_H
