#include <iostream>
#include <cstdio>
#include <algorithm>
#define mod 1000000007
inline int read();
int a[205];
int dp[205][205][1005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),k;
    k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    dp[0][0][0]=1;
    std::sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<=n;j++){
            int pp=(((long long)(a[i]-a[i-1]))*j)%mod;
            for(int kk=0;kk<=k-pp;kk++){
                dp[i][j][kk+pp]+=((long long)(((long long)dp[i-1][j][kk])*(j+1)))%mod;
                dp[i][j][kk+pp]%=mod;
                if(j!=n){
                    dp[i][j+1][kk+pp]+=dp[i-1][j][kk];
                    dp[i][j+1][kk+pp]%=mod;
                }
                if(j!=0){
                    dp[i][j-1][kk+pp]+=(((long long)dp[i-1][j][kk])*j)%mod;
                    dp[i][j-1][kk+pp]%=mod;
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<=k;i++){
        ans+=dp[n][0][i];
        ans%=mod;
    }
    printf("%d",ans);
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


