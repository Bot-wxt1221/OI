//���α��ѣ�û�б�� 
#include <iostream>
#include <cstdio>
using namespace std;
int vised[11][11][11][11];//vised[x][y][ax][ay]��ʾ�Ƿ�� x,y �ߵ� ax,ay 
int a[4][2]={{1,0},{0,1},{-1,0},{0,-1}};//�������� 
void dfs(int step,int x,int y,int fx,int fy);//��������0,0�ѵ��յ�    x,y�Ǳ�ʾ��ǰ��  fx,fy��ʾ��һ���� 
void dfs2(int step,int x,int y,int fx,int fy);//��������0,0�ѵ��յ�   x,y�Ǳ�ʾ��ǰ��  fx,fy��ʾ��һ����
int n;//��Ŀ������� n ���� dfsʹ�� 
unsigned long long cnt=0;//ͳ��·���� 
int main(){
	freopen("route.in","r",stdin);
	freopen("route.out","w",stdout);
	cin>>n;
	dfs(0,0,0,0,0);
	cout<<cnt;
	return 0;
}
void dfs(int step,int x,int y,int fx,int fy){
	if(step>n*2){//���·�����Ȳ�����2n 
		return;
	}
	if(x==n&&y==n){
		dfs2(0,n,n,n,n);//�ѻس�·�� 
		return;
	}
	for(int i=0;i<2;i++){//ֻ���������߷��ܴﵽ���·�� 
		int ax=x+a[i][0],ay=y+a[i][1];
		if(ax>n||ay>n||ax<0||ay<0){//�жϱ߽�  ��������Խ��   ��Ҫ���� 
			continue;
		}
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		vised[x][y][ax][ay]=1,vised[x][y][ax][ay]=1;
		dfs(step+1,ax,ay,x,y);
		vised[x][y][ax][ay]=0,vised[x][y][ax][ay]=0;
	}
}
void dfs2(int step,int x,int y,int fx,int fy){
	if(step>n*2){
		return;
	}
	if(x==0&&y==0){
		cnt++;
		return;
	}
	for(int i=2;i<4;i++){//ֻ���������߷��ܴﵽ���·�� 
		int ax=x+a[i][0],ay=y+a[i][1];
		if(ax>n||ay>n||ax<0||ay<0){
			continue;
		}
		if(vised[x][y][ax][ay]==1||vised[ax][ay][x][y]==1){
			continue;
		}
		vised[x][y][ax][ay]=1,vised[x][y][ax][ay]=1;
		dfs2(step+1,ax,ay,x,y);
		vised[x][y][ax][ay]=0,vised[x][y][ax][ay]=0;
	}
}
