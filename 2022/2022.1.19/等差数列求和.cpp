#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long jie(int a);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	cout<<jie(n);
	return 0;
}
unsigned long long jie(int a){
	if(a==1){
		return 1;
	}
	return jie(a-1)+a;
}
