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
class node{
	public:
		int x,y,viw;
};
queue<node>bfs;
char a[1005][1005];
bool vised[1005][1005];
int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
	freopen("save.in","r",stdin);
	freopen("save.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
	}
	node temp;
	temp.x=read();
	temp.y=read();
	temp.viw=0;
	int tx=read();
	int ty=read();
	bfs.push(temp);
	while(bfs.size()>0){
		node temp=bfs.front();
		for(int i=0;i<4;i++){
			int nx=temp.x+pre[i][0];
			int ny=temp.y+pre[i][1];
			if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>n||a[nx][ny]=='1'){
				continue;
			}
			if(nx==tx&&ny==ty){
				printf("%d",temp.viw+1);
				return 0;
			}
			node te;
			te.x=nx;
			te.y=ny;
			te.viw=temp.viw+1;
			vised[nx][ny]=1;
			bfs.push(te);
		}
		bfs.pop();
	}
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


