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
	printf("Static variable 'b' equals 3. 'a' equals 1. Output of b+=a is:\n%d\n", stasis(1));
	printf("Static variable 'b' retains value of 4 for next function call. 'a' equals 1. Output of b+=a is:\n%d\n", stasis(1));

	printf("Local variable 'b' equals 3. 'a' equals 1. Output of b+=a is:\n%d\n", localized(1));
	printf("Local variabl 'b' re-initialized equal to 3 for next function call. 'a' equals 1. Output of b+=a is:\n%d\n", localized(1));
	return(0);
}