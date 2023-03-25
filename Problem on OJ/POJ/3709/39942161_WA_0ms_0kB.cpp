#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[500005];
int l=1,r=0;
int sum[500005];
int que[500005];
int dp[500005];
double Slope(int r,int l){
    if(a[r]==a[l]){
        return 0x3f3f3f3f3f3f3f3f;
    }
    return (double(dp[r-1]-sum[r-1]+r*a[r]-(dp[l-1]-sum[l-1]+l*a[l])))/(a[r]-a[l]);
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("sequence.in","r",stdin);
	// freopen("sequence.out","w",stdout);
	#endif
    int t=read();
    while(t--){
        l=1;
        r=0;
        int n=read(),k=read();
        for(int i=1;i<=n;i++){
            a[i]=read();
            sum[i]=a[i]+sum[i-1];
        }
        for(int i=1;i<=n;i++){
            if(i-k+1>k){
                while(l<r&&Slope(que[r-1],que[r])>=Slope(que[r],i-k+1)){
                    r--;
                }
                que[++r]=i-k+1;
            }else if(i-k<0){
                dp[i]=0x3f3f3f3f3f3f3f3f;
                continue;
            }else{
                dp[i]=sum[i]-sum[1]*i;
                continue;
            }
            while(l<r&&Slope(que[l],que[l+1])<=i+1){
                l++;
            }
            int j=que[l];
            dp[i]=dp[j-1]+(sum[i]-sum[j-1])-(i-j+1)*a[j];
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

