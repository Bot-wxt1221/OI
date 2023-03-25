#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
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
		int v,w;
};
int now=0;
int first[1005];
int nxt[2000005];
int v[2000005];
int w[2000005];
int dis[2000005];
bool vised[1005];
priority_queue<node>go;
bool operator < (node a,node b){
	return a.w<b.w;
}
inline void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=first[a];
	first[a]=now;
	return ;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T2=read();
	for(int T=1;T<=T2;T++){
		now=0;
		go=priority_queue<node>();
		int n=read();
		for(int i=1;i<=n;i++){
			dis[i]=0;
			vised[i]=0;
			first[i]=-1;
		}
		int m=read();
		for(int i=1;i<=m;i++){
			int a,b,c;
			a=read();
			b=read();
			c=read();
			add(a,b,c);
			add(b,a,c);
			if(a==1){
				dis[b]=c;
				go.push(node({b,dis[b]}));
			}else if(b==1){
				dis[a]=c;
				go.push(node({a,dis[a]}));
			}
		}
		dis[1]=0;
		while(vised[n]==0){
			node temp=go.top();
			while(vised[temp.w]){
				go.pop();
				temp=go.top();
			}
			go.pop();
			vised[temp.w]=1;
			for(int i=first[temp.v];i!=-1;i=nxt[i]){
				if(dis[v[i]]<min(dis[temp.v],w[i])){
					dis[v[i]]=min(dis[temp.v],w[i]);
					go.push(node({v[i],dis[v[i]]}));
				}
			}
		}
		printf("Scenario #%d:\n%d\n",T,dis[n]);
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


