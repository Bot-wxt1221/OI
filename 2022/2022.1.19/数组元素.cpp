#include <iostream>
#include <cstdio>
using namespace std;
void change(int a[]){
	a[0]=30,a[1]=50;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a[2]={3,5};
	change(a);
	cout<<a[0]<<' '<<a[1]<<endl; 
	return 0;
}

