#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
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
int a[205];
int dp[205][205];
signed main(){
	freopen("energy.in","r",stdin);
	freopen("energy.out","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    for(int i=n+1;i<=2*n;i++){
        a[i]=a[i-n];
    }
    a[0]=a[2*n];
    for(int L=2;L<=n;L++){
        for(int i=1;(i+L-1)<=2*n;i++){
            int j=i+L-1;
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+a[(j)%(2*n)+1]*a[k+1]*a[(i)]);
            }
        }
    }
    int _max=0;
    for(int i=1;i<=n;i++){
        _max=max(_max,dp[i][i+n-1]);
    }
    printf("%d",_max);
	return 0;
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

