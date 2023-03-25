#include <cstdio> 
#include <iostream> 
#include <cstring>
#include <algorithm>
using namespace std;
struct pig{
	char name[21];
	int foolish,home;
	int id;
}p[100005];
int n,m;
bool check(int k)
{
	int cnt=1;
	int w=0,i=1;
	while (i<=n)
	{
		if(w+p[i].foolish>k)//��Ҫһ���µ���Ȧ 
		{
			cnt++;
			w=0;
		}
		else
		{
			w+=p[i].foolish;
			p[i].home=cnt;
			i++;
		}
		if (cnt>m) return false;//�����Ҫ����Ȧ����m���ͷ���false 
	}
	return true;
}
int main()
{
	freopen("pig.in","r",stdin);
	freopen("pig.out","w",stdout);
	scanf("%d%d",&n,&m);
	int l=1,r=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",p[i].name);
		scanf("%d",&p[i].foolish);
		p[i].id=i;
		r+=p[i].foolish;
	}
	while (l<r)//���� 
	{
		int m=(l+r)/2;
		if (check(m))//�ж� 
			r=m;
		else
			l=m+1;
	}
	check(l);//����һ��Ҫcheck(l)һ�°�������QWQ 
	printf("%d\n",l);
	int now_home=0;
	for(int i=1;i<=n;i++)
	{
		if (now_home!=p[i].home)
		{
			if (now_home!=0)
				putchar('\n');
			printf("%d:",p[i].home);
			now_home=p[i].home;
		}
		if (now_home==p[i].home)
		{
			printf("%s ",p[i].name);
		}
	}
	while (now_home<m)
	{
		putchar('\n');
		printf("%d:",++now_home);
	}
	return 0;
}
