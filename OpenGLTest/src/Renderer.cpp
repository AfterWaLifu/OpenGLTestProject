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

void Renderer::Clear() const
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const Shader& shader) const
{
    shader.Bind();
    va.Bind();
    ib.Bind();
    glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr);
}
