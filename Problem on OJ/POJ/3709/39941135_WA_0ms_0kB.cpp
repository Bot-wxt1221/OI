#include <iostream>
#include <cstdio>
#define int long long
inline int read();
int a[500005];
int l,r;
int yuejie2[505];
int sum[500005];
int que[500005];
int yuejie[55];
int dp[500005];
double Slope(int r,int l){
    if(a[r+1]==a[l+1]){
        return 0x3f3f3f3f3f3f3f3f;
    }
    return (double(dp[r]-sum[r]+r*a[r+1]-(dp[l]-sum[l]+l*a[l+1])))/(a[r+1]-a[l+1]);
}
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	// freopen("sequence.in","r",stdin);
	// freopen("sequence.out","w",stdout);
	#endif
int t=read();
while(t--){
l=r=0;
    int n=read(),k=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum[i]=a[i]+sum[i-1];
    }
    que[0]=-1;  
    for(int i=1;i<=n;i++){
        if(i-k>=0){
            while(l<r&&Slope(que[r-1],que[r])>=Slope(que[r],i-k)){
                r--;
            }
            que[++r]=i-k;
        }
        while(l<r&&Slope(que[l],que[l+1])<=i){
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

