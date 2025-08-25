#include <stdio.h>
#include "glad.h"
#include "GLFW/glfw3.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height){	
	glViewport(0,0,width,height);		
}

int main (){
	glfwInit();
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window= glfwCreateWindow(800,600, "Not Yet Null Enginie 0.0.1", NULL, NULL);
	if ( window== NULL){
		printf("FAILED TO CREATE GLFW WINDOW \n");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	
	//glad init
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD\n");
		return -1;
	}    
	glViewport(0,0,800,600);
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();    
	}
	glfwTerminate();
	return 0;
}






