#include <stdio.h>
#include "glad.h"
#include "GLFW/glfw3.h"
#include "include/windowing.h"
#include "include/input.h"

void renderPass(GLFWwindow* window);

GLFWwindow *window= NULL;

int wnd_Init(){
	glfwInit();
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
    	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window= glfwCreateWindow(800,600, "Not Yet Null Enginie 0.0.1", NULL, NULL);
	if ( window== NULL){
		printf("FAILED TO CREATE GLFW WINDOW \n");
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window); //init of statemachibe, setting window as curre t context, all other commands will be addressing this window 	
	//glad init (extensions a d function pointers)
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_FALSE);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		printf("Failed to initialize GLAD\n");
		return -1;
	}    
	glViewport(0,0,800,600);
	wnd_RenderLoop();
	//onWindowSizeChange
	glfwSetFramebufferSizeCallback(window,framebuffer_size_callback);
	return 0;

}




int wnd_RenderLoop(){	
	while(!glfwWindowShouldClose(window)){
		handleInput(window);
		renderPass(window);
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	glfwTerminate();
	return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height){	
 (void)window; //simple discard
	glViewport(0,0,width,height);		
}


void renderPass(GLFWwindow *window){
	(void)window;
}

