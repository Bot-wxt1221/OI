#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int read(){
	int f=1,x=0;
	char a=getchar();
	while('0'>a||a>'9'){
		(a=='-')?(f=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=(x<<3)+(x<<1)+(a^48);
		a=getchar();
	}
	return f*x;
}
int x[200005];
int y[200005];
int now=0;
vector<int>ques[200005];
int fir[200005];
int nxt[200005];
int v[200005];
int fa[200005];
int dep[200005];
bool vised[200005];
int ans[200005];
int ans2[200005];
int total=0;
int getfa(int a){
	return fa[a]==a?a:fa[a]=getfa(fa[a]);
}
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dis[200005];
int q;
void dfs(int now,int f,int );
void dfs2(int now,int f);
int main(){
	freopen("yam.in","r",stdin);
	freopen("yam.out","w",stdout);
	int n=read();
	q=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		fa[i]=i;
	}
	for(int i=1;i<n;i++){
		int a=read();
		int b=read();
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=q;i++){
		x[i]=read();
		y[i]=read();
		ques[x[i]].push_back(i);
		ques[y[i]].push_back(i);
	}
	dfs(1,0,0);
	dfs2(1,0);
	printf("%d",total);
	return 0;
}
void dfs(int now,int f,int di){
	dis[now]=di;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs(v[i],now,di+1);
		fa[getfa(v[i])]=getfa(now);
	}
	vised[now]=1;
	int siz=ques[now].size();
	for(int i=0;i<siz;i++){
		int q=ques[now][i];
		int b=y[q];
		if(b==now){
			b=x[q];
		}
		if(vised[b]){
			ans[getfa(b)]-=2;
			ans[x[q]]++;
			ans[y[q]]++;
		}
	}
	return ;
}
void dfs2(int now,int f){
	ans2[now]=ans[now];
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs2(v[i],now);
		ans2[now]+=ans2[v[i]];
	}
	if(now==1){
		return ;
	}
	if(ans2[now]==0){
		total+=q;
	}else if(ans2[now]==1){
		total++;
	}
	return ;
}
