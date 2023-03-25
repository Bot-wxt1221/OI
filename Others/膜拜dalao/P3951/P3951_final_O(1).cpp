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
long long a,b,ans;
int main()
{
	scanf("%lld%lld",&a,&b);
	ans=a*b-a-b;
	printf("%lld",ans);
	return 0;	
}
