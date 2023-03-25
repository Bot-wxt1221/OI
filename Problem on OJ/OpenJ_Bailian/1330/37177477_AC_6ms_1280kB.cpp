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
int fa[10005];
int fir[10005];
int nxt[10005];
int dep[10005];
int u[10005];
bool root[10005];
void dfs(int ,int ); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while(T--){
		int n=read();
		for(int i=1;i<=n;i++){
			fir[i]=-1;
			root[i]=0;
		}
		for(int i=1;i<n;i++){
			int a=read();
			u[i]=read();
			root[u[i]]=1;
			fa[u[i]]=a;
			nxt[i]=fir[a];
			fir[a]=i;
		}
		int r=0;
		for(int i=1;i<=n;i++){
			if(root[i]==0){
				r=i;
				break;
			}
		}
		dfs(r,1);
		int a=read(),b=read();
		while(a!=b){
			if(dep[a]<dep[b]){
				b=fa[b];
			}else{
				a=fa[a];
			}
		}
		printf("%d\n",a);
	}
	return 0;
}
void dfs(int now,int de){
	dep[now]=de;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs(u[i],de+1);
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


