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
    DrawableObject* object1 = new DrawableObject(vertices1);
    objects.push_back(object1);
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
    for (auto object : objects) {
        object->draw();
    }
}