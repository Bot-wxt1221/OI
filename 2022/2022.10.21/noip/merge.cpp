#include <iostream>
#include <cstdio>
#include <cstring>
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
int dp2[405][405];
int dp[405][405];
int a[405];
int pre[405];
int main(){
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
    int n=read();
    memset(dp2,0x3f,sizeof(dp2));
    for(int i=1;i<=n;i++){
        a[i]=read();
        pre[i]=a[i]+pre[i-1];
        dp2[i][i]=0;
    }
    for(int i=n+1;i<=2*n;i++){
        a[i]=a[i-n];
        pre[i]=pre[i-1]+a[i];
        dp2[i][i]=0;
    }
    for(int L=2;L<=n;L++){
        for(int i=1;(i+L-1)<=2*n;i++){
            int j=(i+L-1);
            for(int k=i;k<j;k++){
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+pre[j]-pre[i-1]);
                dp2[i][j]=min(dp2[i][j],dp2[i][k]+dp2[k+1][j]+pre[j]-pre[i-1]);
            }
        }
    }
    int _max=0;
    int _min=0x3f3f3f3f;
    for(int i=1;(i+n-1)<=2*n;i++){
        _max=max(_max,dp[i][i+n-1]);
        _min=min(_min,dp2[i][i+n-1]);
    }
    printf("%d\n%d",_min,_max);
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

