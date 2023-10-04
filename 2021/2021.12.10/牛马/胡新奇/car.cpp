#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int column[20];
int line[20];
long long v[20][20][7];
int n,m,ans=0;
void dfs(int x,int y,int dir)
//dir表示方向 : 1左 2上 3右 4下 
{
//	if (v[x][y][dir]>-1) return ;
	v[x][y][dir]=0;
	if (x==n&&y==m)
	{
		v[x][y][dir]=1;
		return ;
	}
	bool up=true,left=true,right=true,down=true;
	if (x==n||((column[y]>>x)&1)) right=false;
	if (x==0||((column[y]>>(x-1)&1))) left=false;
	if (y==m||((line[x]>>y)&1)) up=false;
	if (y==0||((line[x]>>(y-1))&1)) down=false;
	
	if (right&&(dir==4||dir==3))
	{
		column[y]^=(1<<x); 
		dfs(x+1,y,3);
		v[x][y][dir]+=v[x+1][y][3];
		column[y]^=(1<<x);
	}
	if (left&&(dir==2||dir==1))
	{
		column[y]^=(1<<(x-1)); 
		dfs(x-1,y,1);
		v[x][y][dir]+=v[x-1][y][1];
		column[y]^=(1<<(x-1));
	}
	if (up&&(dir==2||dir==3))
	{
		line[x]^=(1<<y); 
		dfs(x,y+1,2);
		v[x][y][dir]+=v[x][y+1][2];
		line[x]^=(1<<y);
	}
	if (down&&(dir==4||dir==1))
	{
		line[x]^=(1<<(y-1)); 
		dfs(x,y-1,4);
		v[x][y][dir]+=v[x][y-1][4];
		line[x]^=(1<<(y-1));
	}
//	cout<<x<<" "<<y<<" "<<dir<<" "<<v[x][y][dir]<<endl;
	return ;
}
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout); 
	memset(v,-1,sizeof(v));
	cin>>n>>m;
	dfs(0,0,3);
	cout<<v[0][0][3]<<endl;
	return 0;
}
