cmake_minimum_required(VERSION 3.6)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.22.16.tar.gz"
    SHA1 "84153076a3cebf4869c904fa5c93ea309386b583"
)

set(HUNTER_PACKAGE_LOG_BUILD ON)

project(learnOpenGL)

add_subdirectory(third-party EXCLUDE_FROM_ALL)

## GLFW
hunter_add_package(glfw)
find_package(glfw3 CONFIG REQUIRED)

set (CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(common)

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries(${PROJECT_NAME} common)

set_target_properties(
    learnOpenGL PROPERTIES
    COMPILE_FLAGS "${WARNING_FLAGS}"
    )

include("cmake/clangTidy.cmake")

if(CLANG_TIDY_EXE)
    set_target_properties(
        common learnOpenGL
        PROPERTIES
        CXX_CLANG_TIDY "${DO_CLANG_TIDY}"
        )
endif()
