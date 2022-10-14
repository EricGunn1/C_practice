#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	int a = 3;
	int *b;
	char hello[10];

	printf("a is an integer with value %d and address %p\n", a, &a);
	*b = a;
	printf("b points to %p and contains the value %d\n", b, *b);
	printf("'hello' is an array, and arrays are pointers. it points to address %p\n", hello);
	strcpy(hello, "HELLO");
	printf("after using the strcpy function, pointer 'hello' is at address %p contains the string '%s'\n", &hello, hello);

	return 0;
}