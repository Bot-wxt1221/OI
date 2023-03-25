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
char a[10005];
int lef[10005];
int righ[10005];
int ead=0;
void dfs1(int now);
void dfs2(int now);
int dfs();
int main(){
	freopen("tree_b.in","r",stdin);
	freopen("tree_b.out","w",stdout);
	char a=dfs();
	dfs1(1);
	printf("\n");
	dfs2(1);
	return 0;
}
int dfs(){
	ead++;
	a[ead]=getchar();
	int how=ead;
	if(a[ead]=='.'){
		return ead;
	}
	lef[how]=dfs();
	righ[how]=dfs();
	return how;
}
void dfs1(int now){
	if(a[now]=='.'){
		return ;
	}
	dfs1(lef[now]);
	printf("%c",a[now]);
	dfs1(righ[now]);
}
void dfs2(int now){
	if(a[now]=='.'){
		return ;
	}
	dfs2(lef[now]);
	dfs2(righ[now]);
	printf("%c",a[now]);
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



