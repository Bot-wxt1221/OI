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
int fir[40005];
int nxt[80005];
int v[80005];
int w[80005];
bool vised[40005];
void dfs(int ,int ,int );
vector<int>q[40005];
int ans[40005];
int a[10005];
int b[10005];
int now=0; 
int dis[10005];
void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		fa[i]=i;
		q[i].clear();
	}
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		int c=read();
		char d[1005];
		scanf("%s",d);
		add(a,b,c);
		add(b,a,c);
	}
	int k=read();
	for(int i=1;i<=k;i++){
		a[i]=read();
		b[i]=read();
		q[b[i]].push_back(i);
		q[a[i]].push_back(i);
	}
	dfs(1,0,0);
	for(int i=1;i<=k;i++){
		int LCA=ans[i];
		printf("%d\n",dis[a[i]]+dis[b[i]]-2*dis[LCA]);
	}
	return 0;
}
void dfs(int now,int f,int de){
	dis[now]=de;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs(v[i],now,de+w[i]);
		fa[getfa(v[i])]=getfa(now);
	}
	vised[now]=1;
	for(int i=0;i<q[now].size();i++){
		int bb=b[q[now][i]];
		int aa=a[q[now][i]];
		if(bb==now){
			swap(aa,bb);
		}
	//		cout<<q[now][i]<<endl;
		if(vised[bb]){
			ans[q[now][i]]=getfa(bb);
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


