//
// Created by Jakub Češka on 18.10.2024.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {
    Shader vertexShader(GL_VERTEX_SHADER, vertexShaderSource);
    Shader fragmentShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

    id = glCreateProgram();
    glAttachShader(id, vertexShader.getID());
    glAttachShader(id, fragmentShader.getID());
    glLinkProgram(id);

    checkCompileErrors(id, "PROGRAM");
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(id);
}

void ShaderProgram::use() const {
    glUseProgram(id);
}

GLuint ShaderProgram::getID() const {
    return id;
}

void ShaderProgram::checkCompileErrors(GLuint shader, const std::string& type) {
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            printf("ERROR::SHADER_COMPILATION_ERROR of type: %s\n%s\n", type.c_str(), infoLog);
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            printf("ERROR::SHADER_LINKING_ERROR of type: %s\n%s\n", type.c_str(), infoLog);
        }
    }
}

