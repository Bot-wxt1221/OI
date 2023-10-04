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
const int maxn=5e4+10;
int len,n,m,l=0x3f3f3f3f,r;
int d[maxn];
inline bool check(int x);
int main()
{
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> len >> n >> m;
	for(RI i=1;i<=n;i++) cin >> d[i];
	d[n+1]=len;
	sort(d+1,d+n+2);
	r=len;
	for(RI i=1;i<=n+1;i++) l=min(l,d[i]-d[i-1]);
	while(l<r)
	{
		RI mid=(l+r)>>1;
		if(check(mid)) l=mid+1;
		else r=mid;
	}
	printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline bool check(int x)
{
	RI cnt=m;
	for(RI i=2;i<=n+1 && cnt;i++)
		if(d[i]-d[i-1]<x) cnt--;
	return cnt;	
}
