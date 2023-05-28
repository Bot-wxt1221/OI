#include <cstdio>
#include <iostream>
using namespace std;
int main() {
	int i=0;


	printf("%d ",i++);
	printf("%d ",i++);//0 1 2
	printf("%d\n",i++);


	i=0;
	printf("%d %d %d\n",i++,i++,i++);//2 1 0
	i=0;
	
	printf("%d %d %d\n",++i,++i,++i);//3 3 3
	
	int x;
	x=3,2,3,5,3,4,1,1,12;
	printf("%d\n",x);//3
	
	x=(3,2,3,5,3,4,1,1,12);
	printf("%d\n",x);//12
	
	i=0;
	printf("%d %d %d\n",i--,i--,i--);
	
	i=0;
	printf("%d %d %d\n",--i,--i,--i);
	
	return 0;
}
