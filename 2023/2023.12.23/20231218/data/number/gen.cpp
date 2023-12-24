#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#include"testlib.h"
using namespace std;
int main(int argc,char*argv[])
{
	registerGen(argc,argv,1);
	int maxlgn=atoi(argv[1]);
	int maxlgm=atoi(argv[2]);
	int type=0;
	if(strcmp(argv[3],"-m")==0)type=1;
	else if(strcmp(argv[3],"--m")==0)type=2;
	int t=1000;
	printf("%d\n",t);
	ll maxn=1,maxm=1;
	int i=1,j=1;
	for(i=1,maxn=10;i<=maxlgn;i++,maxn*=10)
	{
		for(j=1,maxm=10;j<=maxlgm;j++,maxm*=10)
		{
			for(int k=1;k<=3;k++)
			{
				ll n=rnd.next(0ll,maxn);
				ll m=rnd.next(1ll,maxm);
				if(type==1)m=1000000000000000000ll;
				else if(type==2)m=maxm;
				ll s=rnd.next(0ll,m-1);
				printf("%lld %lld %lld\n",s,n,m);
				t--;
			}
			if(i==maxlgn&&j==maxlgm)
			{
				while(t--)
				{
					ll n=rnd.next(0ll,maxn);
					ll m=rnd.next(1ll,maxm);
					if(type==1)m=1000000000000000000ll;
					else if(type==2)m=maxm;
					ll s=rnd.next(0ll,m-1);
					printf("%lld %lld %lld\n",s,n,m);
				}
			}
		}
	}
	return 0;
}
