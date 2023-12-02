#include <iostream>
#include <cstdio>
#define mod 1000000007
inline int read();
int t[25][25];
int dp[25][(1<<20)+5];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read()-1;
    int m=read();
    int k=read();
    for(int i=1;i<=k;i++){
        int ai=read();
        int bi=read();
        int ci=read();
        t[ai-1][bi-1]=ci+1;
    }
    int nowd=0;
    dp[nowd][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            nowd^=1;
            for(int kk=0;kk<(1<<(n));kk++){
                dp[nowd][kk]=0;
            }
            for(int kk=0;kk<(1<<(n));kk++){
                int v=dp[nowd^1][kk];
                if(!v){
                    continue;
                }
                if(t[i][j]!=2&&(((~kk)>>j)&1)){
                    dp[nowd][kk]+=v;
                    dp[nowd][kk]%=mod;
                }
                if(t[i][j]!=1){
                    if((((kk)>>j)&1)){
                        dp[nowd][kk]+=v;
                        dp[nowd][kk]%=mod;
                    }else{
                        int T=(kk>>j);
                        if(T){
                            T=(T)&(T-1);
                        }
                        T=((T+1)<<j);
                        T+=(kk&((1<<j)-1));
                        dp[nowd][T]+=v;
                        dp[nowd][T]%=mod;
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        ans+=dp[nowd][i];
        ans%=mod;
    }
    printf("%d",ans);
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


