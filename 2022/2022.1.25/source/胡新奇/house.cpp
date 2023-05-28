#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int len[50005]={0},m,n; 
bool check(int minn)
{
	int k=0,bef=0;
	int top=n;
	while(len[top]-len[top-1]<minn)
	{
		top--;k++;
	}
	for (int i=1;i<=top;i++)
	{
		if (len[i]-len[bef]<minn)
			k++;
		else 
			bef=i;
	}
	return k<=m;
}
int main()
{
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	int L;
	scanf("%d%d%d",&L,&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&len[i]);
	sort(len+1,len+1+n);
	len[++n]=L;
	int l=1,r=L,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if (check(mid)) l=mid+1;
		else r=mid; 
	}
	printf("%d",l-1);
	return 0;
}
