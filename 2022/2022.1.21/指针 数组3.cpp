#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a[5]={1,2,3,4,5};
	int *p=NULL;
	cout<<a<<endl;
	p=a;
	cout<<p<<endl;
	cout<<*p<<endl;
	cout<<*p++<<endl;
	cout<<p<<endl;
	cout<<*p++<<endl;
	cout<<p<<endl;
	return 0;
}

