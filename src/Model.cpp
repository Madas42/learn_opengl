//
// Created by Jakub Češka on 18.10.2024.
//

#include "Model.h"
#include <iostream>


Model::Model(const std::vector<float>& verticies) {
    setUpBuffers(verticies);
}

Model::~Model() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void Model::bind() const {
    glBindVertexArray(vao);
}

void Model::unbind() const {
    glBindVertexArray(0);
}

void Model::setUpBuffers(const std::vector<float>& verticies) {
    // VAO
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // VBO
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, verticies.size() * sizeof(float), verticies.data(), GL_STATIC_DRAW);

    // Defining attributes for pinters (3D position for 3 floaths per vertex)
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Unbind VAO and VBO
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl;
    }
}
