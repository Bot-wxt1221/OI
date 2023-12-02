#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
#define inv2 500000004
inline int read();
int a[3005];
int dp[3005][3005];
int pow(int a,int b){
    if(b==0){
        return 1;
    }
    if(b&1==0){
        int temp=pow(a,b/2);
        return ((temp)*(temp))%mod;
    }
    return (pow(a,b-1)*a)%mod;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),q;
    q=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]>a[j]){
                dp[i][j]=1;
            }else{
                dp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=q;i++){
        int xx=read();
        int yy=read();
        dp[xx][yy]=dp[yy][xx]=((dp[xx][yy]+dp[yy][xx])*inv2)%mod;
        for(int j=1;j<=n;j++){
            if(j==xx||j==yy){
                continue;
            }
            dp[xx][j]=dp[yy][j]=((dp[yy][j]+dp[xx][j])*inv2)%mod;
            dp[j][xx]=dp[j][yy]=((dp[j][yy]+dp[j][xx])*inv2)%mod;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans+=dp[i][j];
            ans%=mod;
        }
    }
    ans=ans*pow(2,q);
    printf("%lld",ans%mod);
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


