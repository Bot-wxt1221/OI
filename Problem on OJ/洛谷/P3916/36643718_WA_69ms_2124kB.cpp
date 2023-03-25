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
bool vised[100005];
int dfs(int step);
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,now=0;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		head[i]=-1;
	}
	for(int i=1;i<=m;i++){
		now++;
		u[now]=read();
		v[now]=read();
		nex[now]=head[u[now]];
		head[u[now]]=now;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",dfs(i));
	}
	return 0;
}
int dfs(int step){
	if(ans[step]!=0)	return ans[step];
	ans[step]=step;
	for(int i=head[step];i!=-1;i=nex[i]){
		ans[step]=max(ans[step],v[i]);
		if(vised[v[i]]==1){
			continue;
		}
		vised[v[i]]=1;
		ans[step]=max(ans[step],dfs(v[i]));
	}
	return ans[step];
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

