#include <stdexcept>
#include "shader.hpp"

namespace OpenGL {

Shader::Shader(const char* source, Shader::Type type) :
    type{type},
    source{source},
    id{glCreateShader(GLenum(type))}
{
}

Shader::~Shader()
{
    glDeleteShader(id);
}

void Shader::compile()
{
    glShaderSource(id, 1, &source, nullptr);
    glCompileShader(id);
    check_compiled();
}

void Shader::check_compiled() const
{
    int success;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        constexpr int max_log_size = 512;
        char info_log[max_log_size];
        glGetShaderInfoLog(id, max_log_size, nullptr, static_cast<char*>(info_log));
        throw std::runtime_error{static_cast<char*>(info_log)};
    }
}

} // namespace OpenGL
