#include <stdio.h>

int main(){
	const int a = 5;
	int *ptr = &a;
	printf("%d\n", a);
//	a = 7;//protect  read-only
	*ptr = 7;
	printf("%d\n", a); 
	return 0;
}

