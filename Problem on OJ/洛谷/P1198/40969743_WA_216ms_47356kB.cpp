#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
inline int read();
int dp[200005][60];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    memset(dp,-1,sizeof(dp));
    int m=read(),d=read();
    int n=0;
    int t=0;
    for(int i=1;i<=m;i++){
        char a=getchar();
        if(a=='A'){
            int temp=t+read();
            temp%=d;
            n++;
            dp[n][0]=temp;
            for(int j=1;n-(1<<j)+1>0;j++){
                dp[n][j]=std::max(dp[n][j-1],dp[n-(1<<(j-1))][j-1]);
            }
        }else{
            int L=read();
            int r=n;
            int l=r-L+1;
            int lg2=log2(r-l+1);
            // t=std::max(dp[r][lg2],dp[l+(1<<lg2)+1][lg2]);
            // printf("%d\n",std::max(dp[r][lg2],dp[l+(1<<lg2)+1][lg2]));
        }
    }
	return 0;
}
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


