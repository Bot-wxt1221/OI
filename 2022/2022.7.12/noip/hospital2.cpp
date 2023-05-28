#include <iostream>
#include <cstdio>
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
int first[1005];
int people[1005];
int v[1005];
int  nex[1005];
int now;
unsigned long ans=0;
void add(int x,int y){
	now++;
	v[now]=y;
	nex[now]=first[x];
	first[x]=now;
}
bool vised[105];
int anss[105];
void dfs(int now,int dep);
void dfs2(int ,int );
int main(){
//	freopen("hospital.in","r",stdin);
//	freopen("hospital.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		first[i]=-1;
	}
	for(int i=1;i<=n;i++){
		people[i]=read();
		int a=read(),b=read();
		if(a!=0){
			add(i,a);
			add(a,i);
		}
		if(b!=0){
			add(i,b);
			add(b,i);
		}
	}
	dfs(1,0);
	anss[1]=ans;
	memset(vised,0,sizeof(vised));
	dfs2(1,1);
	int _min=100000;
	for(int i=1;i<=n;i++){
		_min=min(_min,anss[i]);
	}
	printf("%d",_min);
	return 0;
}
void dfs(int now,int dep){
	if(vised[now]){
		return ;
	}
	vised[now]=1;
	ans+=dep*people[now];
	for(int i=first[now];i!=-1;i=nex[i]){
		dfs(v[i],dep+1);
	}
	return ;
}
void dfs2(int now,int fa){
	if(vised[now]){
		return ;
	}
	vised[now]=1;
	if(now!=1){
		anss[now]=anss[fa]+(people[fa]-people[now]);
	}
	for(int i=first[now];i!=-1;i=nex[i]){
		dfs2(v[i],now);
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



