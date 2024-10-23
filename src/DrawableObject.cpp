//
// Created by Jakub Češka on 18.10.2024.
//

#include "DrawableObject.h"

DrawableObject::DrawableObject(const std::vector<float>& verticies) {
    model = new Model(verticies);
}

DrawableObject::~DrawableObject() {
    delete model;
}

void DrawableObject::draw() {
    model->bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
    model->unbind();
}
