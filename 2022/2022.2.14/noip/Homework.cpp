#include <iostream>
#include <cstdio>
using namespace std;
int dp[100005];
int a[505];
int w[505];
signed main(){
	freopen("Homework.in","r",stdin);
	freopen("Homework.out","w",stdout);
	int k,n,all=0;
	cin>>k>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>w[i];
		all+=w[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=k;j>=1;j--){
			if(j>=a[i]){
				if(dp[j-a[i]]+w[i]>dp[j]){
					dp[j]=dp[j-a[i]]+w[i];
				}else{
					dp[j]=dp[j];
				}
			}else{
				dp[j]=dp[j];
			}
		}
	cout<<all-dp[k];
	return 0;
}

