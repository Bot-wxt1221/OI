#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct p{
	int x1,x2,y1,y2,step;
};
//(x1,y1)ΪĿ�공������     (x2,y2)Ϊ�޳��������� 
queue<p> Q;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//4������ 
bool vis[55][55][55][55];//vis���飬��¼һ��״̬�Ƿ���� 
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
	//��ʼ��
	// 
	while(!Q.empty())
	{
		p top=Q.front();int nx,ny;
		Q.pop();
		if (top.x1==n&&top.y1==m)
		{
			ans=top.step;
			break;
		}//ʹ��Ŀ�공�ƶ����յ㣬ֱ���˳� 
		if (vis[top.x1][top.y1][top.x2][top.y2])
			continue;//��״̬֮ǰ�Ѿ�����ת�ƹ���,�Ͳ�������ת����,û����һ����ʹ���㷨����Ч�ʴ����� 
		else
			vis[top.x1][top.y1][top.x2][top.y2]=true;//��� 
		for (int k=0;k<4;k++)//4����������ѡ��հ״��ı䶯���� 
		{
			nx=top.x2+dir[k][0];
			ny=top.y2+dir[k][1];
			//�հ״�����һ�������(nx,ny) 
			if (nx<1||nx>n||ny<1||ny>m) continue;//Խ�� 
			// 
			g.x1=top.x1;g.y1=top.y1;//һ��Ŀ�공���겻��䶯 
			g.x2=nx;g.y2=ny;
			if (nx==top.x1&&ny==top.y1)
			{
				g.x1=top.x2;
				g.y1=top.y2;
			}//����հ״��������ƶ���Ŀ�공��λ��,��֤��Ŀ�공�������б䶯
			//�䶯Ϊ�հ״��ƶ�ǰ������ 
			g.step=top.step+1;
			Q.push(g);
			//���ǽ���״̬��� 
		}
	}
	//���� 
	cout<<ans<<endl;
	return 0;
}
