#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	char *hello;
	char goodbye[200];
	int mem_size = 200;

	strcpy(goodbye, "This memory is on the stack");
	printf("%s at address %p\n", goodbye, &goodbye);
	
	hello = (char *) malloc(mem_size);

	strcpy(hello, "This memory is on the heap");
	printf("%s at address %p\n", hello, &hello);
	free(hello);
}