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
long long _min=-1UL;
int k,n,r;
int head[105];
int next[10005];
int v[10005];
int l[10005];
int t[10005];
bool vised[105];
int minlk[105][10005];
void dfs(int now,int nl,int nt);
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	k=read();
	n=read();
	r=read();
	memset(minlk,0x3f,sizeof(minlk));
	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=r;i++){
		int s=read();
		v[i]=read();
		l[i]=read();
		t[i]=read();
		next[i]=head[s];
		head[s]=i;
	}
	vised[1]=1;
	dfs(1,0,0);
	if(_min==-1UL){
		printf("-1");
	}else{
		printf("%lld",_min);
	}
	return 0;
}
void dfs(int now,int nl,int nt){
	if(nl>_min||nt>k){
		return ;
	}
	if(now==n){
		_min=nl;
		return ;
	}
	if(minlk[now][nt]>=nl){
		minlk[now][nt]=nl;
	}else{
		return ;
	}
	for(int i=head[now];i!=-1;i=next[i]){
		if(vised[v[i]]){
			continue;
		}
		vised[v[i]]=1;
		dfs(v[i],nl+l[i],nt+t[i]);
		vised[v[i]]=0;
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


