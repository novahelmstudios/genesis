cmake_minimum_required(VERSION 3.14)
project(genesis)

set(CMAKE_CXX_STANDARD 20)

# Include directories
include_directories(include)
include_directories(glad/include)

# Source files
file(GLOB_RECURSE SRC src/*.cpp)
set(GLAD_SRC include/glad/src/glad.c)

# Create executable
add_executable(genesis ${SRC} ${GLAD_SRC})

# Link libraries
find_package(OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

target_include_directories(genesis PRIVATE ${GLFW_INCLUDE_DIRS})
target_link_libraries(genesis PRIVATE ${GLFW_LIBRARIES} OpenGL::GL dl)
