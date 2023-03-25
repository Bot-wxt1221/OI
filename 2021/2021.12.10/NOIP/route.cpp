//两次爆搜，没有别的 
#include <iostream>
#include <cstdio>
using namespace std;
int vised[11][11][11][11];//vised[x][y][ax][ay]表示是否从 x,y 走到 ax,ay 
int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//方向数组 
void dfs(int step,int x,int y,int fx,int fy);//此搜索从0,0搜到终点    x,y是表示当前点  fx,fy表示上一个点 
void dfs2(int step,int x,int y,int fx,int fy);//此搜索从0,0搜到终点   x,y是表示当前点  fx,fy表示上一个点
int n;//题目所输入的 n 方便 dfs使用 
unsigned long long cnt=0;//统计路径数 
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	cin>>n;
	dfs(0,0,0,0,0);
	cout<<cnt;
	return 0;
}
void dfs(int step,int x,int y,int fx,int fy){
	if(step>n*2){//最短路径长度不大于2n 
		return;
	}
	if(x==n&&y==n){
		dfs2(0,n,n,n,n);//搜回程路径 
		return;
	}
	for(int i=0;i<2;i++){//只有这两种走法能达到最短路径 
		int ax=x+a[i][0],ay=y+a[i][1];
		if(ax>n||ay>n||ax<0||ay<0){//判断边界  避免数组越界   不要忘了 
			continue;
		}
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		vised[x][y][ax][ay]=1,vised[x][y][ax][ay]=1;
		dfs(step+1,ax,ay,x,y);
		vised[x][y][ax][ay]=0,vised[x][y][ax][ay]=0;
	}
}
void dfs2(int step,int x,int y,int fx,int fy){
	if(step>n*2){
		return;
	}
	if(x==0&&y==0){
		cnt++;
		return;
	}
	for(int i=2;i<4;i++){//只有这两种走法能达到最短路径 
		int ax=x+a[i][0],ay=y+a[i][1];
		if(ax>n||ay>n||ax<0||ay<0){
			continue;
		}
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		vised[x][y][ax][ay]=1,vised[x][y][ax][ay]=1;
		dfs2(step+1,ax,ay,x,y);
		vised[x][y][ax][ay]=0,vised[x][y][ax][ay]=0;
	}
}
