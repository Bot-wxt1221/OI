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
int now;
int fir[1000005];
int nxt[2000005];
int v[2000005];
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dep[1000005];
int zishu[1000005];
int n;
void dfs1(int now,int fa,int de)
{
	dep[1]+=de;
	zishu[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs1(v[i],now,de+1);
		zishu[now]+=zishu[v[i]];
	}
	return;
}
void dfs2(int now,int fa){
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dep[v[i]]=dep[now];
		dep[v[i]]-=zishu[v[i]];
		dep[v[i]]+=(n-zishu[v[i]]);
		dfs2(v[i],now);
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,-1,0);
	dfs2(1,-1);
	int ans=0;
	int out=-1;
	for(int i=1;i<=n;i++){
		if(dep[i]>=ans){
			ans=dep[i];
			out=i;
		}
	}
	printf("%d",out); 
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


