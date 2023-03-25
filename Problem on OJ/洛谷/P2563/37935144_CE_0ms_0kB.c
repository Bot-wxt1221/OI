#include <cstdio>
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
int dp[205];
int prime[100]={0,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	dp[0]=1;
	for(int i=1;i<=46;i++){
		for(int j=prime[i];j<=200;j++){
			dp[j]=dp[j-prime[i]]+dp[j];
		}
	}
	int a;
	while(scanf("%d",&a)!=EOF){
		printf("%d\n",dp[a]);
	}
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


