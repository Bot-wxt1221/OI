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
		if (first)//��һ���ر��жϡ� 
		{
			first=false;
			ans++;
			i-=a[i];
			continue;
		}
		int next_i=i-a[i];
		if (next_i<0)//�Ƿ����㹻������ 
		{
			i--;
			continue;
		}
		bool divide=false;//�Ƿ������һ���ֵ��˻���ǰ��һ�飬�����µ�����Ϊ�鳤 
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
