#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	char c[6]="hello";
	char *pc=c;
	cout<<c<<endl;
	cout<<pc<<endl; 
	cout<<static_cast<void*>(c)<<endl;
	cout<<static_cast<void*>(pc)<<endl;
	return 0;
}

