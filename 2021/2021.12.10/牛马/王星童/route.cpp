#include <iostream>
#include <cstdio>
using namespace std;
int vised[11][11][11][11];
int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void dfs(int step,int x,int y,int fx,int fy);
void dfs2(int step,int x,int y,int fx,int fy);
int n;
unsigned long long cnt=0;
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	cin>>n;
	dfs(0,0,0,0,0);
	cout<<cnt;
	return 0;
}
void dfs(int step,int x,int y,int fx,int fy){
	if(step>n*2){
		return;
	}
	if(x==n&&y==n){
		dfs2(0,n,n,n,n);
		return;
	}
	for(int i=0;i<2;i++){
		int ax=x+a[i][0],ay=y+a[i][1];
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		if(ax>n||ay>n||ax<0||ay<0){
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
	for(int i=2;i<4;i++){
		int ax=x+a[i][0],ay=y+a[i][1];
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		if(ax>n||ay>n||ax<0||ay<0){
			continue;
		}
		vised[x][y][ax][ay]=1,vised[x][y][ax][ay]=1;
		dfs2(step+1,ax,ay,x,y);
		vised[x][y][ax][ay]=0,vised[x][y][ax][ay]=0;
	}
}
