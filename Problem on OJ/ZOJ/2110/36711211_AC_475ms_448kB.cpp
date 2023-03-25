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
int n,m,t,dx,dy,sx,sy;
char a[10][10];
bool vised[10][10];
const int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
bool yes=0;
void dfs(int x,int y,int T);
int main(){
//	freopen("bone.in","r",stdin);
//	freopen("bone.out","w",stdout);
	while(scanf("%d%d%d",&n,&m,&t)!=EOF&&n!=0&&m!=0&&t!=0){
		for(int i=1;i<=n;i++){
			scanf("%s",a[i]+1);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='D'){
					dx=i;
					dy=j;
				}
				if(a[i][j]=='S'){
					sx=i;
					sy=j;
				}
			}
		}
		yes=0;
		vised[sx][sy]=1; 
		dfs(sx,sy,0);
		vised[sx][sy]=0;
		if(yes){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
void dfs(int x,int y,int T){
	if(yes)	return ;
	if(x==dx&&y==dy&&T==t){
		yes=1;
		return ;
	}
	if(T>=t){
		return ;
	}
	if(x==dx&&y==dy&&T!=t){
		return ;
	}
	for(int i=0;i<4;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m||a[nx][ny]=='X'){
			continue;
		}
		vised[nx][ny]=1;
		dfs(nx,ny,T+1);
		vised[nx][ny]=0;
	}
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

