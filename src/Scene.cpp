//
// Created by Jakub Češka on 18.10.2024.
//

#include "Scene.h"

std::vector<float> vertices1 = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

Scene::Scene() {
    shaderProgram = new ShaderProgram("shaders/vertexShaderTriangle.glsl", "shaders/fragmentShaderTriangle.glsl");
    DrawableObject* object1 = new DrawableObject(vertices1, shaderProgram);
    objects.push_back(object1);
    printf("Scene created\n");
}

Scene::~Scene() {
    for (auto object : objects) {
        delete object;
    }
}

void Scene::addObject(DrawableObject* object) {
    objects.push_back(object);
}

void Scene::render() {
    shaderProgram->use();
    for (auto object : objects) {
        object->draw();
    }
}