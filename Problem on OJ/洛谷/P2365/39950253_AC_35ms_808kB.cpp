#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int t[300005];
int f[300005];
int dp[300005];
int que[300005];
int n,s;
int l=1,r=1;
double Slope(int a,int b){
    return ((s*f[n]-s*f[b]+dp[b]-(s*f[n]-s*f[a]+dp[a])))/(f[b]-f[a]);
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen(".in","r",stdin);
	// freopen(".out","w",stdout);
	#endif
    n=read();
    s=read();
    for(int i=1;i<=n;i++){
        t[i]=read();
        t[i]+=t[i-1];
        f[i]=read();
        f[i]+=f[i-1];
    }
    for(int i=1;i<=n;i++){
        while(l<r&&Slope(que[l],que[l+1])<t[i]){
            l++;
        }
        dp[i]=dp[que[l]]+t[i]*(f[i]-f[que[l]])+s*(f[n]-f[que[l]]);
        while(l<r&&Slope(que[r],que[r-1])>Slope(que[r],i)){
            r--;
        }
        que[++r]=i;
    }
    printf("%lld",dp[n]);
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


