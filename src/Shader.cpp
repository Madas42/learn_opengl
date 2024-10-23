//
// Created by Jakub Češka on 18.10.2024.
//

#include "Shader.h"

Shader::Shader (GLenum type, const char* source) {
    id = glCreateShader(type);
    glShaderSource(id, 1, &source, NULL);
    glCompileShader(id);
    printf("Shader created\n");
}

Shader::~Shader() {
    glDeleteShader(id);
}

GLuint Shader::getID() const {
    return id;
}

char* Shader::loadShaderSource(const char* filePath) {
    std::ifstream shaderFile(filePath);
    if (!shaderFile.is_open()) {
        std::cerr << "Failed to open shader file: " << filePath << std::endl;
        return nullptr;
    }

    std::stringstream shaderStream;
    shaderStream << shaderFile.rdbuf();
    std::string shaderCode = shaderStream.str();
    char* shaderSource = new char[shaderCode.size() + 1];
    std::copy(shaderCode.begin(), shaderCode.end(), shaderSource);
    shaderSource[shaderCode.size()] = '\0';

    return shaderSource;
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
