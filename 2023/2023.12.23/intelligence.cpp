#include <iostream>
#include <cstdio>
#include <algorithm>
inline int read();
int h[1000005];
int st[1000005][30];
int sum[1000005];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("intelligence.in","r",stdin);
	freopen("intelligence.out","w",stdout);
	#endif
    int n=read(),k;
    k=read();
    for(int i=1;i<=n;i++){
		h[i]=read();
		sum[i]=sum[i-1]+h[i];
		st[i][0]=h[i];
	}
	for(int i=1;i<30;i++){
		for(int j=1;(j+(1<<i)-1)<=n;j++){
			st[i][j]=std::__gcd(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		
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


