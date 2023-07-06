#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#define int long long
inline int read();
int fir[200005];
int nxt[400005];
int v[400005];
int w[400005];
int p[200005];
int q[200005];
int dp[200005];
int seq[200005];
int dis[200005];
int tree[200005];
int n;
class backn{
	public:
		int pos,to;
};
class back{
	public:
		backn b[60];
		int co=0;
};
int lowbit(int x){
	return x&-x;
}
std::stack<back> a;
back add(int x,int y){
	back t;
	while(x<=n){
		// tree[x]=std::min(tree[x],y);
		if(y<tree[x]){
			t.co++;
			t.b[t.co].pos=x;
			t.b[t.co].to=tree[x];
			tree[x]=y;
		}
		x+=lowbit(x);
	}
	return t;
}
int que(int x){
	int _min=0x3f3f3f3f3f3f3f3f;
	while(x>0){
		_min=std::min(_min,tree[x]);
		x-=lowbit(x);
	}
	return _min;
}
int now;
void add(int x,int y,int z){
    now++;
    v[now]=y;
    w[now]=z;
    nxt[now]=fir[x];
    fir[x]=now;
    return ;
}
void dfs(int now,int fa,int dep){
	seq[dep]=now;
	int l=std::lower_bound(dis+1,dis+dep+1,dis[dep]-p[now])-dis;
	dp[now]=que(n-l+1)+q[now];
	if(now==1){
		dp[now]=q[now];
	}
	a.push(add(n-dep+1,dp[now]));
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(fa==v[i]){
			continue;
		}
		dis[dep+1]=dis[dep]+w[i];
		dfs(v[i],now,dep+1);
	}
	back temp=a.top();
	a.pop();
	for(int i=1;i<=temp.co;i++){
		tree[temp.b[i].pos]=temp.b[i].to;
	}
	return ;
}
signed main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	#endif
	// freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		tree[i]=0x3f3f3f3f3f3f3f3f;
	}
    for(int i=2;i<=n;i++){
		p[i]=read();
	}
	for(int i=2;i<=n;i++){
		q[i]=read();
	}
	for(int i=1;i<n;i++){
		int u=read(),v,w;
		v=read();
		w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,1,1);
	for(int i=1;i<=n;i++){
		if(dp[i]-q[i]==0x3f3f3f3f3f3f3f3f){
			printf("-1 ");
		}else
			printf("%lld ",dp[i]-q[i]);
	}
	return 0;
}
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


