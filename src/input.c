#include "GLFW/glfw3.h"
#include <stdio.h>
#include "include/input.h"

void handleInput(GLFWwindow* window){
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        	glfwSetWindowShouldClose(window, true);
}

