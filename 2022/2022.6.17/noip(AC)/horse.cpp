#include <iostream>
#include <cstdio>
#include <cstring>
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
bool vised[15][15];
const int pre[8][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{1,-2},{2,-1}};
int ans=0;
void dfs(int now,int x,int y);
int main(){
	freopen("horse.in","r",stdin);
	freopen("horse.out","w",stdout);
	int T=read();
	while(T--){
		ans=0;
		int x,y;
		n=read();
		m=read();
		x=read();
		y=read();
		memset(vised,0,sizeof(vised));
		vised[x][y]=1;
		dfs(1,x,y);
		printf("%d\n",ans);
	}
	return 0;
}
void dfs(int now,int x,int y){
	if(now==n*m){
		ans++;
	}
	for(int i=0;i<8;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<0||ny<0||nx>=n||ny>=m){
			continue;
		}
		vised[nx][ny]=1;
		dfs(now+1,nx,ny);
		vised[nx][ny]=0;
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


