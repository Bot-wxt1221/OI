#include <iostream>
#include <cstdio>
inline int read();
int fir[100005];
int nxt[200005];
int v[200005];
int now;
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int nans;
int siz[100005];
int big[100005];
int big2[100005];
bool check[100005];
void dfs(int now,int fa){
	siz[now]=1;
	check[now]=1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs(v[i],now);
		siz[now]=std::max(siz[v[i]]+1,siz[now]);
		if(big[now]<=siz[v[i]]){
			big2[now]=big[now];
			big[now]=siz[v[i]];
		}else if(big2[now]<=siz[v[i]]){
			big2[now]=siz[v[i]];
		}
	}
	nans=std::max(nans,big[now]+big2[now]+1);
	return ;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
	freopen("chariot.in","r",stdin);
	freopen("chariot.out","w",stdout);
	#endif
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	int tot=0;
	for(int i=1;i<=m;i++){
		int x=read();
		int y=read();
		add(x,y);
		add(y,x);
	}
	nans=0;
	for(int i=1;i<=n;i++){
		if(!check[i]){
			nans=0;
			dfs(i,i);
			tot+=nans;
		}
	}
	printf("%d",tot);
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



