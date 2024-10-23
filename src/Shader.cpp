//
// Created by Jakub Češka on 18.10.2024.
//

#include "Shader.h"

Shader::Shader (GLenum type, const char* source) {
    id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);
}

Shader::~Shader() {
    glDeleteShader(id);
}

GLuint Shader::getID() const {
    return id;
}

void Shader::checkCompileErrors(GLuint shader, const char* type) {
    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\nType: %s\nLog:\n%s\n", type, infoLog);
    }
}
