#include <iostream>
#include <cstdio>
#include <queue>
#define int long long
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
deque<int>a;
int now;
int fir[1000005];
int nxt[2000005];
int v[2000005];
int w[2000005];
void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int n;
int dp[1000005];
void dfs1(int now,int fa)
{
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		if(w[i]==1){
			dp[1]++;
		}
		dfs1(v[i],now);
	}
	return;
}
void dfs2(int now,int fa){
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		if(w[i]==0){
			dp[v[i]]=dp[now]+1;
		}else{
			dp[v[i]]=dp[now]-1;
		}
		dfs2(v[i],now);
	}
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		add(u,v,0);
		add(v,u,1);
	}
	dfs1(1,-1);
	dfs2(1,-1);
	int ans=(1LL<<60);
	int out=-1;
	for(int i=1;i<=n;i++){
		if(dp[i]<ans){
			a=deque<int>();
			a.push_back(i);
			ans=dp[i];
		}else if(dp[i]==ans){
			a.push_back(i);
		}
	}
	printf("%lld\n",ans);
	for(int i=0;i<a.size();i++){
		printf("%lld ",a[i]);
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

