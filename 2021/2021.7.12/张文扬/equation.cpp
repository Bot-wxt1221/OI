#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long int a,b,c;
long long int gcd(long long int x,long long int y)
{
	return y==0?x:gcd(y,x%y);
}
int main()
{
	freopen("equation.in","rb",stdin);
	freopen("equation.out","wb",stdout);
	cin>>a>>b>>c;
	long long int y=c/b,ans=0;
	if(c%gcd(a,b)!=0){
		cout<<0;return 0;
	}
	while(y>=0)
	{
		if((c-y*b)%a==0)ans++;
		y--;
	}
	cout<<ans;
	return 0;
}
