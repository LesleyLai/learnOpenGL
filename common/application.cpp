#include <iostream>
#include <sstream>
#include <stdexcept>

#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "application.hpp"

void framebuffer_size_callback(GLFWwindow*, int width, int height)
{
    glViewport(0, 0, width, height);
}

[[noreturn]] void glfw_error(int error, const char* description) {
    std::ostringstream ss;
    ss << "GLFW Error " << error << ": " << description << '\n';
    throw std::runtime_error{ss.str()};
}

Application::Application(int width, int height) {
    if (!glfwInit())
        throw std::runtime_error{"cannot initialize GLFW."};

    glfwSetErrorCallback(glfw_error);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window_ = glfwCreateWindow(width, height, "Hello World", nullptr, nullptr);

    if (!window_)
    {
        glfwTerminate();
        std::exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window_);
    glfwSwapInterval(1);

    if (!gladLoadGL()) {
        throw std::runtime_error{ "Failed to initialize GLAD" };
    }

    if (!GLAD_GL_VERSION_4_3) {
        throw std::runtime_error{ "The system do not support OpenGL 4.3 or later version." };
    }

    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
}

Application::~Application() {
    if (window_) glfwDestroyWindow(window_);

    // TODO: This cause the program to crash
    //glfwTerminate();
}

int Application::run()
try {
    while (!glfwWindowShouldClose(window_))
    {
        // render here
        render();

        /* Swap front and back buffers */
        glfwSwapBuffers(window_);

        /* Poll for and process events */
        glfwPollEvents();
    }
    return 0;
} catch (std::runtime_error& e) {
    std::cerr << e.what() << '\n';
    return -1;
} catch (...) {
    std::cerr << "Unknown exception\n";
    return -100;
}
