#include <iostream>
#include <cstdio>
using namespace std;
int dp[10005];
inline int sum(int b);
int main(){
	freopen("coin.in","r",stdin);
	freopen("coin.out","w",stdout);
	int n;
	cin>>n;
	n++;
	int j=1;
	for(int i=1;i<=n;j++){
		for(int a=1;a<=j;a++){
			dp[++i]=j;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dp[i];
	}
	cout<<ans;
	return 0;
}

