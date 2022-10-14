#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int nums, char *num[]){
	int a;
	char number[100];

	strcpy(number, num[1]);
	a = atoi(number);
	if(a % 2 == 0){
		printf("%d is even\n", a);
	}
	else{
		printf("%d is odd\n", a);
	}
	return 0;
}