#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m;
const int SIZE = 1000;
int a[SIZE+1][SIZE+1], book[SIZE+1][SIZE+1] = {0};
int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   //向右走、向下走、向左走、向上走 
void dfs(int x, int y, int color);

int main()
{
	int i, j, num = 0;
	char ch; 

//	freopen("puzzle.in","r",stdin);
//	freopen("puzzle.out","w",stdout);
	
	//读入 n和 m,n为行，m为列 
	cin >> n >> m;	
	
	//读入地图 
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++) 
		{
			cin >> ch;
			a[i][j] = ch - '0';		
		}
	}
			
	//对每一个'1'尝试进行dfs染色 
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(a[i][j] == 1)
			{
				num--;  //更新染色的编号，每发现一个新积木就染不同的染色
				book[i][j] = 1; 
				dfs(i, j, num);
				printf("%d %d\n",i,j);
			}
		} 
	}
	
	cout << -num;  	//输出积木数量 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int x,int y,int color)
{
	int tx, ty, k;
	
	a[x][y] = color;   //染色 
	//顺时针枚举四个方向
	for(k = 0; k < 4; k++)
	{
		//计算下一个点的坐标
		tx = x + nxt[k][0];
		ty = y + nxt[k][1];
		//判断是否越界
		if(tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		//判断该点是否为积木区域或者曾经标记过
		if(a[tx][ty] == 1 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;        //标记这个点已经走过
			dfs(tx, ty, color);     //开始尝试下一个点
		} 
	} 

    return;
} 

