#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
inline int read();
void gcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return ;
    }
    gcd(b,a%b,y,x);
    y-=(a/b)*x;
    return ;
}
int dp[3000005];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read();
    int p=read();
    printf("1\n");
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=p-((p/i)*dp[p%i]%p);
        printf("%lld\n",dp[i]);
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


