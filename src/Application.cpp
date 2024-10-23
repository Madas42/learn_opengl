//
// Created by Jakub Češka on 18.10.2024.
//

#include "Application.h"
#include "Scene.h"
#include "DrawableObject.h"

void Application::framebuffer_size_callback (GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Application::processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Application::run() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LOG", nullptr, nullptr);
    if (window == nullptr) {
        printf("Failed to crate GLFW window\n");
        glfwTerminate();
        return;
    }

    // Set render window
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return;
    }

    glViewport(0, 0, 800, 600);

    // Window resizing
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    Scene scene;

    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Render Scene
        scene.render();

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
}