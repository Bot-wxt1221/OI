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
int to[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int map[105][105];
int dp[105][105][3];
bool vised[105][105];
class node{
	public:
		int x,y;
		node(int ix,int iy,int co){
			x=ix;
			y=co;
			y=iy;
		}
};
queue<node>a;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(dp,0x3f,sizeof(dp));
	int inf=dp[0][0][0];
	int m=read(),n;
	n=read();
	for(int i=1;i<=n;i++){
		int a=read();
		int b=read();
		map[a][b]=read()+1;
	}
	dp[m][m][map[m][m]]=0;
	if(map[m][m]==0){
		dp[m][m][1]=dp[m][m][2]=2;
	}
	a.push(node(m,m,map[m][m]));
	vised[m][m]=1;
	while(a.size()>0){
		node temp=a.front();
		vised[temp.x][temp.y]=0;
		a.pop();
		for(int i=0;i<=3;i++){
			int nx=temp.x+to[i][0];
			int ny=temp.y+to[i][1];
			if(nx<=0||ny<=0||nx>m||ny>m){
				continue;
			}
			if(map[temp.x][temp.y]==0&&map[nx][ny]==0){
				continue;
			}
			if(map[temp.x][temp.y]==map[nx][ny]){
				int tmp=dp[temp.x][temp.y][map[temp.x][temp.y]]; 
				if(tmp<dp[nx][ny][map[nx][ny]]){
					dp[nx][ny][map[nx][ny]]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
			}else if(map[temp.x][temp.y]==0){
				int tmp=dp[temp.x][temp.y][map[nx][ny]==1?2:1]+1;
				if(tmp<dp[nx][ny][map[nx][ny]]){
					dp[nx][ny][map[nx][ny]]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
				tmp=dp[temp.x][temp.y][map[nx][ny]]+0;
				if(tmp<dp[nx][ny][map[nx][ny]]){
					dp[nx][ny][map[nx][ny]]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
			}else if(map[nx][ny]==0){
				int tmp=dp[temp.x][temp.y][map[temp.x][temp.y]]+2;
				if(tmp<dp[nx][ny][map[temp.x][temp.y]]){
					dp[nx][ny][map[temp.x][temp.y]]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
				tmp=dp[temp.x][temp.y][map[temp.x][temp.y]]+3;
				if(tmp<dp[nx][ny][map[temp.x][temp.y]==2?1:2]){
					dp[nx][ny][map[temp.x][temp.y]==2?1:2]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
			}else{
				int tmp=dp[temp.x][temp.y][map[nx][ny]==1?2:1]+1;
				if(tmp<dp[nx][ny][map[nx][ny]]){
					dp[nx][ny][map[nx][ny]]=tmp;
					if(vised[nx][ny]==0){
						vised[nx][ny]=1;
						a.push(node(nx,ny,map[nx][ny]));
					}
				}
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			cerr<<map[i][j]<<' ';
//		}
//		cerr<<endl;
//	}
  	if(dp[1][1][map[1][1]]>=inf){
		printf("-1");
	}else
		printf("%d",dp[1][1][map[1][1]]);
 	return 0;
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



