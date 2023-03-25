#include <iostream>
#include <cstdio>
#include <cmath>
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
int f[1000005][100]; 
int main(){
	freopen("range_max.in","r",stdin);
	freopen("range_max.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		f[i][0]=read();
	}
	for(int i=1;i<=log2(n);i++){
		for(int j=1;j<=n;j++){
			f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		int lg=log2(b-a+1);
		printf("%d\n",max(f[a][lg],f[b-(1<<lg)+1][lg]));
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



