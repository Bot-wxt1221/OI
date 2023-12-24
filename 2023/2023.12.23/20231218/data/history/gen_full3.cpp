#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int n,m,t,pa[100005],a[100005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxm=atoi(argv[2]);
	int maxv=atoi(argv[3]);
	int k=atoi(argv[4]);
	int t=atoi(argv[5]);
	int n=rnd.next(maxn/3*2,maxn);
	int m=rnd.next(maxm/3*2,maxm);
	int type=atoi(argv[6]);
	if(strcmp(argv[7],"-n")==0)n=maxn,m=maxm;
	printf("%d %d %d %d\n",n,m,k,t);
	for(int i=1;i<=n;i++)pa[i]=a[i]=i;
	shuffle(a+1,a+n+1);
	for(int i=1;i<10;i++)
	{
		int u=rnd.next(1,10);
		int v=rnd.next(1,10);
		while(find(a[u])==find(a[v]))
		{
			u=rnd.next(1,10);
			v=rnd.next(1,10);
		}
		printf("%d %d\n",a[u],a[v]);
		pa[find(a[u])]=find(a[v]);
	}
	for(int i=10+1;i<=n;i++)
	{
		int x=rnd.next(1,10);
		printf("%d %d\n",a[i],a[x]);
	}
	if(type)
	{
		while(m--)
		{
			if(rnd.next(0,1))
			{
				if(rnd.next(0,100)) printf("1 %d %d\n",a[rnd.next(1,10)],rnd.next(-maxv,maxv));
				else printf("1 %d %d\n",rnd.next(1,n),rnd.next(-maxv,maxv));
			}
			else printf("2 %d\n",rnd.next(1,n));
		}
	}
	else
	{
		for(int i=1;i<=m/2;i++)printf("1 %d %d\n",rnd.next(1,n),rnd.next(-maxv,maxv));
		for(int i=m/2+1;i<=m;i++)printf("2 %d\n",rnd.next(1,n));
	}
	return 0;
}
