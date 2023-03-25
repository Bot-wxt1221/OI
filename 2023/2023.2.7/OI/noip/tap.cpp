#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long dp[50];
int main(){	
	#ifdef ONLINE_JUDGE
	#else
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	#endif
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	dp[n]=1;
	for(int i=n-1;i>=1;i--){
		dp[i]=dp[i+1]+dp[i+2]+dp[i+2]+dp[i+4]+dp[i+6];
	}
	cout<<dp[2]+dp[3];
	return 0;
}
