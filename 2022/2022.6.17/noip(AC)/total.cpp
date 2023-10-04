#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char a[25][25];
int h,w;
bool vised[25][25];
const int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int ans=0;
void dfs(int x,int y);
int main(){
	freopen("total.in","r",stdin);
	freopen("total.out","w",stdout);
	while(scanf("%d%d",&w,&h)!=EOF&&w!=0&&h!=0){
		int sx,sy;
		for(int i=1;i<=h;i++){
			scanf("%s",a[i]+1);
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				if(a[i][j]=='@'){
					sx=i;
					sy=j;
				}
			}
		}
		ans=1;
		memset(vised,0,sizeof(vised));
		vised[sx][sy]=1;
		dfs(sx,sy);
		printf("%d\n",ans);
	}
	return 0;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>h||ny>w||a[nx][ny]=='#'){
			continue;
		}
		ans++;
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


