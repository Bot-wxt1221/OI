#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define int long long
inline int read();
int a[1000006];
int sum2[1000005];
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n;
    while(scanf("%lld",&n)!=EOF){
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=(a[i]=read());
        }
        sum/=n;
        for(int i=1;i<=n;i++){
            a[i]-=sum;
        }
        for(int i=1;i<=n;i++){
            sum2[i]=sum2[i-1]+a[i-1];
        }
        std::sort(sum2+1,sum2+n+1);
        int tt=sum2[(n+1)/2];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=(sum2[i]-tt>0?sum2[i]-tt:tt-sum2[i]);
        }
        printf("%lld\n",ans);
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


