#include<iostream>
#include<cstdio>
using namespace std;
int book[1][8]={0};//标记数组 
int a[10][10]={0};
void dfs(int x,int y,int step,int w,int h);
int main()
{
	freopen("car.in","r",stdin);
	freopen("car.out","w",stdout); 
	
	int w,h,a,startx,starty,ans;
	cin>>w>>h;
	a=w*h;
	book[startx][starty]=1;
	if(startx<=w&&starty<=h)
		dfs(startx,starty,0,w,h);
			ans++;
	printf("%d",ans);
	
	fclose(stdin);
    fclose(stdout);
	return 0;
}

void dfs(int x,int y,int step,int w,int h)
{
	int next[4][2]={{1,0},/*下*/{0,1},/*右*/{-1,0},/*上*/{0,-1}/*左*/};
	int tx=0,ty=0,k,min,ans;
	if(step<min)
		ans++;
		return ;
	for(k=0;k<=3;k++)
	{
		tx=x+next[k][0];
		ty=y+next[k][1];
		if(tx<1||tx>w||ty<1||ty>h)
			continue;
		if(a[tx][ty]==0&&book[tx][ty]==0)
		{
			book[tx][ty]=1;
			dfs(tx,ty,step+1,w,h);
			book[tx][ty]=0;
		}
	}
		
	return ;
}
