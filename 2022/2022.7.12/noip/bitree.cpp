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
bool root[30];
int lef[30];
int righ[30];
int fa[30];
int num[30];
int d[30];
int height[30];
void dfs(int a,int dep);
int main(){
	freopen("bitree.in","r",stdin);
	freopen("bitree.out","w",stdout);
	int n;
	n=read();
	for(int i=1;i<=n;i++){
		int id;
		id=read();
		int &l=lef[id],&r=righ[id];
		l=read();
		r=read();
		num[id]=2;
		if(l==-1){
			num[id]--;
		}else{
			root[l]=1;
			fa[l]=id;
		}
		if(r==-1){
			num[id]--;
		}else{
			root[r]=1;
			fa[r]=id;
		}
	}
	int r;
	for(int i=0;i<n;i++){
		if(!root[i]){
			r=i;
		}
	}
	fa[r]=-1;
	dfs(r,0);
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, ",i,fa[i]);
		if(fa[i]==-1){
			printf("sibling = -1, ");
		}else if(righ[fa[i]]==i){
			printf("sibling = %d, ",lef[fa[i]]);
		}else{
			printf("sibling = %d, ",righ[fa[i]]);
		}
		printf("degree = %d, depth = %d, height = %d, ",num[i],d[i],height[i]);
		if(r==i){
			printf("root\n");
		}else if(num[i]==0){
			printf("leaf\n");
		}else{
			printf("internal node\n");
		}
	}
	return 0;
}
void dfs(int a,int deq){
	d[a]=deq;
	if(num[a]==0){
		height[a]=0;
		return ;
	}
	if(righ[a]!=-1){
		dfs(righ[a],deq+1);
		height[a]=height[righ[a]]+1;
	}
	if(lef[a]!=-1){
		dfs(lef[a],deq+1);
		height[a]=max(height[a],height[lef[a]]+1);
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



