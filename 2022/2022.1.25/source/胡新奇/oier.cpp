#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct OIER{
	char name[35];
	long long data;
	void init()
	{
		data=0;
	}
}oi[10005];
int n,k;
bool Less(char a[],char b[])
{
	if (strlen(a)<strlen(b))return true; 
	if (strlen(b)<strlen(a))return false;
	for (int i=0;i<strlen(a);i++)
		if (a[i]<b[i]) return true;
		else if (a[i]>b[i]) return false;
	return true;
}
bool cmp1(OIER a,OIER b)
{
	return Less(a.name,b.name);
}
bool cmp2(OIER a,OIER b)
{
	if (a.data==b.data)
		return Less(a.name,b.name);
	return a.data>b.data;
}
void add(char S[],long long w)
{
	int l=1,r=n,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if (Less(S,oi[mid].name)) r=mid;
		else l=mid+1;
	}	
//	cout<<oi[l].data<<" "<<w<<endl;
	oi[l].data+=w;
//	cout<<oi[l].data<<" "<<w<<endl;
	return ;
}
int main()
{
	freopen("oier.in","r",stdin);
	freopen("oier.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		oi[i].init();
		scanf("%s",oi[i].name);
	}
	sort(oi+1,oi+n+1,cmp1);
	scanf("%d",&k);
	char ch[35];long long addw;
	for (int i=1;i<=k;i++)
	{
		scanf("%s %lld",ch,&addw);
		add(ch,addw);
	}
	sort(oi+1,oi+n+1,cmp2);
	for (int i=1;i<=n;i++)
		printf("%s %lld\n",oi[i].name,oi[i].data);
	return 0;
}
