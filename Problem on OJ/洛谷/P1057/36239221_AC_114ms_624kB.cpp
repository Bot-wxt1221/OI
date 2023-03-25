#include <iostream>
using namespace std;
int n,m;
inline int pre(int x){
	return x==1?n:x-1;
}
inline int nex(int x){
	return x==
	n?1:x+1;
}
int dp[35][35];
long long dfs(int n1,int m1);
int main(){
    cin>>n>>m;
	dp[2][1]=dp[n][1]=1;
	for(int j=2;j<=m;j++){
    	for(int i=n;i;i--){
			dp[i][j]=dp[pre(i)][j-1]+dp[nex(i)][j-1]; 
		}
	}
	cout<<dp[1][m];
}