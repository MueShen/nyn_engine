cmake_minimum_required(VERSION 3.10)
project(cyt_engine LANGUAGES C)


find_package(OpenGL)



file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "src/include/*.h")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")



add_executable(core ${SOURCES} ${HEADERS})
add_subdirectory(vendor/glfw-3.4)
target_compile_options(core PRIVATE -Wall -Wextra )

target_include_directories(core PUBLIC ${OPENGL_INCLUDE_DIR}) 
target_link_directories(core PUBLIC  ${OPENGL_INCLUDE_DIR})
target_link_libraries(core ${OPENGL_gl_LIBRARY} glfw )
