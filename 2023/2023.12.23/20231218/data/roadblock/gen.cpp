#include<cstdio>
#include<algorithm>
#include<cstring>
#include"testlib.h"
using namespace std;
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxn=atoi(argv[1]);
	int maxk=atoi(argv[2]);
	int maxv=atoi(argv[3]);
	int n=rnd.next(maxn/3*2,maxn);
	int k=rnd.next(0,maxk);
	if(strcmp(argv[4],"-n")==0)n=maxn;
	printf("%d %d\n",n,k);
	for(int i=1;i<=n;i++)printf("%d ",rnd.next(0,maxv));
	printf("\n");
	for(int i=1;i<=n;i++)printf("%d ",rnd.next(0,maxv));
	printf("\n");
	return 0;
}
