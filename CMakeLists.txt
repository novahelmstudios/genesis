cmake_minimum_required(VERSION 3.21)
project(genesis)

set(CMAKE_CXX_STANDARD 17)

# Set src and include
include_directories(include)
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# External libraries
add_subdirectory(external/glfw)
add_subdirectory(external/glm)

add_executable(MyOpenGLGame ${SOURCES})
target_link_libraries(MyOpenGLGame glfw glm)
