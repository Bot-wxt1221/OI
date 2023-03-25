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
int righ[105];
int lef[105];
int data[105];
bool root[105];
int n1ow=0;
int x;
bool finish=0;
void dfs(int now);
int main(){
	freopen("tree_a.in","r",stdin);
	freopen("tree_a.out","w",stdout);
	int n=read();
	x=read();
	for(int i=1;i<=n;i++){
		data[i]=read();
		righ[i]=read();
		lef[i]=read();
		root[lef[i]]=root[righ[i]]=1;
	}
	int r=0;
	for(int i=1;i<=n;i++){
		if(root[i]==0){
			r=i;
		}
	}
	dfs(r);
	return 0;
}
void dfs(int now){
	if(finish){
		return ;
	}
	if(righ[now]!=0){
		dfs(righ[now]);
	}
	n1ow++;
	if(data[now]==x){
		if(!finish)
			printf("%d",n1ow);
		finish=1;
		return ;
	}
	if(lef[now]!=0){
		dfs(lef[now]);
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



