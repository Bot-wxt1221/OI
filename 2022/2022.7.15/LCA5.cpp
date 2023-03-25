#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
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
int fir[10005];
int nxt[10005];
int v[10005];
int pos[10005];
vector<int>a[33];
int dep[10005];
int query(int l,int r){
	int lg=log2(r-l+1);
	if(dep[a[lg][l]]<dep[a[lg][r-(1<<lg)+1]]){
		return a[lg][l];
	}else{
		return a[lg][r-(1<<lg)+1];
	}
}
void dfs(int ,int ); 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		fir[i]=-1;
	}
	for(int i=1;i<n;i++){
		int a=read();
		int b=read();
		nxt[i]=fir[a];
		fir[a]=i;
		v[i]=b;
	}
	dfs(1,1);
	for(int i=1;i<33;i++){
		a[i].resize(a[0].size());
	}
	for(int i=1;i<=log2(a[0].size());i++){
		for(int j=0;(j+(1<<(i-1)))<a[0].size();j++){
			if(dep[a[i-1][j]]<dep[a[i-1][j+(1<<(i-1))]]){
				a[i][j]=a[i-1][j];
			}else{
				a[i][j]=a[i-1][j+(1<<(i-1))];
			}
		}
	}
	int m=read();
	for(int i=1;i<=m;i++){
		int a=read();
		int b=read();
		printf("%d\n",query(pos[a],pos[b]));
	}
	return 0;
}
void dfs(int now,int de){
	a[0].push_back(now);
	dep[now]=de;
	pos[now]=a[0].size()-1;
	for(int i=fir[now];i!=-1;i=nxt[i]){
		dfs(v[i],de+1);
	}
	a[0].push_back(now);
	pos[now]=a[0].size()-1;
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



