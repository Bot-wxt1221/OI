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
int nexy[10005];
int head[10005];
int v[10005];
void dfs(int now); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=n-1;i++){
		int a=read();
		v[i]=read();
		nexy[i]=head[a];
		head[a]=i;
	}
	dfs(1);
	return 0;
}
void dfs(int now){
	printf("%d ",now);
	for(int i=head[now];i!=-1;i=nexy[i]){
		dfs(v[i]);
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
