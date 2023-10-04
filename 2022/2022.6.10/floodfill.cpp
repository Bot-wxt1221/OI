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
int map[1005][1005];
bool vised[1005][1005];
int ans=0;
int pre[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int ,int ,int );
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=read();
		}
	}
	int now=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if((!vised[i][j])&&(!map[i][j]==0)){
				now--;
				dfs(i,j,now);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%-4d",map[i][j]);
		}
		cout<<endl;
	}
	cout<<-now; 
	return 0;
}
void dfs(int x,int y,int color){
	if(x<=0||y<=0||x>n||y>m||vised[x][y]||map[x][y]<=0)	return ;
	map[x][y]=color;
	vised[x][y]=1;
	for(int i=0;i<=3;i++){
		dfs(x+pre[i][0],y+pre[i][1],color);
	}
	return ;
}
/*
Anything about this program:
Type:
	水题 
Description:
	联通块 
Example:
	1:
		In:
			10 10
			1	2	1	0	0	0	0	0	2	3
			3	0	2	0	1	2	1	0	1	2
			4	0	1	0	1	2	3	2	0	1
			3	2	0	0	0	1	2	4	0	0
			0	0	0	0	0	0	1	5	3	0
			0	1	2	1	0	1	5	4	3	0
			0	1	2	3	1	3	6	2	1	0
			0	0	3	4	8	9	7	5	0	0
			0	0	0	3	7	8	6	0	1	2
			0	0	0	0	0	0	0	0	1	0
		Out:
			-1  -1  -1  0   0   0   0   0   -2  -2
			-1  0   -1  0   -3  -3  -3  0   -2  -2
			-1  0   -1  0   -3  -3  -3  -3  0   -2
			-1  -1  0   0   0   -3  -3  -3  0   0
			0   0   0   0   0   0   -3  -3  -3  0
			0   -3  -3  -3  0   -3  -3  -3  -3  0
			0   -3  -3  -3  -3  -3  -3  -3  -3  0
			0   0   -3  -3  -3  -3  -3  -3  0   0
			0   0   0   -3  -3  -3  -3  0   -4  -4
			0   0   0   0   0   0   0   0   -4  0
More:

*/


