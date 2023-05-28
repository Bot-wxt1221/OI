#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
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
queue<int>aa;
stack<int>in;
int dfsn=0;
int ans;
int now=0;
int fir[155000];
int nxt[500005];
int dp[500005];
int v[500050];
int have=0;
int a[500050];
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dfn[155000],low[150000],in_stack[150000];
namespace ng{
	int now;
	int out[500050];
	int fir[155000];
	int nxt[500005];
	int v[500050];
	int a[500050];
	void add(int a,int b){
		out[a]++;
		now++;
		v[now]=b;
		nxt[now]=fir[a];
		fir[a]=now;
		return ;
	}	
}
int numberfornode[500050];
void dfs(int,int);
int main(){
	freopen("popular.in","r",stdin);
	freopen("popular.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=1;
		ng::fir[i]=-1;
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		a=read();
		b=read();
		add(a,b);
	}
	for(int i=1;i<=n;i++){
		if(dfn[i]){
			continue;
		} 
		dfs(i,-1);
	}
	for(int i=1;i<=n;i++){
		for(int j=fir[i];j!=-1;j=nxt[j]){
			if(numberfornode[i]!=numberfornode[v[j]]){
				ng::add(numberfornode[i],numberfornode[v[j]]);
			}
		}
	}
	int tt=0;
	int siz;
	for(int i=1;i<=ans;i++){
		if(ng::out[i]==0){
			tt++;
			siz=ng::a[i];
		}
	}
	printf("%d",tt==1?siz:0);
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
		int tot=0;
		while(in.size()>0&&in.top()!=now){
			in_stack[in.top()]=0;
			tot+=a[in.top()];
			numberfornode[in.top()]=ans+1;
			in.pop();
			have++;
		}
		in_stack[in.top()]=0;
		in.pop();
		numberfornode[now]=ans+1;	
		tot+=a[now];
		ans++;
		ng::a[ans]=tot;
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


