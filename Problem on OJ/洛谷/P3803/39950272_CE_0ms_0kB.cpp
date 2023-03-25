#include <iostream>
#include <cstdio>
inline int read();
int f[4000005],g[4000005],ans[4000005];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
    int n=read(),m;
    m=read();
    for(int i=0;i<=n;i++){
        f[i]=read();
    }
    for(int i=0;i<=m;i++){
        g[i]=read();
    }
    int limit=1;
    while(limit<(n+m)){
        limit=(limit)<<1;
    }
    fft(f,limit);
    fft(g,limit);
    for(int i=1;i<=limit;i++){
        f[i]*=g[i];
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


