#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int e[1005][1005];
int sum[1000005];
struct point{
	int x,y;
};
queue<point> mq;
void bfs(void);
int a,b,n,x,y;
int main()
{
	freopen("war.in","r",stdin);
	freopen("war.out","w",stdout);
	cin>>a>>b;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		point f;
		scanf("%d%d",&f.x,&f.y);
		e[f.x][f.y]=i;
		mq.push(f);
	}
	bfs();
	int max_i=1;
	for (int i=1;i<=a;i++)
	{
		for (int j=1;j<=b;j++)
		{
			printf("%d ",e[i][j]);
			sum[e[i][j]]++;
			if (sum[max_i]<sum[e[i][j]]||(sum[max_i]==sum[e[i][j]]&&max_i>e[i][j]))
				max_i=e[i][j];//更新人数最多的宗教 
		}
		printf("\n");
	}
	printf("%d\n",max_i);
	fclose (stdin);
	fclose (stdout);
	return 0;
}
void bfs(void)
{
	while (!mq.empty())
	{
		point head=mq.front();//出队 
		mq.pop();
		for (int k=0;k<4;k++)
		{
			int nx,ny;
			nx=head.x+dir[k][0];
			ny=head.y+dir[k][1];
			if (nx<=0||ny<=0||nx>a||ny>b) continue;//超出地图 
			if(e[nx][ny]==0)//将还没有宗教的人入队 
			{
				e[nx][ny]=e[head.x][head.y];
				point nxt;nxt.x=nx;nxt.y=ny;
				mq.push(nxt);
			}
		}
	}
	return ;
}

