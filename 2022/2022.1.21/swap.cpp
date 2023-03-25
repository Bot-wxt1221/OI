#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int a,b;
	int *p1,*p2;
	int *temp;
	cin>>a>>b;
	p1=&a;
	p2=&b;
	if(*p1<*p2){
		temp=p1;p1=p2;p2=temp;
	}
	cout<<*p1<<' '<<*p2;
	return 0;
}

