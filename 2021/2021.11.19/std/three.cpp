/*
   dp[i]表示第i天所消耗的最少粮食，则有
   dp[i]=min{dp[j-1]+cost[j][i]*(i-j+1)*V+K} (j<=i)
      cost[j][i]表示第j天到第i天方案不变的情况下需要多少士兵 
   
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include <sstream>

using namespace std;
const int inf=1000000000;
const int maxn=310;
const int maxm=5050;

struct Edge
{
	int s,e,nx,c;
	bool operator < (const Edge &b) const
	{
		return c<b.c;
	}
}edge[2*maxm];
int head[maxn],cnt;
void add(int s,int e,int c)
{
	edge[cnt].s=s;
	edge[cnt].e=e;
	edge[cnt].c=c;
	edge[cnt].nx=head[s];
	head[s]=cnt++;
}
int fa[maxn];
int find(int x)
{
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
int n,m,T,V,K;
int vis[55][303][303];//vis[i][j][k]表示第i天 j到k的这条边是否受灾
int cost[55][55];//表示第i到j天方案不变的情况下 每天需要多少士兵
int dp[55];
int main()
{
	freopen("three.in","r",stdin);
	freopen("three.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&m,&T,&V,&K);
	memset(head,-1,sizeof(head));cnt=0;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		add(a,b,c);
		add(b,a,c);
	}
	sort(edge,edge+cnt);
	int P;
	scanf("%d",&P);
	for(int i=1;i<=P;i++)
	{
		int X,Y,T1,T2;
		scanf("%d %d %d %d",&X,&Y,&T1,&T2);
		for(int i=T1;i<=T2;i++)
			vis[i][X][Y]=vis[i][Y][X]=1;
	}
	for(int i=1;i<=T;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				vis[i][j][k]+=vis[i-1][j][k];//为了判断方便，将j到k的这条边是否受灾求和，则知道这条边的受灾天数 
	for(int i=1;i<=T;i++)
		for(int j=i;j<=T;j++)
		{
			//下面是kruskal求最小生成树
			int sum=0;
			for(int k=1;k<=n;k++)fa[k]=k;
			for(int k=0;k<cnt;k++)
			{
				int a=edge[k].s;
				int b=edge[k].e;
				if(vis[j][a][b]-vis[i-1][a][b])continue;//如果a到b这条边还在受灾，则跳过 
				if(find(a)==find(b))continue;
				sum+=edge[k].c;
				fa[find(a)]=find(b);
			}
			bool ok=1;
			for(int k=2;k<=n;k++)if(find(k)!=find(1))ok=0;
			if(ok)cost[i][j]=sum;
			else cost[i][j]=inf;
		}

	dp[0]=0;
	for(int i=1;i<=T;i++)
	{
		dp[i]=inf;
		for(int j=1;j<=i;j++)
			if(cost[j][i]!=inf)
			{
				dp[i]=min(dp[i],dp[j-1]+cost[j][i]*(i-j+1)*V+K);
			}
	}
	printf("%d\n",dp[T]);
	return 0;
}
