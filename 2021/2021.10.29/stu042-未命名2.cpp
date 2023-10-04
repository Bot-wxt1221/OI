#include <cstdio>
#include <iostream>
#include<cmath>
using namespace std;
int main()
{
	double n,m;
	scanf("%lf%lf",&n,&m);
	printf("%lld",(long long)(0.9+(n-m)/m)+(long long)(log2(m)+0.9));
	return 0;
}
