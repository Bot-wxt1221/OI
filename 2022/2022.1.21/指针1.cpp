#include <iostream>
#include <cstdio>
using namespace std;
int a;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a;
	cout<<(&a)<<endl; 
	cout<<sizeof(&a)<<endl;//取指针变量的大小 
	cout<<(&::a)<<endl;
	cout<<sizeof(&::a);
	return 0;
}
