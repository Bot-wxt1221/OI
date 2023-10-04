#include <iostream>
#include <cstdio>
#include <queue>
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
class node{
	public:
		int x,y,step;
};
queue<node>a;
int to[1005][1005];
int map[1005][1005];
int pre[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n,m;
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			map[i][j]=read();
		} 
	}
	memset(to,0x3f,sizeof(to));
	int inf=to[0][0];
	int x,y;
	x=read();
	y=read(); 
	to[x][y]=0;
	a.push(node({x,y,0}));
	while(a.size()>0){
		node temp=a.front();
		a.pop();
		for(int i=0;i<=3;i++){
			int nx=temp.x+pre[i][0],ny=temp.y+pre[i][1];
			if(to[nx][ny]!=inf||map[nx][ny]==0)	continue;
			to[nx][ny]=temp.step+1;
			a.push(node{nx,ny,to[nx][ny]});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(to[i][j]!=inf)
				cout<<to[i][j]<<' ';
			else
				cout<<-1<<' ';
		}
		cout<<endl;
	}
	return 0;
}
/*
Anything about this program:
Type:
	水题 
Description:
	单源最短路 
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
			1 1
		Out:
			0 1 2 -1 -1 -1 -1 -1 -1 -1
			1 -1 3 -1 -1 -1 -1 -1 -1 -1
			2 -1 4 -1 -1 -1 -1 -1 -1 -1
			3 4 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
			-1 -1 -1 -1 -1 -1 -1 -1 -1 -1	
More:

*/


