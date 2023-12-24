#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int n,m,t,pa[100005];
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
	for(int i=1;i<=n;i++)pa[i]=i;
	for(int i=1;i<=n*9/10;i++)
	{
		printf("%d %d\n",max(1,(i-1)-(i-1)%3),i+1);
		pa[i+1]=max(1,(i-1)-(i-1)%3);
	}
	for(int i=n*9/10+1;i<n;i++)
	{
		int u=rnd.next(1,n);
		int v=rnd.next(1,n);
		while(find(u)==find(v))
		{
			u=rnd.next(1,n);
			v=rnd.next(1,n);
		}
		printf("%d %d\n",u,v);
		pa[find(u)]=find(v);
	}
	if(type)
	{
		while(m--)
		{
			if(rnd.next(0,1))
				printf("1 %d %d\n",rnd.next(1,n),rnd.next(-maxv,maxv));
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
