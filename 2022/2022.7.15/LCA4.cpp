#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
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
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int n;
int fir[10005];
int nxt[10005];
int v[10005];
int ans[10005][10005];
bool vised[10005];
void dfs(int ); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		fa[i]=i;
	}
	for(int i=1;i<n;i++){
		int a=read();
		int b=read();
		nxt[i]=fir[a];
		fir[a]=i;
		v[i]=b;
	}
	int m=read();
	dfs(1);
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		printf("%d\n",ans[a][b]);
	}
	return 0;
}
void dfs(int now){
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs(v[i]);
		fa[getfa(v[i])]=getfa(now);
	}
	vised[now]=1;
	for(int i=1;i<=n;i++){
		if(vised[i]){
			ans[now][i]=ans[i][now]=getfa(i);
		}
	}
	return ;
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



