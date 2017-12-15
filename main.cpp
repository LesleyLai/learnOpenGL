#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "common/window.hpp"

void glfw_error(int error, const char* description)
{
    std::cerr << "GLFW Error " << error << ": " << description << '\n';
}

int main()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwSetErrorCallback(glfw_error);

    {
        Window window;
        while (!window.should_close())
        {
            window.update();
        }
    }

    // FIXME: The below line cause crash
    // glfwTerminate();
    return 0;
}
