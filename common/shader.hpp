#pragma once

#include "glad/glad.h"

namespace OpenGL {

/**
 * @ingroup opengl
 * @brief The Shader class
 */
struct Shader {
public:
    /// OpenGL_shader type
    enum class Type {
        Vertex = GL_VERTEX_SHADER,
        Fragment = GL_FRAGMENT_SHADER,
        Geometry = GL_GEOMETRY_SHADER,
        Compute = GL_COMPUTE_SHADER
    };

    /// Type of the shader
    const Type type;
    /// Source of the shader
    const char* source;
    ///The OpenGL assigned id of this shader.
    const unsigned int id;

    Shader(const char* source, Type type);
    ~Shader();

    /// Compiles this OpenGL_shader
    void compile();


private:
    void check_compiled() const;
};

} // namespace OpenGL

