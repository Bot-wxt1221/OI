#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005],n,m;
bool check(int maxn)
{
	int sum=0,cnt=1;
//	cout<<maxn<<endl;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>maxn) return false;
		if (sum+a[i]>maxn)
		{
			cnt++;
			sum=a[i];
		}
		else sum+=a[i];
//		cout<<i<<" "<<sum<<endl;
	}
	return cnt<=m;
}
int main()
{
	freopen("divide_b.in","r",stdin);
	freopen("divide_b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int l=1,r=1e9,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if (check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}
