//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef SCENE_H
#define SCENE_H

#include "DrawableObject.h"
#include "ShaderProgram.h"

class Scene {
public:
    Scene();
    ~Scene();

    void addObject(DrawableObject* object);
    void render();

private:
    std::vector<DrawableObject*> objects;
    ShaderProgram* shaderProgram;
};

#endif //SCENE_H
