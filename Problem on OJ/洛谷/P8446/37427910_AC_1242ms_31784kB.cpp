#include <iostream>
#include <cstdio>
#include <algorithm>
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
int a[4000005];
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	int ans=0;
	int mx=-1,re=-1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		mx=max(mx,a[i]+i);
		re=max(re,mx-a[i]-i-1);
	}
	reverse(a+1,a+n+1);
	mx=-1;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]+i);
		re=max(re,mx-a[i]-i-1);
	}
	printf("%lld",re);
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


