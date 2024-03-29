# Compiler specific settings

if(compiler_included)
    return()
endif()
set(compiler_included true)

function(add_compiler_flags)
    foreach(flag ${ARGV})
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${flag}" PARENT_SCOPE)
    endforeach()
endfunction()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    add_compiler_flags(-Wall)
    add_compiler_flags(-Wextra)
    add_compiler_flags(-Wpedantic)
    add_compiler_flags(-Wshadow)
    add_compiler_flags(-Wnon-virtual-dtor)
    add_compiler_flags(-Wcast-align)
    add_compiler_flags(-Wunused)
    add_compiler_flags(-Woverloaded-virtual)
    add_compiler_flags(-Wconversion)
    add_compiler_flags(-Wsign-conversion)
    add_compiler_flags(-Wmisleading-indentation)
    add_compiler_flags(-Wduplicated-cond)
    add_compiler_flags(-Wduplicated-branches)
    add_compiler_flags(-Wlogical-op)
    add_compiler_flags(-Wnull-dereference)
    add_compiler_flags(-Wuseless-cast)
    add_compiler_flags(-Wdouble-promotion)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compiler_flags(/W14640)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS) # Suppress C4996
    add_compiler_flags(/permissive-) # force standard conformance
endif()
