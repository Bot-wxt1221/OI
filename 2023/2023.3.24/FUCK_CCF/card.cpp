#include <iostream>
#include <cstdio>
#define int long long
inline int read();
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	#endif
    int n=read();
	n=n*2+1;
	int i=0;
	int nn=n;
	while(n){
		i++;
		n>>=1;
	}
	i--;
	printf("%lld",(nn-(1ll<<i)-1)%13+1);
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


