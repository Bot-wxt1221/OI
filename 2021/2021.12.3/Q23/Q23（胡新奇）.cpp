#include<iostream>
#include<cstdio>
using namespace std;
int f[31][61];
//f[i][j] 第i轮，剩j个 方案数 
int main()
{
	int n,m,s=0;
	cin>>n>>m;
	f[0][n]=1;
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n+m+1;j++)
		{
			f[i][j]+=f[i-1][j+1];//输一个 
			f[i][j]+=f[i-1][j-1];//赢一个 
			if (i==m) s+=f[i][j];
		}
	}
	cout<<s<<endl;
	return 0;
}
