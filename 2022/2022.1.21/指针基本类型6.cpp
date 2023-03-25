#include <stdio.h>

int main(){
	const int a = 5;
	const int * const ptr = (int *)&a;//指针位置常量 
	printf("%d\n", a);
//	a = 7;//protect  read-only
//	*ptr = 7;//read-only 
	return 0;
}

