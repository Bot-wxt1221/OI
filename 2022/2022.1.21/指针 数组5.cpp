#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a[4]={1,3,5,7};
	cout<<a<<endl;
	cout<<a+1<<endl;
	cout<<&a<<endl;
	cout<<&a+1<<endl;
	cout<<*(&a)<<endl;
	cout<<*(&a)+1<<endl; 
	return 0;
}

