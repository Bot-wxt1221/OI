#include <iostream>
#include <cstdio>
inline int read();
int g[105][105];
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("graph_exp.in","r",stdin);
	freopen("graph_exp.out","w",stdout);
	#endif
    int n=read();
    for(int i=1;i<=n;i++){
    	int u=read(),k;
    	k=read();
    	for(int j=1;j<=k;j++){
    		g[u][read()]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",g[i][j]);
		}
		printf("\n");
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


