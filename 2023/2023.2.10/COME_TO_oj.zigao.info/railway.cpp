#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int dp[105][105];
int dis[105];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("railway.in","r",stdin);
	freopen("railway.out","w",stdout);
	#endif
    int l1=read();
    int l2=read();
    int l3=read();
    int c1=read();
    int c2=read();
    int c3=read();
    int n=read();
    int s=read();
    int t=read();
    if(s>t){
        std::swap(s,t);
    }
    dis[1]=0;
    for(int i=2;i<=n;i++){
        dis[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(abs(dis[i]-dis[j])==0){
                dp[i][j]=0;
            }else if(abs(dis[i]-dis[j])<=l1){
                dp[i][j]=c1;
            }else if(abs(dis[i]-dis[j])<=l2){
                dp[i][j]=c2;
            }else if(abs(dis[i]-dis[j])<=l3){
                dp[i][j]=c3;
            }else{
                dp[i][j]=0x3f3f3f3f3f3f3f3fll;
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j]=dp[i][k]+dp[k][j];
                }
            }
        }
    }
    printf("%lld",dp[s][t]);
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

