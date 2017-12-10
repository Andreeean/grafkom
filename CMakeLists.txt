cmake_minimum_required(VERSION 3.8)
project(FP)

set(CMAKE_CXX_STANDARD 17)
find_package (OpenGL REQUIRED)

add_subdirectory (external)

cmake_policy (SET CMP0026 OLD)
list (APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include (CreateLaunchers)
include (MSVCMultipleProcessCompile) # /MP

if (INCLUDE_DISTRIB)
    add_subdirectory (distrib)
endif (INCLUDE_DISTRIB)

include_directories (
        external/AntTweakBar-1.16/include/
        external/glfw-3.1.2/include/GLFW/
        external/glm-0.9.7.1/
        external/glew-1.13.0/include/
        external/assimp-3.0.1270/include/
        external/bullet-2.81-rev2613/src/
        .
)

set (ALL_LIBS
        ${OPENGL_LIBRARY}
        glut32
        glfw
        GLEW_1130
        )

add_definitions (
        -DTW_STATIC
        -DTW_NO_LIB_PRAGMA
        -DTW_NO_DIRECT3D
        -DGLEW_STATIC
        -D_CRT_SECURE_NO_WARNINGS
)

set (CONTROLS_AND_SHADER
        common/controls.cpp
        common/controls.hpp
        common/shader.cpp
        common/shader.hpp
        cmake-build-debug/ColorFragmentShader.fragmentshader
        cmake-build-debug/TransformVertexShader.vertexshader
        )

set (BASE_OPENGL
        main.hpp
        opengl.hpp
        opengl.cpp
        )

file (GLOB_RECURSE OPENGL_OBJECTS "customs/*")

add_executable (main
        main.cpp
        ${OPENGL_OBJECTS}
        ${CONTROLS_AND_SHADER}
        )
target_link_libraries (main ${ALL_LIBS})
