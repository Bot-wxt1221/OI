#include <iostream>
using namespace std;
int dp[10000005];
int tc[10000005];
int sc[10000005];
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