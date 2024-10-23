//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef MODEL_H
#define MODEL_H

#include <GL/glew.h>
#include <vector>

class Model {
public:
    Model(const std::vector<float>& verticies);
    ~Model();

    void bind() const;
    void unbind() const;

private:
    GLuint vao;
    GLuint vbo;

    void setUpBuffers(const std::vector<float>& verticies);
};



#endif //MODEL_H
