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
int n,m;
char a[1005][1005];
void dfs(int x,int y);
int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='1'){
				a[i][j]='0';
				ans++;
				dfs(i,j);
//				cout<<i<<' '<<j<<endl;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(nx<=0||ny<=0||nx>n||ny>m){
			continue;
		}
		if(a[nx][ny]=='1'){
			a[nx][ny]='0';
			dfs(nx,ny);
		}
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


