cmake_minimum_required(VERSION 3.10)
project(nyn_engine LANGUAGES C)

set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL)



file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")



add_executable(core ${SOURCES} ${HEADERS})
add_library(glad STATIC "vendor/glad/glad.c")
target_include_directories(glad PRIVATE "vendor/glad/")

add_subdirectory(vendor/glfw-3.4)
target_compile_options(core PRIVATE -Wall -Wextra )

target_include_directories(core PUBLIC ${OPENGL_INCLUDE_DIR} "vendor/glad/") 
target_link_directories(core PUBLIC  ${OPENGL_INCLUDE_DIR})
target_link_libraries(core ${OPENGL_gl_LIBRARY} glfw glad )

if(UNIX)
	SET(CMAKE_C_FLAGS "-lGL -lX11 -lpthread -lXrandr -lXi -ldl")

endif(UNIX)
