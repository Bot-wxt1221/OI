#include <iostream>
#include <cstdio>
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
int fa[10005];
bool vised[10005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<n;i++){
		int a=read();
		int u=read();
		fa[u]=a;
	}
	int a=read(),b;
	b=read();
	while(a!=1){
		vised[a]=1;
		a=fa[a];
	}
	vised[1]=1;
	while(b!=1&&vised[b]==0){
		b=fa[b];
	}
	printf("%d",b);
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



