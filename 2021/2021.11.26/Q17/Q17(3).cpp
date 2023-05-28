//第 n 个是男生，n-1可男可女
//第 n 个是女生，n-1只可女
//时间复杂度 O(n) 
#include <iostream>
#include <cstdio>
using namespace std;
long long boy[100],girl[100];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	boy[1]=girl[1]=1;//boy【i】是求 i位置放男生方案数 ，girl同理 
	for(int i=2;i<=n;i++){
		boy[i]=boy[i-1]+girl[i-1];
		girl[i]=boy[i-1];
	}
	cout<<boy[n]+girl[n];
	return 0;
}
