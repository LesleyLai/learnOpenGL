#include <cstdlib>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "window.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

Window::Window() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    window_ = glfwCreateWindow(800, 600, "Hello World", nullptr, nullptr);

    if (!window_)
    {
        glfwTerminate();
        std::exit(-1);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window_);


    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        std::exit(-1);
    }
    glfwSwapInterval(1);

    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window_, framebuffer_size_callback);
}

Window::~Window() {
    if (window_) glfwDestroyWindow(window_);
}

void Window::render() const {
    /* Render here */
    glClearColor(0.0f, 0.3f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Window::update() const {
    processInput(window_);

    /* Render here */
    render();

    /* Swap front and back buffers */
    glfwSwapBuffers(window_);

    /* Poll for and process events */
    glfwPollEvents();
}

bool Window::should_close() const {
    return glfwWindowShouldClose(window_);
}
