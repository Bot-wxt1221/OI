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

bool tree[1048576*4];
int n1;
int dfs(int now);
int main(){
	freopen("drop.in","r",stdin);
	freopen("drop.out","w",stdout);
	int n=read();
	n1=1<<n;
	int l=read();
	for(int i=1;i<=l-1;i++){
		dfs(1);
	}
	printf("%d",dfs(1));
	return 0;
}
int dfs(int now){
	if(now*2>n1){
		return now;
	}
	if(tree[now]){
		tree[now]=0;
		return dfs(now*2+1);
	}else{
		tree[now]=1;
		return dfs(now*2);
	}
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



