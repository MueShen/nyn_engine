#include <stdio.h>
#include <stdlib.h>

#include "include/windowing.h"
#include "include/fileworks.h"

int main (){
	char *tst=loadFile("test.txt", 10);
	printf("%s\n",tst);
	free(tst);
	wnd_Init();
}






