#include "GLFW/glfw3.h"
#include "include/fileworks.h"

struct Shader{
public: 
	unsigned int ID;

	void loadShader(char[] vertexPath, char[] fragmentPath){
		char[]	*vertCode;
		char[]	*fragCode;
		vertCode=loadFile(vertexPath,10);
		fragCode=loadFile(fragmentPath,10);

		unsigned int vertex,framgnet;
		int success;
		char infolog[512];

		vertex=glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vertCode, NULL);
		glCompileShader(vertex);
		glGetShaderiv(vertex,GL_COMPILE_STATUS, &success);
		if(!success){
			glGetShaderInfoLog(vertex, 512, NULL, infolog);
			printf(infolog);
		}
		
		fragment=glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fragCode, NULL);
		glCompileShader(fragment);
		glGetShaderiv(fragment,GL_COMPILE_STATUS, &success);
		if(!success){
			glGetShaderInfoLog(fragment, 512, NULL, infolog);
			printf(infolog);
		}

		ID=glCreateProgram();
		glAttachShader(ID, vertex);
		glAttachShader(ID, fragment);
		glLinkProgram(ID);
		glGetProgramiv(ID, GL_LINK_STATUS, &success);
		if(!success){
			glGetProgramInfoLog(ID,512,NULL,infolog);
			printf(infolog);
		}
		glDeleteShader(vertex);
		glDeleteShader(fragment);

		free(vertCode);
		free(fragCode);
	}

	void use();


}


