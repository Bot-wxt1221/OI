#include <iostream>
#include <cstdio>
#include <cmath>
#define maxn 40005
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
int fir[maxn*2];
int nxt[maxn*2];
int v[maxn*2];
int w[maxn*2];
int go[maxn][30];
int dep[maxn];
int fa[maxn];
int to[maxn][30];
void dfs(int now,int fa,int de);
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m,c;
	while(scanf("%d%d%d",&n,&m,&c)!=EOF){
		for(int i=1;i<=n;i++){
			fir[i]=-1;
			fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int a=read();
			v[i*2-1]=read();
			fa[getfa(a)]=getfa(v[i*2-1]);
			w[i*2-1]=read();
			nxt[i*2-1]=fir[a];
			fir[a]=i*2-1;
			v[i*2]=a;
			w[i*2]=w[i*2-1];
			nxt[i*2]=fir[v[i*2-1]];
			fir[v[i*2-1]]=i*2;
		}
		for(int i=1;i<=n;i++){
			if(fa[i]==i){
				dfs(i,0,1);
			}
		}
		for(int i=1;i<=log2(n);i++){
			for(int j=1;j<=n;j++){
				go[j][i]=go[go[j][i-1]][i-1];
				to[j][i]=to[j][i-1]+to[go[j][i-1]][i-1];
			}
		}
		int ans=0;
		for(int i=1;i<=c;i++){
			ans=0;
			int a=read();
			int b=read();
			if(getfa(a)!=getfa(b)){
				printf("No connected\n");
				continue;
			}
			if(dep[a]>dep[b]){
				swap(a,b);
			}//de[a]<de[b]
			while(dep[a]!=dep[b]){
				int i=0;
				while(dep[go[b][i+1]]>dep[a]){
					i++;
				}
				ans+=to[b][i];
				b=go[b][i];
			}
			if(a==b){
				printf("%d\n",ans);
				continue;
			}
			int ji=1;
			while(1){
				if(go[a][ji]==go[b][ji]){
					if(ji==0){
						break;
					}
					ans+=to[a][ji-1];
					ans+=to[b][ji-1];
					a=go[a][ji-1];
					b=go[b][ji-1];
					ji=0;
				}else{
					ji++;
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
void dfs(int now,int fa,int de){
	go[now][0]=fa;
	dep[now]=de;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		if(v[i]==fa){
			to[now][0]=w[i];
			continue;
		}
		dfs(v[i],now,de+1);
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

