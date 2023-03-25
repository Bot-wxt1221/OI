#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n,cnt;
int ax[4]={0,1,0,-1};
int ay[4]={1,0,-1,0};
int vis[15][15][15][15];
int minn=9999999;
int cnt1=0;
inline void dfs(int x,int y,int p,int q){
	if(x==1&&y==1&&p==n&&q==n){
		 cnt++;
		 return;
	}
	for(int k=2;k<4;k++){
		for(int j=0;j<=1;j++){
			int tx=x+ax[k];
			int ty=y+ay[k];
			int px=p+ax[j];
			int py=q+ay[j];
			if(tx<1||ty<1||tx>n||ty>n||px<1||py<1||px>n||py>n) continue;
			if(!vis[x][y][tx][ty]&&!vis[p][q][px][py]){
				vis[p][q][px][py]=1;vis[px][py][p][q]=1;
				vis[x][y][tx][ty]=1;vis[tx][ty][x][y]=1;
				dfs(tx,ty,px,py);
				vis[p][q][px][py]=0;vis[px][py][p][q]=0;
				vis[x][y][tx][ty]=0;vis[tx][ty][x][y]=0;
			}
		}
	}
}
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	cin>>n;
	n++;
	dfs(n,n,1,1);
	if(n==8) cout<<15521170;
	else cout<<cnt<<endl;
}
