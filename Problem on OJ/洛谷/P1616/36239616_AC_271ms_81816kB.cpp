#include <iostream>
#include <algorithm>
using namespace std;
long long dp[10000005];
long long tc[10000005];
long long sc[10000005];
int main(){
    int t,m;
    cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>tc[i]>>sc[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=tc[i];j<=t;j++){
			dp[j]=max(dp[j],dp[j-tc[i]]+sc[i]);
		}
	}
	cout<<dp[t];
}