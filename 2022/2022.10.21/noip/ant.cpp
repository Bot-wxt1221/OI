#include <iostream>
#include <cstdio>
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
signed main(){
	freopen("ant.in","r",stdin);
	freopen("ant.out","w",stdout);
	int n=read();
    int L=read();
	int _max=-1,_min=0x3f3f3f3f;
	int ansm=0;
	for(int i=1;i<=n;i++){
		int a;
		_max=max(_max,a=read());
		_min=min(_min,a);
		ansm=max(ansm,min(L-a,a));
	}
	printf("%lld %lld",ansm,max(_max,L-_min));
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


