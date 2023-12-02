#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
inline int read();
int dp[5005];
int a[5005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    memset(dp,0x3f,sizeof(dp));
    int n=read();
    int cr=read();
    int cl=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        a[i]++;
    }
    a[0]=1;
    dp[0]=0;
    a[n+1]=n+2;
    for(int i=1;i<=n+1;i++){
        int cntl=0,cntr=0;
        for(int j=i-1;j>=0;j--){
            if(a[j]<a[i]){
                dp[i]=std::min(dp[i],dp[j]+cntl*cl+cntr*cr);
                cntl++;
            }else{
                cntr++;
            }
            
        }
    }
    printf("%lld",dp[n+1]);
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


