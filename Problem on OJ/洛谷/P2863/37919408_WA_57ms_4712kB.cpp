#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
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
stack<int>in;
int dfsn=0;
int ans;
int now=0;
int fir[155000];
int nxt[500005];
int v[500050];
int have=0;
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dfn[155000],low[150000],in_stack[150000];
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
	}
	dfs(1,-1);
	printf("%d",ans);
	return 0;
}
void dfs(int now,int fa){
	low[now]=dfn[now]=++dfsn;
	in.push(now);
	in_stack[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(dfn[v[i]]==0){
			dfs(v[i],now);
			low[now]=min(low[now],low[v[i]]);
		}else if(in_stack[v[i]]){
			low[now]=min(low[now],dfn[v[i]]);
		}
	}
	if(dfn[now]==low[now]){
		int have=1;
		while(in.size()>0&&in.top()!=now){
			in.pop();
			have++;
		}
		in.pop();
		if(have!=1){
			ans++;
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


