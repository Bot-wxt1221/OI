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
const int maxn=1e4+10;
typedef struct
{
	int x1,y1;
	int x2,y2;
	int sqr;
	inline void calc(void)
	{
		x2+=x1;
		y2+=y1;
		sqr=(x2-x1)*(y2-y1);
		return;
	}
}rectangle;
rectangle rct[maxn];
int n,l,r,minimum=0x3f3f3f3f,ss;
inline bool cmp(rectangle x,rectangle y);
inline bool check(int x);
int main()
{
	freopen("rectangle.in","r",stdin);
	freopen("rectangle.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> r >> n;
	for(RI i=1;i<=n;i++) 
	{
		cin >> rct[i].x1 >> rct[i].y1 >> rct[i].x2 >> rct[i].y2;
		rct[i].calc();
		ss+=rct[i].sqr;
	}
	sort(rct+1,rct+n+1,cmp);
	while(l<r)
	{
		RI mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	RI lef=0,rig=n;
	while(lef<rig)
	{
		RI mid=(lef+rig)>>1;
		if(rct[mid].x1<=l) lef=mid+1;
		else rig=mid;
	}
	if(!(rct[lef-1].x1<l && rct[lef-1].x2>l) && lef-1) 
		printf("%d",rct[lef].x1);
	else printf("%d",l);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline bool cmp(rectangle x,rectangle y)
{
	if(x.x2==y.x2) return x.x1<y.x1;
	return x.x2<y.x2;
}
inline bool check(int x)
{
	RI s1=0;
	for(RI i=1;i<=n;i++)
		if(rct[i].x2<=x) s1+=rct[i].sqr;
		else if(rct[i].x1<=x && rct[i].x2>=x)
			s1+=(x-rct[i].x1)*(rct[i].y2-rct[i].y1);
	if(s1<ss-s1) return 0;
	else if(s1-(ss-s1)>minimum) return 0;
	else 
	{
		minimum=s1-(ss-s1);
		return 1;
	}		
}
