#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int n,m;
const int SIZE = 1000;
int a[SIZE+1][SIZE+1], book[SIZE+1][SIZE+1] = {0};
int nxt[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};   //�����ߡ������ߡ������ߡ������� 
void dfs(int x, int y, int color);

int main()
{
	int i, j, num = 0;
	char ch; 

//	freopen("puzzle.in","r",stdin);
//	freopen("puzzle.out","w",stdout);
	
	//���� n�� m,nΪ�У�mΪ�� 
	cin >> n >> m;	
	
	//�����ͼ 
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++) 
		{
			cin >> ch;
			a[i][j] = ch - '0';		
		}
	}
			
	//��ÿһ��'1'���Խ���dfsȾɫ 
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <= m; j++)
		{
			if(a[i][j] == 1)
			{
				num--;  //����Ⱦɫ�ı�ţ�ÿ����һ���»�ľ��Ⱦ��ͬ��Ⱦɫ
				book[i][j] = 1; 
				dfs(i, j, num);
				printf("%d %d\n",i,j);
			}
		} 
	}
	
	cout << -num;  	//�����ľ���� 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void dfs(int x,int y,int color)
{
	int tx, ty, k;
	
	a[x][y] = color;   //Ⱦɫ 
	//˳ʱ��ö���ĸ�����
	for(k = 0; k < 4; k++)
	{
		//������һ���������
		tx = x + nxt[k][0];
		ty = y + nxt[k][1];
		//�ж��Ƿ�Խ��
		if(tx < 1 || tx > n || ty < 1 || ty > m)
			continue;
		//�жϸõ��Ƿ�Ϊ��ľ�������������ǹ�
		if(a[tx][ty] == 1 && book[tx][ty] == 0)
		{
			book[tx][ty] = 1;        //���������Ѿ��߹�
			dfs(tx, ty, color);     //��ʼ������һ����
		} 
	} 

    return;
} 

