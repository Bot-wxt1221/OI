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
int nex[100005],head[100005],u[100005],v[10005];
int ans[100005];
void dfs(int step);
int no2w;
int main(){
//	freopen("1.in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,now=0;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=m;i++){
		now++;
		v[now]=read();
		u[now]=read();
		nex[now]=head[u[now]];
		head[u[now]]=now;
	}
	for(int i=n;i>=1;i--){
		no2w=i;
		dfs(i);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
void dfs(int step){
	if(ans[step])	return ;
	ans[step]=no2w;
	for(int i=head[step];i!=-1;i=nex[i]){
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

