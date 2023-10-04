/*
如果第 n 个是男生， f(n)=f(n-1)
如果第 n 个是女生， f(n)=f(n-2)  n-1只能放男生，考虑n-1为男生时，f(n-1)=f(n-2)
第 n 个位置是f(n)=f(n-1)+f(n-2)]
斐波那契数列
*/ 
#include <iostream>
#include <cstdio>
#define MAXN 1000
using namespace std;
int dp[MAXN];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dp[0]=dp[1]=1;
	int n;
	cin>>n;
	for(int i=2;i<=n+1;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cout<<dp[n+1];
	return 0;
}
