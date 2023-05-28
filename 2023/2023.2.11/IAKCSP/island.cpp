#include <iostream>
#include <cstdio>
#include <queue>
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
int n,m;
int map[105][105];
bool vised[105][105];
int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;
priority_queue<int>a;
void dfs(int x,int y);
int main(){
	freopen("island.in","r",stdin);
	freopen("island.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vised[i][j]==0&&map[i][j]>0){
				vised[i][j]=1;
				ans=map[i][j];
				dfs(i,j);
				a.push(-ans);
			}
		}
	}
	printf("%d\n",a.size());
	while(a.size()>0){
		printf("%d ",-a.top());
		a.pop();
	}
	return 0;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m||map[nx][ny]==0){
			continue;
		}
		vised[nx][ny]=1;
		ans+=map[nx][ny];
		dfs(nx,ny);
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


