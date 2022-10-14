#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stasis(int a){
	static int b = 3;
	b += a;
	return b;
}

int localized(int a){
	int b = 3;
	b += a;
	return b;
}

int main(){
	printf("%d\n", stasis(1));
	printf("%d\n", stasis(1));

	printf("%d\n", localized(1));
	printf("%d\n", localized(1));

	return(0);
}