#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
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
		int x,y;
};
bool cmp(node a,node b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}
vector<node>ans;
int n,m;
int _max=0;
bool vised[105][105];
char map[105][105];
void dfs(int x,int y);
int pre[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void total(int x,int y);
int main(){
	freopen("bomberman.in","r",stdin);
	freopen("bomberman.out","w",stdout);
	n=read();
	m=read();
	int sx,sy;
	sx=read();
	sy=read();
	for(int i=1;i<=n;i++){
		scanf("%s",map[i]+1);
	}
	dfs(sx,sy);
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0;i<ans.size();i++){
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	printf("%d",_max);
	return 0;
}
void dfs(int x,int y){
	if(map[x][y]=='.')
		total(x,y);
	for(int i=0;i<=3;i++){
		int nx=x+pre[i][0],ny=y+pre[i][1];
		if(vised[nx][ny]||nx<=0||ny<=0||nx>n||ny>m||map[nx][ny]!='.'){
			continue;
		}
		vised[nx][ny]=1;
		dfs(nx,ny);
	}
	return ;
}
void total(int x,int y){
	int nx=x,ny=y;
	int total=0;
	while(nx>0&&map[nx][ny]!='#'){
		if(map[nx][ny]=='G'){
			total++;
		}
		nx--;
	}
	nx=x,ny=y;
	while(nx<=n&&map[nx][ny]!='#'){
		if(map[nx][ny]=='G'){
			total++;
		}
		nx++;
	}
	nx=x,ny=y;
	while(ny>0&&map[nx][ny]!='#'){
		if(map[nx][ny]=='G'){
			total++;
		}
		ny--;
	}
	nx=x,ny=y;
	while(ny<=m&&map[nx][ny]!='#'){
		if(map[nx][ny]=='G'){
			total++;
		}
		ny++;
	}
	if(total>_max){
		_max=total;
		ans.clear();
		node temp;
		temp.x=x;
		temp.y=y;
		ans.push_back(temp);
	}else if(total==_max){
		node temp;
		temp.x=x;
		temp.y=y;
		ans.push_back(temp);
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


