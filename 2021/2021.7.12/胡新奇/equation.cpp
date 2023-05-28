#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main() 
{
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	if (b>a) swap(a,b);
	int x=0;
	int ans=0;
	int x0=c/a,y0=c/b;
	while (x<=c/a)
	{
		int yn=(c/b-(a/b)*x);
		if((c-a*x)%b==0)
		{
			ans=yn*__gcd(a,b)/a;
			ans+=1;
			break;
		}
		x++;
	}
	cout<<ans<<endl;
	return 0;
}
