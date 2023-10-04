#include <iostream>
#include <cstdio>
int read(){
	int x=0,op=1;
	char f=getchar();
	while(f<'0'||f>'9'){
		op=((f=='-')?-1:1);
		f=getchar();
	}
	while('0'<=f&&f<='9'){
		x=(x<<3)+(x<<1)+(f^'0');
		f=getchar();
	}
	return op*x;
}
int fir[25];
int nxt[50];
int ww[50];
int v[50];
int now,tottt;
void add(int x,int y){
	v[++now]=y;
	nxt[now]=fir[x];
	fir[x]=now;
	return ;
}
int n;
bool vised[25];
int seq[25];
int ans[25];
int dp[25];
int tot=0;
int faa[25];
void init1(int now,int fa){
	faa[now]=fa;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		init1(v[i],now);
	}
	return ;
}
void dfs2(int now,int fa,int add){
	ww[now]+=add;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs2(v[i],now,add);
	}
	return ;
}
void dfs3(int now,int fa){
	tot+=ww[now];
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			continue;
		}
		dfs3(v[i],now);
	}
	return ;
}
int tot2=0;
void dfs1(int now){
	if(now==n+1){
		tot=0;
		dfs3(1,0);
		tot2+=tot;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vised[i]){
			continue;
		}
		vised[i]=1;
		seq[now]=i;
		int t=ww[i];
		dfs2(i,faa[i],ww[i]);
		dfs1(now+1);
		dfs2(i,faa[i],-t);
		vised[i]=0;
	}
}
int main(){
	#ifndef ONLINE_JUDGE
	freopen("spacetime.in","r",stdin);
	freopen("spacetime.out","w",stdout);
	#endif
	n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int u=read(),v;
		v=read();
		add(u,v);
		add(v,u);
	}
	init1(1,1);
	tottt=0;
	for(int i=1;i<=n;i++){
		ww[i]=read();
		tottt+=ww[i];
	}
	dfs1(1);
	printf("%d",tot2);
	return 0;
}

