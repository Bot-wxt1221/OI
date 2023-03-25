#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a[5]={1,2,3,4,5};
	int *p=NULL;
	p=a;
	for(int i=0;i<5;i++){
		cout<<p[i]<<' ';
	} 
	return 0;
}

