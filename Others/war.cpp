#include <cstdio>
#include <climits>
#include <cstring>

#define H//����������� 

using namespace std;

struct OIer
{
	int x, y;
};

int a, b;
int map[1200][1200];//��λ���󣬴洢�ڽ�������� 
int n;
int sum[1200000];//��¼���ڽ̵��ŷ����� 
int maxn;//��¼�ŷ����������ڽ̵ı�� 
OIer q[1200000];//���Ѷ��� 
int head, tail;
int t[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};//����˳�� 

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
		//1~a, b -> 0~a-1, b-1 ����������� 
		q[tail].x = xi;
		q[tail].y = yi;
		map[xi][yi] = i + 1;
		tail++;
	}//�洢ͷ�ӵ�λ�� 
	
	BFS();//����ģ�⴫�̹��� 
	
	for (i=0; i<a; i++)
	{
		for (j=0; j<b; j++)
		{
			printf("%d ", map[i][j]);
			sum[map[i][j]]++;
		}
		printf("\n");
	}
	
	maxn = INT_MIN;//��ʼ��maxnΪ��Сֵ����Ҫͷ�ļ�climits
	for (i=1; i<=n; i++)
	{
		if (sum[i] > sum[maxn])//ͳ���ŷ����������ڽ̵ı�� 
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
	
	while (head < tail)//�򵥵Ŀ���ģ�� 
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
