#include <iostream>
#include <cstdio>
#define int unsigned long long
inline int read();
int a[5005][5005];
signed main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("chessboard.in","r",stdin);
	freopen("chessboard.out","w",stdout);
	#endif
    a[1][1]=1;
    int n=read();
    n++;
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            a[i][j]=a[i][j-1]+a[i-1][j];
        }
        a[i][i]=a[i][i-1];
    }
    std::cout<<a[n][n]*2;
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


