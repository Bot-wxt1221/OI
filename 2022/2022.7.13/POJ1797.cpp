#include <iostream>
#include <cstdio>
#include <algorithm>
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
class node{
	public:
		int u,v,w;
		node();
}a[1000005];
int first[1005];
int nex[1000005];
node::node(){
	u=v=w=0;
}
class node2{
	public:
		int u,w;
};
bool operator < (node2 a,node2 b){
	return a.w<b.w;
}
priority_queue<node2>aa;
bool cmp(node a,node b){
	return a.w>b.w;
}
bool vised[1005];
int dis[1005];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(),T2;
	T2=T;
	while(T--){
		int n=read(),m;
		m=read();
		for(int i=1;i<=n;i++){
			dis[i]=(1<<30);
			vised[i]=0;
		}
		for(int i=1;i<=m;i++){
			a[i].u=read();
			a[i].v=read();
			a[i].w=read();
			first[a[i].]
			if(a[i].u==1){
				aa.push(node2({a[i].v,a[i].w}));
				dis[a[i].v]=a[i].w;
			}
			if(a[i].v==1){
				aa.push(node2{a[i].u,a[i].w});
				dis[a[i].u]=a[i].w;
			}
		}
		while(vised[n]==0){
			int top=aa.top();
			vised[top]=1;
			aa.pop();
			for()
		}
	}
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



