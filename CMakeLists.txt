cmake_minimum_required(VERSION 3.14)
project(genesis)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)

# Source files (include glad.c if needed)
file(GLOB_RECURSE SRC
    src/*.cpp
    src/*.c   # Include glad.c if it's inside src or similar
)

add_executable(genesis ${SRC})

# Find OpenGL
find_package(OpenGL REQUIRED)

# Find GLFW using pkg-config
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

# Find FreeType using pkg-config
pkg_search_module(FREETYPE REQUIRED freetype2)

# Include directories for GLFW and FreeType
target_include_directories(genesis PRIVATE
    ${GLFW_INCLUDE_DIRS}
    ${FREETYPE_INCLUDE_DIRS}
)

# Link libraries for GLFW, FreeType, OpenGL, and dl
target_link_libraries(genesis PRIVATE
    ${GLFW_LIBRARIES}
    ${FREETYPE_LIBRARIES}
    OpenGL::GL
    dl
)
