#include <iostream>
#include <cstdio>
#include <deque>
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
int x[100005];
int y[100005];
int now=0;
deque<int>ques[100005];
int fir[100005];
int nxt[200005];
int v[200005];
int fa[200005];
int ans[100005];
bool vised[100005];
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
int dis[100005];
void dfs(int now,int f);
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n=read(),m;
	for(int i=1;i<=40000;i++){
		fir[i]=-1;
		fa[i]=i;
	}
	int r=0;
	for(int i=1;i<=n;i++){
		int a=read();
		int b=read();
		if(b==-1){
			r=a;
			continue;
		}
		add(a,b);
		add(b,a);
	}
	m=read();
	for(int i=1;i<=m;i++){
		x[i]=read();
		y[i]=read();
		ques[x[i]].push_back(i);
		ques[y[i]].push_back(i);
	}
	dfs(r,0);
	for(int i=1;i<=m;i++){
		int LCA=ans[i];
		if(LCA==x[i]){
			printf("1\n");
		}else if(LCA==y[i]){
			printf("2\n");
		}else{
			printf("0\n");
		}
	}
	return 0;
}
void dfs(int now,int f){
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs(v[i],now);
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
			ans[q]=getfa(b);
		}
	}
	return ;
}
