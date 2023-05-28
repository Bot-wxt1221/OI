#include <iostream>
#include <cstring>
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
int first[450];
int mid[450];
int lef[450];
int righ[450];
bool have[500];
void dfs(int l,int r,int l1,int r1);
void dfs2(int now);
int main(){
	freopen("get_tree.in","r",stdin);
	freopen("get_tree.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		first[i]=read();
	}
	for(int i=1;i<=n;i++){
		mid[i]=read();
	}
	dfs(1,n,1,n);
	dfs2(first[1]);
	return 0;
}
void dfs(int l,int r,int l1,int r1){
	if(r<=l||l1>=r1){
		return ;
	}
	int fen;
	for(int i=l1;i<=r1;i++){
		if(mid[i]==first[l]){
			fen=i;
			break;
		}
	}
	if(fen==l1){
		dfs(l+1,r,l1+1,r1);
		righ[first[l]]=first[l+1];
		return ;
	}else if(fen==r1){
		dfs(l+1,r,l1,r1-1);
		lef[first[l]]=first[l+1];
		return ;
	}
	dfs(l+1,l+1+fen-1-l1,l1,fen-1);
	lef[first[l]]=first[l+1];
	dfs(l+1+fen-1-l1+1,r,fen+1,r1);
	righ[first[l]]=first[l+1+fen-1-l1+1];
	return ;
}
void dfs2(int now){
	if(now==0){
		return ;
	}
	dfs2(lef[now]);
	dfs2(righ[now]);
	printf("%d ",now);
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



