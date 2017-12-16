#pragma once

namespace OpenGL {
struct Shader;

/**
 * @ingroup opengl
 * @brief An OpenGL shader program
 */
struct Program {
    /// The OpenGL assigned id of this shader program
    const unsigned int id;

    Program();

    /// Attaches a shader to this program
    void attach(const Shader& shader);

    /// @brief Links the shader program
    /// @throw std::runtime_error if fail
    void link();

    // Uses this shader program as current shader
    // Todo: remove this method and use a stateless way to manupulate shaders
    void use() const;

    ///@{
    void set_uniform(const char* name, float value) const;
    void set_uniform(const char* name, double value) const;
    void set_uniform(const char* name, int value) const;
    void set_uniform(const char* name, bool value) const;
    void set_uniform(const char* name, unsigned int value) const;
    ///@}

};

}
