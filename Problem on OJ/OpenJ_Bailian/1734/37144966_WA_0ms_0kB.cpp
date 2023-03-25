#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int read(){
	int f=0,x=1;
	char a=getchar();
	while('0'>a||a>'9'){
		(a=='-')?(x=-1):1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		f=(f<<3)+(f<<1)+(a^48);
		a=getchar();
	}
	return f*x;
}
class node{
	public:
		int u,v,w;
}a[10005];
int fa[105];
bool cmp(node a,node b){
	return a.w<b.w;
}
int getfa(int x){
	return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int fir[105];
int now;
int nxt[10005];
int v[10005];
bool vised[105];
bool fid;
int ans[105];
void dfs(int step,int now,int );
void add(int a,int b){
	now++;
	v[now]=b;
	nxt[now]=fir[a];
	fir[a]=now;
	return ;
}
int firs;
int siz[105];
int main(){
//	freopen("trip.in","r",stdin);
//	freopen("trip.out","w",stdout);
	int n=read(),m;
	m=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		siz[i]=1;
		fir[i]=-1;
	}
	for(int i=1;i<=m;i++){
		a[i].u=read();
		a[i].v=read();
		a[i].w=read();
	}
	int find=0;
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		int fx=getfa(a[i].u),fy=getfa(a[i].v);
		if(fx==fy&&siz[fx]>=3){
			add(a[i].u,a[i].v);
			add(a[i].v,a[i].u);
			fa[fx]=fy;
			siz[fy]+=siz[fx];
			find=i;
			break;
		}
		add(a[i].u,a[i].v);
		add(a[i].v,a[i].u);
		fa[fx]=fy;
		siz[fy]+=siz[fx];
	}
	if(find==0){
		printf("No solution.");
	}else{
		ans[0]=a[find].u;
		firs=a[find].u;
		dfs(0,a[find].u,-1);
	}
	return 0;
}
void dfs(int step,int now,int fa){
	if(fid){
		return ;
	}
	if(now==firs&&step>2){
		fid=1;
		for(int i=0;i<step;i++){
			printf("%d ",ans[i]);
		}
		return ;
	}
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(getfa(now)!=getfa(v[i])){
			continue;
		}
		if(vised[v[i]]){
			continue;
		}
		if(v[i]==fa){
			continue;
		}
		ans[step+1]=v[i];
		vised[v[i]]=1;
		dfs(step+1,v[i],now);
		vised[v[i]]=0;
	}
	return ;
}
