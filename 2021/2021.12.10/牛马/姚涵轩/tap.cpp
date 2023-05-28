#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int cxb=0;//插线板最后的总数量 
void dfs(int ls,int n,int m,int sy);//m需要的个数，n为可以插的格子 ,sy为层次--cyy的思路 
int main()
{
	freopen("tap.in","r",stdin); 
	  freopen("tap.out","w",stdout);
	int n;
	cin>>n;
	
	dfs(2,n,2,1);
	dfs(3,n,3,1);
	
	cout<<cxb;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void dfs(int ls,int n,int m,int sy)
{
	if(m>n)
	{
		return;
	}
	if(m==n)
	{
		cxb++;
		return;
	}
	if(m<n)
	{
		for(int i=1;i<=sy;i++)
		{
			for(int j=1;j<=ls;j++)
			{
				dfs(2+3*j-3*i,n,m+j,i);
				dfs(j,n,m+2*j,j);
			}
		}
	}
}
