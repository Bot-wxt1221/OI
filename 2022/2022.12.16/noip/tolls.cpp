#include <iostream>
#include <cstdio>
inline int read();
int map[105][105];
int main(){
	#ifdef ONLINE_JUDGE=LUOGU
	#else
	freopen("tolls.in","r",stdin);
	freopen("tolls.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            map[i][j]=read();
        }
        map[1][i]+=map[1][i-1];
        map[i][1]+=map[i-1][1];
    }
    for(int i=2;i<=n;i++){
        for(int j=2;j<=n;j++){
            map[i][j]+=std::min(map[i-1][j],map[i][j-1]);
        }
    }
    printf("%d",map[n][n]);
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

