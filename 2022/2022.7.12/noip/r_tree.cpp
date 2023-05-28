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
int next1[100005];
int first[100005];
int v[100005];
int dep[100005];
int now=0;
int fa[100005];
namespace stack{
	int stack[1000005];
	int top=0;
	
}
void dfs(int now,int deq);
int main(){
	freopen("r_tree.in","r",stdin);
	freopen("r_tree.out","w",stdout);
	int n=read();
	for(int i=0;i<n;i++){
		first[i]=-1;
		fa[i]=-1;
	}
	for(int i=1;i<=n;i++){
		int id=read();
		int k=read();
		for(int i=1;i<=k;i++){
			int c=read();
			fa[c]=id;
			now++;
			v[now]=c;
			next1[now]=first[id];
			first[id]=now;
		}
	}
	int root;
	for(int i=0;i<n;i++){
		if(fa[i]==-1){
			root=i;
		}
	}
	dfs(root,0);
	for(int i=0;i<n;i++){
		printf("node %d: parent = %d, depth = %d, ",i,fa[i],dep[i]);
		if(fa[i]==-1){
			printf("root, [");
		}else if(first[i]==-1){
			printf("leaf, [");
		}else{
			printf("internal node, [");
		}
		for(int j=first[i];j!=-1;j=next1[j]){
			stack::stack[stack::top++]=v[j];
		}
		while(stack::top>1){
			printf("%d, ",stack::stack[stack::top-1]);
			stack::top--;
		}
		if(stack::top>0){
			printf("%d",stack::stack[stack::top-1]);
			stack::top--;
		}
		printf("]\n");
	}
	return 0;
}
void dfs(int now,int deq){
	dep[now]=deq;
	for(int i=first[now];i!=-1;i=next1[i]){
		dfs(v[i],deq+1);
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



