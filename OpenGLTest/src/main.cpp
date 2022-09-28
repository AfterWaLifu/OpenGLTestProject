#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>

#include "Renderer.h"

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(1280, 720, "Testing OpenGL", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        return -1;

    glfwSwapInterval(1);

    std::cout << glGetString(GL_VERSION) << std::endl;

    float vertexes[] = {
        -0.5f,-0.5f,
         0.5f,-0.5f,
        -0.5f, 0.5f,
         0.5f, 0.5f
    };

    unsigned int indices[] = {
        0,1,3,
        3,2,0
    };

    VertexArray va;
    VertexBuffer vb(vertexes, 8 * sizeof(float));    

    VertexBufferLayout layout;
    layout.Push<float>(2);
    va.addBuffer(vb, layout);

    IndexBuffer ib(indices, 6);

    Shader shader("res/vertex.vert", "res/fragment.frag");

    va.Unbind();
    vb.Unbind();
    ib.Unbind();
    shader.Unbind();

    float color = 0.0f;
    float increment = 0.05f;

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        shader.Bind();
        shader.SetUniform4f("u_Color", color, color, color, 1.0f);

        va.Bind();
        ib.Bind();

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        color += increment;
        if (color >= 0.99f) increment = -0.01f;
        else if (color <= 0.01f) increment = 0.01f;

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}