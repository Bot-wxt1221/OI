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
int a,b,ans;
bool p[10000001];
int main()
{
	scanf("%d%d",&a,&b);
	if(a<b) swap(a,b);
	for(int i=0;i<=10000;i++)	
		for(int j=0;j<=10000;j++)
			if(!p[i*a+j*b]) p[i*a+j*b]=true;
	for(int i=1;i<=50000;i++)
		if(!p[i]) ans=i;
	printf("%d",ans);	
	return 0;	
}
