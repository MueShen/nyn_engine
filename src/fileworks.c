#include <stdio.h>
#include <stdlib.h>
#include "include/fileworks.h"

char *loadFile(char path[], int sizeAlloc){
	FILE *fptr;
	fptr = fopen(path,"r");

	char *returnPointer =(char*) malloc(sizeAlloc*1000000);
	fgets(returnPointer, sizeAlloc*1000000-1, fptr);
	fclose(fptr);
	return returnPointer;
}
//TODO file loading, universal file reaidng 
