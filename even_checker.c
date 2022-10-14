#include <stdio.h>
#include <string.h>

int main(){
	int a = 8;
	if(a % 2 == 0){
		printf("%d is even\n", a);
	}
	else{
		printf("%d is odd\n", a);
	}
	return 0;
}