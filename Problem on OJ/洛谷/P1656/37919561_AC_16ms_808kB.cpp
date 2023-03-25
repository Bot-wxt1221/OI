#include <iostream>
#include <cstdio>
#include <algorithm>
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
int dfsn=0;
int now=0;
int fir[1550];
int nxt[50005];
int v[50005];
class ans{
	public:
		int u,v;
}anas[50005];
bool cmp(ans a,ans b){
	return a.u==b.u?a.v<b.v:a.u<b.u;
}
int have=0;
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dfn[1550],low[1500];
void dfs(int,int);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();
		b=read();
		add(a,b);
		add(b,a); 
	}
	dfs(1,-1);
	sort(anas+1,anas+1+have,cmp);
	for(int i=1;i<=have;i++){
		printf("%d %d\n",anas[i].u,anas[i].v);
	}
	return 0;
}
void dfs(int now,int fa){
	low[now]=dfn[now]=++dfsn;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		if(dfn[v[i]]==0){
			dfs(v[i],now);
			low[now]=min(low[now],low[v[i]]);
			if(low[v[i]]>dfn[now]){
				have++;
				anas[have].u=now;
				anas[have].v=v[i];
			}
		}else if(dfn[now]>dfn[v[i]]){
			low[now]=min(low[now],dfn[v[i]]);
		} 
	}
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


