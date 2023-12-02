#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define mod 998244353
#define inv2 499122177
inline int read();
int a[5005];
int dp[5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int sum=0,ans=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum+=a[i];
    }
    std::sort(a+1,a+n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i-1]+1;j<=a[i];j++){
            for(int kk=j;kk>=1;kk--){
                dp[kk]+=dp[kk-1];
                dp[kk]%=mod;
            }
        }
        ans+=dp[1];
        ans%=mod;
        for(int j=1;j<=a[i];j++){
            dp[j-1]+=((((j)*(j-1))%mod)*dp[j])%mod;
            dp[j-1]%=mod;
        }
    }
    printf("%lld",(((ans-sum+mod)%mod)*inv2)%mod);
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


