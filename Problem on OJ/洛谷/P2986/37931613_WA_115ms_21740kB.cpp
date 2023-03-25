#include <iostream>
#include <cstdio>
#define int long long
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
int w[2000005];
int c[1000005];
void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dep[1000005];
int zishu[1000005];
int n,tot;
void dfs1(int now,int fa,int de)
{
	dep[1]+=de*c[now];
	zishu[now]=c[now];
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs1(v[i],now,de+w[i]);
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
		dep[v[i]]-=zishu[v[i]]*w[i];
		dep[v[i]]+=(tot-zishu[v[i]])*w[i];
		dfs2(v[i],now);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		c[i]=read();
		tot+=c[i];
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		int w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs1(1,-1,0);
	dfs2(1,-1);
	int ans=(1<<60);
	int out=-1;
	for(int i=1;i<=n;i++){
		if(dep[i]<=ans){
			ans=dep[i];
			out=i;
		}
	}
	printf("%lld",ans); 
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


