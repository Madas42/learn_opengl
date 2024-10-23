//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef SHADER_H
#define SHADER_H
#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>


class Shader {
public:
    Shader(GLenum type, const char* source);
    ~Shader();

    GLuint getID() const;
    static char* loadShaderSource(const char* filePath);

private:
    GLuint id;

    void checkCompileErrors(GLuint shader, const char* type);
};



#endif //SHADER_H
