#include<iostream>
#include<stack>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[300005];
int zuo[300005];
int you[300005];
int main()
{
	freopen("rain.in","r",stdin);
	freopen("rain.out","w",stdout);
	
	int r;
	int n=0;
	int ans=0;
	int tmp=0;
	while(scanf("%d",&r) != EOF)
	{
		n++;
		a[n]=r;
		//
		if(zuo[n-1] > r)
		{
			zuo[n]=zuo[n-1];
		}
		else
		{
			zuo[n]=r;
		}
		//
	}
	for(int i=n;i>=1;i--)
	{
		if(you[i+1] > a[i])
		{
			you[i]=you[i+1];
		}
		else
		{
			you[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i] == zuo[i] || a[i] == you[i]) continue;
		if(zuo[i] == 0 || you[i] == 0) continue;
		tmp=min(zuo[i],you[i]);
		ans+=tmp-a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
