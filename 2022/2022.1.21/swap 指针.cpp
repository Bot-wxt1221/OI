#include <iostream>
#include <cstdio>
using namespace std;
void _swap(int *a,int *b); 
int main(){
	int a,b;
	cin>>a>>b;
	_swap(&a,&b);
	 cout<<a<<' '<<b;
	return 0;
}
void _swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
