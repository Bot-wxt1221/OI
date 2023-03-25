#include <iostream>
#include <cstdio>
using namespace std;
int a[10];
int money[10]={0,1,2,3,5,10,20};
inline int read(){
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
int dp[1005][10][1005];
int main(){
	int n=6;
	int _max=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		_max+=money[i]*a[i];
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=_max;j++){
			dp[0][i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=_max;j++){
			bool ans=0;
			for(int m=0;m<=_max;m++){
				ans|=dp[j][i-1][m];
			}
			for(int m=0;m<=_max;m++){
				dp[j][i][m]|=ans;
			}
		}
		for(int j=1;j<=a[i];j++){
			for(int m=1;m<=_max;m++){
				if(m-money[i]>=0)
					dp[m][i][j]|=dp[m-money[i]][i][j-1];
				// dp[m][i][j]|=dp[m][i][j-1];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=_max;i++){
		if(dp[i][6][a[6]]){
			ans++;
		}
	}
	printf("Total=%d",ans);
	// getchar();
	// getchar();
	// getchar();
	return 0;
}
