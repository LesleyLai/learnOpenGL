add_library(common
    window.hpp
    window.cpp)

target_link_libraries(common glad glfw)

set_target_properties(
    common PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_FLAGS "${WARNING_FLAGS}"
    )
