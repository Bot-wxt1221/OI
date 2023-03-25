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
char a[105][105];
bool vised[105][105];
const int pre[8][2]={{1,0},{-1,0},{0,-1},{0,1},{1,-1},{1,1},{-1,-1},{-1,1}};
int ans;
int n,m;
void dfs(int x,int y);
int main(){
	freopen("oil_field.in","r",stdin);
	freopen("oil_field.out","w",stdout);
	while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0){
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		ans=0;
		memset(vised,0,sizeof(vised));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(vised[i][j]==0&&a[i][j]=='@'){
					ans++;
					vised[i][j]=1;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m||a[nx][ny]=='*'){
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


