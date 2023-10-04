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
int n;
int ans=0;
bool vised[105][105];
const int pre[3][2]={{-1,0},{0,1},{0,-1}};
void dfs(int step,int x,int y);
int main(){
	freopen("check.in","r",stdin);
	freopen("check.out","w",stdout);
	n=read();
	dfs(1,50,50);
	printf("%d",ans);
	return 0;
}
void dfs(int step,int x,int y){
	if(vised[x][y])	return ;
	if(step==n+1){
		ans++;
		return ;
	}
	vised[x][y]=1;
	dfs(step+1,x-1,y);
	dfs(step+1,x,y+1);
	dfs(step+1,x,y-1);
	vised[x][y]=0;
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


