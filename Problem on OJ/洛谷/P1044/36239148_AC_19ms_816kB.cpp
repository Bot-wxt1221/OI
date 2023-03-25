#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		c=='-'?f=-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return f*x;
}
int dp[20][20];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int a=read();
	for(int i=0;i<=a;i++){
		dp[0][i]=1;
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			if(i==j){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j]+dp[i][j-1];
			}
		}
	}
	cout<<dp[a][a];
	return 0;
}
