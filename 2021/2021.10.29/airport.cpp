#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e5+10;
typedef struct
{
	int l,r;
	int bel;
}range;
typedef struct
{
	int ord,tim;
	bool typ;/*typ=0->take in typ=1->take off*/
}moment;
struct h
{
	int ord;
	bool operator <(const h &x)const
	{
		return x.ord<ord;
	}	
};
moment mot1[maxn<<1],mot2[maxn<<1];
range a1[maxn],a2[maxn];
int n,m1,m2,cnt1,cnt2,ans;
int need1[maxn],need2[maxn],sn1[maxn],sn2[maxn];
priority_queue<h> q;
bool cmp(moment x,moment y);
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(need1,0,sizeof(need1));memset(need2,0,sizeof(need2));
	memset(sn1,0,sizeof(sn1));memset(sn2,0,sizeof(sn2));
	cin >> n >> m1 >> m2;
	int cnt1=cnt2=0;
	for(int i=1;i<=m1;i++) 
	{
		cin >> a1[i].l >> a1[i].r;
		mot1[++cnt1].tim=a1[i].l;mot1[cnt1].typ=0;mot1[cnt1].ord=i;
		mot1[++cnt1].tim=a1[i].r;mot1[cnt1].typ=1;mot1[cnt1].ord=i;
	}
	for(int i=1;i<=m2;i++) 
	{
		cin >> a2[i].l >> a2[i].r;
		mot2[++cnt2].tim=a2[i].l;mot2[cnt2].typ=0;mot2[cnt2].ord=i;
		mot2[++cnt2].tim=a2[i].r;mot2[cnt2].typ=1;mot2[cnt2].ord=i;
	}
	sort(mot1+1,mot1+1+cnt1,cmp);sort(mot2,mot2+1+cnt2,cmp);
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) q.push((h){i});
	for(int i=1;i<=cnt1;i++)
		if(!mot1[i].typ) 
		{
			if(q.empty()) continue;
			int availble=q.top().ord;q.pop();
			need1[availble]++;
			a1[mot1[i].ord].bel=availble;
		}
		else if(a1[mot1[i].ord].bel)
			q.push((h){a1[mot1[i].ord].bel});
	while(!q.empty()) q.pop();
	for(int i=1;i<=n;i++) q.push((h){i});		
	for(int i=1;i<=cnt2;i++)
		if(!mot2[i].typ)
		{
			if(q.empty()) continue;
			int availble=q.top().ord;q.pop();
			need2[availble]++;
			a2[mot2[i].ord].bel=availble;
		}
		else if(a2[mot2[i].ord].bel)
			q.push((h){a2[mot2[i].ord].bel});
		
	for(int i=1;i<=n;i++) 
	{
		sn1[i]=sn1[i-1]+need1[i];
		sn2[i]=sn2[i-1]+need2[i];
	} 
	for(int i=0;i<=n;i++) ans=max(ans,sn1[i]+sn2[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
bool cmp(moment x,moment y)
{
	return x.tim<y.tim;
}
