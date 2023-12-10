#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,a[N],m,now;
vector<int>v;
vector<int>c[N];
ll ans;
struct BIT
{
	int c[N];
	void add(int x,int d)
	{
		for(;x<=n;x+=x&(-x))
			c[x]+=d;
	}	
	int ask(int x)
	{
		int res=0;
		for(;x;x-=x&(-x))
			res+=c[x];
		return res;
	}
	int query(int l,int r) 
	{
		return ask(r)-ask(l-1);
	}
}B;
int main()
{
		freopen("sort.in","r",stdin);
		freopen("sort.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		B.add(i,1);
		v.push_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
		c[x].push_back(i);
	}
	m=v.size();now=1;
	for(int i=m;i>=1;i--)
	{
		if(c[i].front()<now)
		{
			while(c[i].back()>=now)
			{
				B.add(c[i].back(),-1);
				c[i].pop_back();
			}
			ans+=B.query(now,n);now=1;
		}
		int nxt=c[i].back();
		while(c[i].size())
		{
			B.add(c[i].back(),-1);
			c[i].pop_back();
		}
		ans+=B.query(now,nxt);now=nxt+1;
	}
	printf("%lld",ans);
	return 0;
}
