add_library(common
    application.hpp
    application.cpp
    shader.hpp
    shader.cpp
    shader_program.hpp
    shader_program.cpp
    )

target_link_libraries(common glad glfw glm)

set_target_properties(
    common PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_FLAGS "${WARNING_FLAGS}"
    )
