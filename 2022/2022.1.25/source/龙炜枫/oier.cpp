#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<set>
#include<ctime>
#define ll long long
#define RL register long long
using namespace std;
const ll maxn=1e4+10;
typedef struct
{
	string name;
	ll w;
}YTC;
YTC oier[maxn];
ll n,k;
inline bool cmp(YTC x,YTC y);
inline ll search(string x);
int main()
{
	freopen("oier.in","r",stdin);
	freopen("oier.out","w",stdout);
	cin >> n;
	for(RL i=1;i<=n;i++) cin >> oier[i].name;
	sort(oier+1,oier+n+1,cmp);
	cin >> k;
	for(RL i=1,scr;i<=k;i++)
	{
		register string name;
		cin >> name >> scr;
		oier[search(name)].w+=scr;
	}
	sort(oier+1,oier+n+1,cmp);
	for(RL i=1;i<=n;i++) cout << oier[i].name << " " << oier[i].w << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
inline bool cmp(YTC x,YTC y)
{
	if(x.w==y.w) return x.name<y.name;
	else return x.w>y.w;
}
inline ll search(string x)
{
	RL l=1,r=n;
	while(l<r)
	{
		RL mid=(l+r)>>1;
		if(oier[mid].name<x) l=mid+1;
		else r=mid;
	}
	return l;
}
