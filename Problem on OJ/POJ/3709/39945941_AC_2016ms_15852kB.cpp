#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int yuejie[55];
int a[500005];
int l,r;
int yuejie2[55];
int sum[500005];
int que[500005];
int dp[500005];
double y(int r){
    return dp[r]-sum[r]+r*a[r+1];
}
double x(int r){
    return a[r+1];
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        memset(a,0,sizeof(a));
        memset(sum,0,sizeof(sum));
        memset(dp,0,sizeof(dp));
        memset(que,0,sizeof(que));
        l=r=0;
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=a[i]+sum[i-1];
    }
    // que[0]=-1;  
    for(int i=1;i<=n;i++){
        if(i-k>=k){
            while(l<r&&(y(que[r])-y(que[r-1]))*(x(i-k)-x(que[r]))>=(y(i-k)-y(que[r]))*(x(que[r])-x(que[r-1]))){
                r--;
            }
            que[++r]=i-k;
        }
        while(l<r&&y(que[l+1])-y(que[l])<=(i)*(((x(que[l+1])-x(que[l]))))){
            l++;
        }
        int j=que[l];
        if(i-k<0){
            dp[i]=0x3f3f3f3f3f3f3f3f;
        }else if(j!=-1){
            dp[i]=dp[j]+(sum[i]-sum[j])-(i-j)*a[j+1];
        }else
            dp[i]=(sum[i])-(i-j)*a[j+1];
    }
    printf("%lld\n",dp[n]);
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


