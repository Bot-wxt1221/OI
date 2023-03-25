#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[1000005];
int main()
{
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int ans=0;
	int i=n;
	bool first=true;
	while (i>=1)
	{
		if (first)//第一组特别判断。 
		{
			first=false;
			ans++;
			i-=a[i];
			continue;
		}
		int next_i=i-a[i];
		if (next_i<0)//是否有足够的人数 
		{
			i--;
			continue;
		}
		bool divide=false;//是否决定将一部分的人划到前面一组，并以新的人作为组长 
		for (int j=i;j>next_i;j--)
		{
			if (j-a[j]>next_i)
			{
				i=j;
				divide=true;
			}
			if (divide) break;
		}
		if (divide) continue;
		i=next_i;
		ans++;
	}
	cout<<ans<<endl;
	fclose (stdin);
	fclose (stdout);
	return 0;
}
