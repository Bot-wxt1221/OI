#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long s[1000005],ss[1000005];
int main()
{
//	freopen("rectangle.in","r",stdin);
//	freopen("rectangle.out","w",stdout);
	int R,n,x,y,w;long long h;
	memset(s,0,sizeof(s));
	memset(ss,0,sizeof(ss));
	scanf("%d%d",&R,&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d%lld",&x,&y,&w,&h);
		s[x+1]+=h;s[x+w+1]-=h;
	}
	for (int i=1;i<=R;i++)
	{
		s[i]+=s[i-1];
		cout<<s[i]<<" ";
		ss[i]=ss[i-1]+s[i];
	}
	cout<<endl;
	for (int i=1;i<=R;i++)
	{
		cout<<ss[i]<<" ";
	}
	cout<<endl;
	int ans=0;
	for (int i=R;i>=0;i--)
	{
		if (ss[i]<ss[R]-ss[i])
		{
			ans=i+1;
			break;
		}
	}
	while(ans<R&&ss[ans+1]-ss[ans]==0)
		ans++;
	printf("%d\n",ans);
	return 0;
}
