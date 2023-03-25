#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct p{
	int x1,x2,y1,y2,step;
};
//(x1,y1)为目标车的坐标     (x2,y2)为无车处的坐标 
queue<p> Q;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//4个方向 
bool vis[55][55][55][55];//vis数组，记录一个状态是否访问 
int ans=0x7f7f7f7f;
int main()
{
	int n,m;
	p g;
	cin>>n>>m;
	//
	memset(vis,false,sizeof(vis));
	g.x1=1;g.x2=n;
	g.y1=1;g.y2=m;
	g.step=0;
	Q.push(g);
	//初始化
	// 
	while(!Q.empty())
	{
		p top=Q.front();int nx,ny;
		Q.pop();
		if (top.x1==n&&top.y1==m)
		{
			ans=top.step;
			break;
		}//使得目标车移动到终点，直接退出 
		if (vis[top.x1][top.y1][top.x2][top.y2])
			continue;//该状态之前已经用来转移过了,就不再用来转移了,没有这一步会使得算法运行效率大大减慢 
		else
			vis[top.x1][top.y1][top.x2][top.y2]=true;//标记 
		for (int k=0;k<4;k++)//4个方向，我们选择空白处的变动方向 
		{
			nx=top.x2+dir[k][0];
			ny=top.y2+dir[k][1];
			//空白处的下一个坐标点(nx,ny) 
			if (nx<1||nx>n||ny<1||ny>m) continue;//越界 
			// 
			g.x1=top.x1;g.y1=top.y1;//一般目标车坐标不会变动 
			g.x2=nx;g.y2=ny;
			if (nx==top.x1&&ny==top.y1)
			{
				g.x1=top.x2;
				g.y1=top.y2;
			}//如果空白处的坐标移动到目标车的位置,就证明目标车的坐标有变动
			//变动为空白处移动前的坐标 
			g.step=top.step+1;
			Q.push(g);
			//我们将新状态入队 
		}
	}
	//宽搜 
	cout<<ans<<endl;
	return 0;
}
