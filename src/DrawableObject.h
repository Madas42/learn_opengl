//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include "Model.h"
#include "Transformation.h"
#include "ShaderProgram.h"

class DrawableObject {
public:
    DrawableObject(const std::vector<float>& verticies, ShaderProgram* shader);
    ~DrawableObject();

    void draw();
private:
    Model* model;
    ShaderProgram* shaderProgram;
};



#endif //DRAWABLEOBJECT_H
