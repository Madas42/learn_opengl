//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <iostream>
#include "Shader.h"

class ShaderProgram {
private:
    GLuint id;
    void checkCompileErrors(GLuint shader, const char* type);

public:
    ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath);
    ~ShaderProgram();

    void use() const;
    GLuint getID() const;
    void setProjectionMatrix(const glm::mat4& projectionMatrix) const;
};



#endif //SHADERPROGRAM_H
