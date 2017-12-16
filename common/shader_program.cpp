#include <stdexcept>

#include "shader_program.hpp"
#include "shader.hpp"

namespace OpenGL {

Program::Program() : id{glCreateProgram()} {

}

void Program::attach(const Shader& shader)
{
    glAttachShader(id, shader.id);
}

void Program::link()
{
    glLinkProgram(id);

    int  success;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success) {
        constexpr int max_log_size = 512;
        char info_log[max_log_size];
        glGetProgramInfoLog(id, max_log_size, nullptr, static_cast<char*>(info_log));
        throw std::runtime_error{static_cast<char*>(info_log)};
    }
}

void Program::use() const
{
    glUseProgram(id);
}

/**
 * @brief Sets a glsl uniform variable
 * @param name Name of the variable in shader
 * @param value Value of the variable
 */
void Program::set_uniform(const char* name, float value) const
{
    glUniform1f(glGetUniformLocation(id, name), value);
}

void Program::set_uniform(const char* name, double value) const
{
    glUniform1d(glGetUniformLocation(id, name), value);
}

void Program::set_uniform(const char* name, int value) const
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

void Program::set_uniform(const char* name, bool value) const
{
    glUniform1i(glGetUniformLocation(id, name), value);
}

void Program::set_uniform(const char* name, unsigned int value) const
{
    glUniform1ui(glGetUniformLocation(id, name), value);
}

//void Program::set_uniform(const char* name, const math::Mat4& value) const
//{
//    glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, value.data());
//}


} // namespace OpenGL
