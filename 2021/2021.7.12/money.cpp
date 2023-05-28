#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long dp[1000010];
int main(){
//	freopen("money.in","r",stdin);
//	freopen("money.out","w",stdout);
	long long n;
	cin>>n;
	dp[15]=1;
	for(int i=16;i<=n;i++){
		dp[i]=max(dp[i-1],dp[i-5],dp[i-10]);
	}
	cout<<dp[n];
}
