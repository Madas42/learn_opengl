//
// Created by Jakub Češka on 18.10.2024.
//

#ifndef SHADER_H
#define SHADER_H
#include <GL/glew.h>
#include <iostream>


class Shader {
public:
    Shader(GLenum type, const char* source);
    ~Shader();

    GLuint getID() const;

private:
    GLuint id;
    void checkCompileErrors(GLuint shader, const char* type);
};



#endif //SHADER_H
