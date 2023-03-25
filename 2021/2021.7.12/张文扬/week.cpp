#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
long long qk(long long a,long long  b)
{
	if(a==1)return a%7;
	if(b==0)return 1;
	if(b%2==0)
	{
		int k=qk(a,b>>1);
		return k*k%7;
	}
	else return a*qk(a,b-1) %7;

}
int main()
{
	freopen("week.in","rb",stdin);
	freopen("week.out","wb",stdout);
	long long n,m;
	cin>>n>>m;
	if(qk(n,m)%7==0)cout<<7;
	else cout<<qk(n,m);
	return 0;
}
