#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ans=0,much=1;
int n;
void dfs(int now ,long long u1,long long u2,long long u3)
{
	if (now>n) return ;
	if (now==n)
	{
		ans+=much;
		return ;
	}
	
	if (u1>0)
	{
		much*=u1;
		dfs(now+1,u1-1,u2+1,u3);
		much/=u1;
	}
	if (u2>0)
	{
		much*=u2;
		dfs(now+1,u1+1,u2,u3);
		much/=u2;
	}
	if (u3>0)
	{
		much*=u3;
		dfs(now+1,u1,u2+2,u3-1);
		much/=u3;
	}
	////////////////////
	if (u1>0)
	{
		much*=u1;
		dfs(now+2,u1-1,u2,u3+1);
		much/=u1;
	}
	if (u2>0)
	{
		much*=u2;
		dfs(now+2,u1+1,u2-1,u3+1);
		much/=u2;
	}
	if (u3>0)
	{
		much*=u3;
		dfs(now+2,u1,u2+1,u3);
		much/=u3;
	}
	
	return ;
}
int main()
{
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	cin>>n;
	dfs(1,1,0,0);
	cout<<ans<<endl;
	return 0;
}
