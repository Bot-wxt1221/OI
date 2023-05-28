#include <iostream>
#include <cstdio>
#include <cstring>
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
int nxt[1000005];
int v[1000005];
int fir[1000005];
int now;
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
bool vised[1000005];
int dis0[1000005];
int dis1[1000005];
queue<int>a;
void dfs(int now,int d,int );
int main(){
//	freopen("work.in","r",stdin);
//	freopen("work.out","w",stdout);
	int n=read(),m;
	m=read();
	int q=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		dis1[i]=dis0[i]=1000000;
	}
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		add(a,b);
		add(b,a);
	}
	a.push(1);
	dis0[1]=0;
	vised[1]=1;
	while(a.size()>0){
		int temp=a.front();
		vised[temp]=0;
		a.pop();
		for(int i=fir[temp];i!=-1;i=nxt[i]){
			bool in=0;
			if(dis1[v[i]]>dis0[temp]+1){
				dis1[v[i]]=dis0[temp]+1;
				in=1;
			}
			if(dis0[v[i]]>dis1[temp]+1){
				dis0[v[i]]=dis1[temp]+1;
				in=1;
			}
			if(in&&(vised[v[i]]==0)){
				a.push(v[i]);
				vised[v[i]]=1;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,L;
		a=read();
		L=read();
		if(L&1){
			if(dis1[a]<=L){
				printf("Yes\n");
				continue;
			}
		}else {
			if(dis0[a]<=L){
				printf("Yes\n");
				continue;
			}
		}
		printf("No\n");
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



