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
	printf("'b' initialized as static variable equal to 3.\n'a' equals 1.\nOutput of b+=a is %d\n", stasis(1));
	printf("'b' retains its value of 4 for next function call.\n'a' equals to 1.\nOutput of b+=a is %d\n", stasis(1));

	printf("'b' initialized as local variable equal to 3.\n'a' passed as argument and equals 1.\nOutput of b+=a is %d\n", localized(1));
	printf("'b' re-initialized as local variable equal to 3.\n'a' equals 1.\nOutput of b+=a is %d\n", localized(1));
	return(0);
}