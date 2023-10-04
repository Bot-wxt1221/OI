#include <iostream>
#include <cstdio>
using namespace std;
int dp[200];
int weight[11],value[11];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>weight[i]>>value[i];
	}
	for(int i = 0; i < n; i++) { // 遍历物品
		for(int j = 150; j >= weight[i]; j--) { // 遍历背包容量
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}
	cout<<dp[150];
	return 0;
}
