#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	char *hello;
	//char *goodbye;
	int mem_size = 200;

	//strcpy(goodbye, "This memory is on the stack at address %p\n");
	//printf("%s\n", goodbye);
	
	hello = (char *) malloc(mem_size);

	strcpy(hello, "This memory is on the heap");
	printf("%s at address %p\n", hello, &hello);
	free(hello);
}