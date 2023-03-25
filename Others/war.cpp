#include <cstdio>
#include <climits>
#include <cstring>

#define H//输入输出控制 

using namespace std;

struct OIer
{
	int x, y;
};

int a, b;
int map[1200][1200];//座位方阵，存储宗教信仰编号 
int n;
int sum[1200000];//记录各宗教的信奉人数 
int maxn;//记录信奉人数最多的宗教的编号 
OIer q[1200000];//宽搜队列 
int head, tail;
int t[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//传教顺序 

void BFS();

int main()
{
	int i, j;
	int xi, yi;
	
	#ifdef H
	freopen("war.in", "r", stdin);
	freopen("war.out", "w", stdout);
	#endif
	
	scanf("%d %d %d", &a, &b, &n);
	
	memset(q, 0, sizeof(q));
	memset(map, 0, sizeof(map));
	head = 0;
	tail = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d %d", &xi, &yi);
		xi -= 1;
		yi -= 1;
		//1~a, b -> 0~a-1, b-1 方便后续处理 
		q[tail].x = xi;
		q[tail].y = yi;
		map[xi][yi] = i + 1;
		tail++;
	}//存储头子的位置 
	
	BFS();//宽搜模拟传教过程 
	
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			printf("%d ", map[i][j]);
			sum[map[i][j]]++;
		}
		printf("\n");
	}
	
	maxn = INT_MIN;//初始化maxn为最小值，需要头文件climits
	for (i=1; i<=n; i++)
	{
		if (sum[i] > sum[maxn])//统计信奉人数最多的宗教的编号 
		{
			maxn = i;
		}
	}
	printf("%d", maxn);
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

void BFS()
{
	int i, j;
	
	while (head < tail)//简单的宽搜模板 
	{
		int tx, ty;
		
		for (i=0; i<4; i++)
		{
			tx = q[head].x + t[i][0];
			ty = q[head].y + t[i][1];
			
			if (tx < 0 || tx >= a || ty < 0 || ty >= b)
			{
				continue;
			}
			
			if (map[tx][ty] == 0)
			{
				map[tx][ty] = map[q[head].x][q[head].y];
				q[tail].x = tx;
				q[tail].y = ty;
				tail++;
			}
		}
		
		head++;
	}
	
	return;
}
