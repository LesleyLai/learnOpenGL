#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "common/application.hpp"
#include "common/shader.hpp"
#include "common/shader_program.hpp"

constexpr const char* vertex_shader_src = "#version 400 core\n"
                                          "layout (location = 0) in vec3 pos;"
                                          "void main() {"
                                          "  gl_Position = vec4(pos, 1.0);"
                                          "}";

constexpr const char* fragment_shader_src =
    "#version 400 core\n"
    "out vec4 frag_colour;"
    "void main() {"
    "  frag_colour = vec4(1, 0, 0, 1.0);"
    "}";

class TriangleApp : public Application {
public:
  TriangleApp()
  {
    glClearColor(0.0f, 0.3f, 0.8f, 1.0f);

    const float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                              0.0f,  0.0f,  0.5f, 0.0f};

    init_shaders();

    // VAO
    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);

    //  copy our vertices array in a buffer for OpenGL to use
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // set the vertex attributes pointers
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(float),
                          reinterpret_cast<void*>(0));
    glEnableVertexAttribArray(0);
  }

  void init_shaders()
  {
    OpenGL::Shader vertex_shader(vertex_shader_src,
                                 OpenGL::Shader::Type::Vertex);
    vertex_shader.compile();
    OpenGL::Shader fragment_shader(fragment_shader_src,
                                   OpenGL::Shader::Type::Fragment);
    fragment_shader.compile();

    program_.attach(vertex_shader);
    program_.attach(fragment_shader);
    program_.link();
    program_.use();
  }

  void render() const override
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program_.use();
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, 3);
  }

private:
  unsigned int vao_ = 0;
  OpenGL::Program program_;
};

int main()
{
  TriangleApp app;
  return app.run();
}
