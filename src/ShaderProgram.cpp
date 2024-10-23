//
// Created by Jakub Češka on 18.10.2024.
//

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexShaderPath, const char* fragmentShaderPath) {
    Shader vertexShader(GL_VERTEX_SHADER, Shader::loadShaderSource(vertexShaderPath));
    Shader fragmentShader(GL_FRAGMENT_SHADER, Shader::loadShaderSource(fragmentShaderPath));

    id = glCreateProgram();
    glAttachShader(id, vertexShader.getID());
    glAttachShader(id, fragmentShader.getID());
    glLinkProgram(id);

    checkCompileErrors(id, "PROGRAM");
    printf("Shader program created\n");
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

void ShaderProgram::checkCompileErrors(GLuint shader, const char* type) {
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
            printf("ERROR::SHADER_COMPILATION_ERROR of type: %s\n%s\n", type, infoLog);
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
            printf("ERROR::SHADER_LINKING_ERROR of type: %s\n%s\n", type, infoLog);
        }
    }
}

