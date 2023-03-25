#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a[5]={10,11,12,13,14};//a是常量指针 
	int *p=NULL;
	//a=p;//报错 
	cout<<a<<endl;
	p=a;
	cout<<p<<endl;
	return 0;
}

