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
    void addShaderProgram(ShaderProgram* shaderProgram);
    void render();
    const std::vector<ShaderProgram*>& getShaderPrograms() const;

private:
    std::vector<DrawableObject*> objects;
    std::vector<ShaderProgram*> shaderPrograms;
};

#endif //SCENE_H
