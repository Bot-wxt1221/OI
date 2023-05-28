#include <iostream>
#include <cstdio>
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
int fir[10005];
int nxt[10005];
int dep[10005];
int v[10005];
void dfs(int ,int ); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int a=read();
		v[i]=read();
		fa[v[i]]=a;
		nxt[i]=fir[a];
		fir[a]=i;
	}
	dfs(1,1);//打表出深度 
	int a=read(),b=read();
	while(a!=b){
		if(dep[a]<dep[b]){
			b=fa[b];
		}else{
			a=fa[a];
		}
	}
	printf("%d",a);
	return 0;
}
void dfs(int now,int de){
	dep[now]=de;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs(v[i],de+1);
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



