//第 n 个是男生，n-1可男可女
//第 n 个是女生，n-1只可女
//时间复杂度 O(n) 
#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long b1,b2,g1,g2; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	b1=g1=1;//boy【i】是求 i位置放男生方案数 ，girl同理 
	for(int i=2;i<=n;i++){
		b2=b1+g1;
		g2=b1;
		b1=b2,g1=g2;
	}
	cout<<b1+g1;
	return 0;
}
