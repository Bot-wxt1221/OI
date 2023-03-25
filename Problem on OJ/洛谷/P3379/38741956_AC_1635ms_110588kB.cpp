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
int x[1000005];
int y[1000005];
int now=0;
vector<int>ques[1000005];
int fir[1000005];
int nxt[2000005];
int v[2000005];
int fa[2000005];
int dep[2000005];
int ans[1000005];
bool vised[1000005];
int w[1000005];
int getfa(int a){
	return fa[a]==a?a:fa[a]=getfa(fa[a]);
}
void add(int a,int b,int c){
	now++;
	v[now]=b;
	w[now]=c;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int dis[100005];
void dfs(int now,int f,int );
int main(){
//	freopen("dis.in","r",stdin);
//	freopen("dis.out","w",stdout);
	int n=read(),m;
	m=read();
	int s=read(); 
	for(int i=1;i<=n;i++){
		fir[i]=-1;
		fa[i]=i;
	}
	for(int i=1;i<n;i++){
		int a=read();
		int b=read();
		add(a,b,1);
		add(b,a,1);
	}
	for(int i=1;i<=m;i++){
		x[i]=read();
		y[i]=read();
		ques[x[i]].push_back(i);
		ques[y[i]].push_back(i);
	}
	dfs(s,0,0);
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}
void dfs(int now,int f,int di){
	dis[now]=di;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==f){
			continue;
		}
		dfs(v[i],now,di+w[i]);
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
