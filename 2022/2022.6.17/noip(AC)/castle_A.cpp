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
bool map[55][55][5];
int pre[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m;
int ans=0;
bool vised[105][105];
void dfs(int x,int y);
int main(){
	freopen("castle_A.in","r",stdin);
	freopen("castle_A.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int r=read();
			if(r>=8){
				r-=8;
				map[i][j][2]=1;
			}
			if(r>=4){
				r-=4;
				map[i][j][0]=1;
			}
			if(r>=2){
				r-=2;
				map[i][j][3]=1;
			}
			if(r>=1){
				r-=1;
				map[i][j][1]=1;
			}
		}
	}
	int total=0,_max=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vised[i][j]==0){
				total++;
				ans=0;
				vised[i][j]=1;
				dfs(i,j);
				_max=max(_max,ans);
			}
		}
	}
	printf("%d\n%d",total,_max);
	return 0;
}
void dfs(int x,int y){
	ans++;
	for(int i=0;i<4;i++){
		if(map[x][y][i]==1){
			continue;
		}
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m){
			continue;
		}
		vised[nx][ny]=1;
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


