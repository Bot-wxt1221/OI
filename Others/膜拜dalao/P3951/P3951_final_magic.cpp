#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<cctype>
#include<set>
using namespace std;
long long a,b,x,y,ans;
void exgcd(long long a,long long b,long long &x,long long &y);
int main()
{
	scanf("%lld%lld",&a,&b);
	exgcd(a,b,x,y);
	if(x>0)
	{
		swap(a,b);
		swap(x,y);
	}
	long long t=-x/b;
	x+=(t*b);
	y-=(t*a);
	while(x<0)
	{
		x+=b;
		y-=a;
	}
	while(x>0)
	{
		x-=b;
		y+=a;
	}
	ans=a*(x+b-1)+b*(y-1);
	printf("%lld",ans);
	return 0;	
}
void exgcd(long long a,long long b,long long &x,long long &y)
{
	//笔者也不知道为什么这里不运行也能AC 
}
