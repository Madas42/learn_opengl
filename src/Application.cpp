//
// Created by Jakub Češka on 18.10.2024.
//

#include "Application.h"
#include "Scene.h"
#include "DrawableObject.h"

std::vector<float> verticesTriangle0 = {
    // Vertex positions       // Colors (R, G, B)
    0.0f,  0.57735f, 0.0f,    1.0f, 0.0f, 1.0f, // Top vertex (Purple)
   -0.5f, -0.28868f, 0.0f,    1.0f, 0.5f, 0.0f, // Bottom-left vertex (Orange)
    0.5f, -0.28868f, 0.0f,    0.0f, 1.0f, 0.0f  // Bottom-right vertex (Green)
};
void Application::framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);

    auto* scene = static_cast<Scene*>(glfwGetWindowUserPointer(window));
    if (scene && !scene->getShaderPrograms().empty()) {
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 0.1f, 100.0f);
        scene->getShaderPrograms()[0]->setProjectionMatrix(projection);
    }
}

void Application::processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

void Application::init() {
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window = glfwCreateWindow(width, height, "Learn OpenGL", nullptr, nullptr);
    if (window == nullptr) {
        printf("Failed to crate GLFW window\n");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Set render window
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        printf("Failed to initialize GLEW\n");
        return;
    }

    // Set the framebuffer size callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetWindowUserPointer(window, &scene);
}

void Application::createShaders() {
    shaderProgram = new ShaderProgram("shaders/vertexShaderTriangle.glsl", "shaders/fragmentShaderTriangle.glsl");
    scene.addShaderProgram(shaderProgram);
}

void Application::createModels() {
    object = new DrawableObject(verticesTriangle0, shaderProgram);
    scene.addObject(object);

    // Set the initial projection matrix
    glfwGetFramebufferSize(window, &width, &height);
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), static_cast<float>(width) / static_cast<float>(height), 1.0f, 100.0f);
    shaderProgram->use();
    shaderProgram->setProjectionMatrix(projection);
}


void Application::run() {
    // Render loop
    while (!glfwWindowShouldClose(window)) {
        // Input
        processInput(window);
        glClearColor(0.11f, 0.008f, 0.004f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        //Render Scene
        scene.render();

        // Check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}