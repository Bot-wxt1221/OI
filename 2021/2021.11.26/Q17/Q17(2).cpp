/*
����� n ���������� f(n)=f(n-1)
����� n ����Ů���� f(n)=f(n-2)  n-1ֻ�ܷ�����������n-1Ϊ����ʱ��f(n-1)=f(n-2)
�� n ��λ����f(n)=f(n-1)+f(n-2)]
쳲���������
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
