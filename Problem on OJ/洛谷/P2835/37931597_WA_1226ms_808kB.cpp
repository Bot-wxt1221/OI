#include <iostream>
#include <cstdio>
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
class graph{
	public:
		int now;
		int in[4005];
		int fir[2005];
		int nxt[4005];
		int v[4005];
		graph(){
			for(int i=1;i<=400;i++){
				fir[i]=-1;
			}
			return ;
		}
		void add(int a,int b){
			in[b]++;
			now++;
			v[now]=b;
			nxt[now]=fir[a];
			fir[a]=now;
			return ;
		}
}a,b;
int ans;
stack<int>out;
bool in_stack[4005];
int ainb[4005];
int dfn[4005],low[4005],ndfn=0;
void dfs1(int now){
	ndfn++;
	dfn[now]=low[now]=ndfn;
	in_stack[now]=1;
	out.push(now);
	for(int i=a.fir[now];i!=-1;i=a.nxt[i]){
		if(!dfn[a.v[i]]){
			dfs1(a.v[i]);
			low[now]=min(low[now],low[a.v[i]]);
		}else if(in_stack[a.v[i]]){
			low[now]=min(low[now],dfn[a.v[i]]);
		}
	}
	if(dfn[now]==low[now]){
		ans++;
		while(out.size()>0&&out.top()!=now){
			ainb[out.top()]=ans;
			in_stack[out.top()]=0;
			out.pop();
		}
		ainb[out.top()]=ans;
		in_stack[out.top()]=0;
		out.pop();
	}
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		int temp=read();
		while(temp!=0){
			a.add(i,temp);
			temp=read();
		}
	}
	dfs1(1);
	for(int i=1;i<=n;i++){
		for(int j=a.fir[i];j!=-1;j=a.nxt[j]){
			if(ainb[i]!=ainb[a.v[j]]){
				b.add(ainb[i],ainb[a.v[j]]);
			}
		}
	}
	int an=0;
	for(int i=1;i<=ans;i++){
		an+=(b.in[i]==0);
	}
	printf("%d",an);
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


