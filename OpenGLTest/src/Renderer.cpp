#include "Renderer.h"

#include <iostream>

void GLClearErrors() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall() {
    if (GLenum error = glGetError()) {
        std::cout << "[OPENGL ERROR] (" << error << ")" << std::endl;
        return false;
    }
    return true;
}
