#include <iostream>
#include <cstdio>
using namespace std;
int abso(int n){//形参 
	if(n<0){
		return -n;
	}
	return n;
} 
int main(){//调用函数 
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	cout<<abso(n);//参数传递     实参     一一对应（个数相同，类型匹配（相同或兼容）） 
	return 0;
}

