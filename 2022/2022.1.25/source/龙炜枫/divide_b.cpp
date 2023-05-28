#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define RI register int
using namespace std;
const int maxn=1e5+10;
int n,m,l=0x3f3f3f3f,r;
int a[maxn];
inline bool check(int x);
int main()
{
	freopen("divide_b.in","r",stdin);
	freopen("divide_b.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(RI i=1;i<=n;i++) 
	{
		cin >> a[i];
		l=min(l,a[i]);
		r+=a[i];
	}
	while(l<r)
	{
		RI mid=(l+r)>>1;
		if(!check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline bool check(int x)
{
	RI cnt=m,sum=0;
	for(RI i=1;i<=n && cnt>0;i++)
	{
		sum+=a[i];
		if(sum>x)
		{
			--cnt;--i;
			sum=0;
		}
	}
	return cnt>0;
}
