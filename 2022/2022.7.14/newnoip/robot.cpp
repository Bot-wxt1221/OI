#include <iostream>
#include <cstdio>
#include <cmath>
#define int long long
#define mx(a,b) (((a)>(b)?(a):(b)))
#define mn(a,b) (((a)<(b))?(a):(b))
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
int f[100005][33]; 
int f2[100005][33];
signed main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		f[i][0]=read();
		f2[i][0]=f[i][0];
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j+(1<<(i-1))-1<=n;j++){
			f[j][i]=mx(f[j][i-1],f[j+(1<<(i-1))][i-1]);
			f2[j][i]=mn(f2[j][i-1],f2[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=n-m+1;i++){
		int a=i,b=i+m-1;
		int lg=log2(m);
		printf("%lld %lld\n",max(f[a][lg],f[b-(1<<lg)+1][lg]),min(f2[a][lg],f2[b-(1<<lg)+1][lg]));
	}
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



