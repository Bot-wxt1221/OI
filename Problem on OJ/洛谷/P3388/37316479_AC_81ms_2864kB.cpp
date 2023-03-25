#include <iostream>
#include <cstdio>
#include <queue>
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
int fir[50005];
int nxt[300005];
int v[300005];
int now;
int low[50005];
int dfn[50005];
priority_queue<int>as;
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int df;
bool vised[50005];
void dfs(int ,int );
int ans=0;
int main(){
//	freopen("P3388_1.in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a=read(),b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		if(vised[i]==0)
			dfs(i,0);
	}
	printf("%d\n",ans);
	while(as.size()>0){
		printf("%d ",-as.top()); 
		as.pop(); 
	}
	return 0;
}
void dfs(int now,int fa){
	int ans=0;
	vised[now]=1;
	dfn[now]=low[now]=++df;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(vised[v[i]]){
			if(fa!=v[i]) 
				low[now]=min(low[now],dfn[v[i]]);
			continue;
		}
		dfs(v[i],now);
		low[now]=min(low[now],low[v[i]]);
		if(low[v[i]]>=dfn[now]){
			ans++; 
		}
	}
	if(fa==0&&ans>=2){
		::ans++;
		as.push(-now);
	}
	if(fa!=0&&ans>=1){
		::ans++;
		as.push(-now);
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


