#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
inline int read();
int dp[505][505][10];
char temp[505];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	int n=read(),k;
    k=read();
    scanf("%s",temp+1);
    for(int i=1;i<=n;i++){
        dp[i][i-1][1]=1;
    }
    for(int siz=1;siz<=n;siz++){
        for(int i=1;i+siz-1<=n;i++){
            int j=i+siz-1;
            if(siz<=k&&(temp[j]=='*'||temp[j]=='?')){
                dp[i][j][1]=dp[i][j-1][1];
            }
            if(siz>=2){
                if((temp[j]==')'||temp[j]=='?')&&(temp[i]=='('||temp[i]=='?')){
                    dp[i][j][2]=dp[i+1][j-1][1];
                    dp[i][j][2]%=mod;
                    dp[i][j][2]+=dp[i+1][j-1][3];
                    dp[i][j][2]%=mod;
                    dp[i][j][2]+=dp[i+1][j-1][4];
                    dp[i][j][2]%=mod;
                    dp[i][j][2]+=dp[i+1][j-1][6];
                    dp[i][j][2]%=mod;
                }
                for(int k=i;k<j;k++){
                    dp[i][j][3]+=(dp[i][k][6]*dp[k+1][j][1])%mod;
                    dp[i][j][3]%=mod;
                    dp[i][j][4]+=((dp[i][k][4]+dp[i][k][5])*dp[k+1][j][2])%mod;
                    dp[i][j][4]%=mod;
                    dp[i][j][5]+=((dp[i][k][4])*dp[k+1][j][1])%mod;
                    dp[i][j][5]%=mod;
                    dp[i][j][6]+=((dp[i][k][3]+dp[i][k][6])*dp[k+1][j][2])%mod;
                    dp[i][j][6]%=mod;
                }
            }
            dp[i][j][5]+=dp[i][j][1];
            dp[i][j][5]%=mod;
            dp[i][j][6]+=dp[i][j][2];
            dp[i][j][6]%=mod;
        }
    }
    printf("%lld",dp[1][n][6]);
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


