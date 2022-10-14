#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	char *hello;
	char *hola;
	char goodbye[200];
	char adios[200];
	int mem_size = 200;

	strcpy(goodbye, "'goodbye' is on the stack");
	printf("%s at address %p\n", goodbye, &goodbye);
	strcpy(adios, "'adios' is also on the stack");
	printf("%s at address %p\n", adios, &adios);
	
	hello = (char *) malloc(mem_size);
	hola = (char *) malloc(mem_size);

	printf("\n");

	strcpy(hello, "'hello' is on the heap");
	printf("%s at address %p\n", hello, &hello);
	strcpy(hola, "'hola' is also on the heap");
	printf("%s at address %p\n", hola, &hola);
	free(hello);
	free(hola);
}