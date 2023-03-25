#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200005];
struct tree{
	int l,r;
	int data;
}node[4*200005];
void build(int p,int l,int r)
{
	node[p].l=l;node[p].r=r;
	if (l==r)
	{
		node[p].data=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(2*p,l,mid);
	build(2*p+1,mid+1,r);
	node[p].data=node[2*p].data+node[2*p+1].data;
	return ;
}
void Push(int p,int goal,int w)
{
	if (node[p].l==node[p].r)
	{
		node[p].data+=w;
		return ;
	}
	int mid=(node[p].l+node[p].r)>>1;
	if (goal<=mid) Push(2*p,goal,w);
	else Push(2*p+1,goal,w);
	node[p].data=node[2*p].data+node[2*p+1].data;
	return ;
}
int solve(int p,int k)
{
	if (node[p].l==node[p].r)
		return node[p].l;
	if (node[2*p].data>=k)
		return solve(2*p,k);
	return solve(2*p+1,k-node[2*p].data);
}
int main()
{
	freopen("flandre.in","r",stdin);
	freopen("flandre.out","w",stdout);
	int n,k,x;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		x=solve(1,k);
		printf("%d\n",a[x]);
		Push(1,x,-1);
	}
	return 0;
}
