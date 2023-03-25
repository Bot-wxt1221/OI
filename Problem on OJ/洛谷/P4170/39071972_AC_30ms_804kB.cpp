#include <iostream>
#include <cstdio>
#include <cstring>
// #define file
using namespace std;
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
char temp[55];
int dp[55][55];
int main(){
	#ifdef file
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	scanf("%s",temp);
	memset(dp,0x3f,sizeof(dp));
	int n=strlen(temp);
	for(int L=1;L<=n;L++){
		for(int i=0;(i+L-1)<n;i++){
			int j=i+L-1;
			if(L==1){
				dp[i][i]=1;
			}else if(temp[i]==temp[j]){
				dp[i][j]=dp[i][j-1];
			}else{
				for(int k=i;k<j;k++){
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	printf("%d",dp[0][n-1]);
	#ifdef file
	#else
// 	while(1);
	#endif
	return 0;
}
/*
Anything about this program:
Type:

Description:

Example:
	1:
		In:

		Out:
More:

*/


