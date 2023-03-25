#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
inline int read();
int c[50005];
int dp[50005];
int a[50005];
int b[50005];
double Slope(int l,int r){
    return (double((dp[r]+b[r]*b[r]-(dp[l]+b[l]*b[l]))))/(b[r]-b[l]);
}
int deq[50005];
int l=1,r=1;
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("P3195_1.in","r",stdin);
	// freopen("P3195.out","w",stdout);
	#endif
    int n=read(),L=read();
    for(int i=1;i<=n;i++){
        c[i]=read();
        c[i]+=c[i-1];
        a[i]=i+c[i];
        b[i]=i+c[i]+L+1;
    }
    b[0]=L+1;
    // dp[0]=deq[++r]=0;
    for(int i=1;i<=n;i++){
        while(l<r&&Slope(deq[l],deq[l+1])<2*a[i]){
            l++;
        }
        dp[i]=dp[deq[l]]+(a[i]-b[deq[l]])*(a[i]-b[deq[l]]);
        while(l<r&&Slope(deq[r],deq[r-1])>Slope(deq[r],i)){
            r--;
        }
        deq[++r]=i;
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


