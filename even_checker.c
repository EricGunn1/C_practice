#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int nums, char *num[]){
	int a;
	int b;
	char number[10];

	for(a = 1; a < nums; a++){
		if(strlen(num[a]) > 10){
			printf("Number too large\n");
			break;
		}
		strcpy(number, num[a]);
		b = atoi(number);
		if(b % 2 == 0){
			printf("%d is even\n", b);
		}
		else{
			printf("%d is odd\n", b);
		}
	}
	return 0;
}