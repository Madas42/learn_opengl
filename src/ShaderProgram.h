//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H
#include <GL/glew.h>
#include <iostream>
#include "Shader.h"

const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

class ShaderProgram {
private:
    GLuint id;
    void checkCompileErrors(GLuint shader, const std::string& type);

public:
    ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);
    ~ShaderProgram();

    void use() const;
    GLuint getID() const;
};



#endif //SHADERPROGRAM_H
