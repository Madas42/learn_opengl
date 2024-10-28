//
// Created by Jakub Češka on 18.10.2024.
//

#include "Scene.h"

Scene::Scene() {
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

void Scene::addShaderProgram(ShaderProgram* shaderProgram) {
    shaderPrograms.push_back(shaderProgram);
}


void Scene::render() {
    shaderPrograms[0]->use();
    for (auto object : objects) {
        object->draw();
    }
}

const std::vector<ShaderProgram*>& Scene::getShaderPrograms() const {
    return shaderPrograms;
}