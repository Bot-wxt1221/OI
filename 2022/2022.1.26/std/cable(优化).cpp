#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
double n,k,a[100086],maxx = -2147483647;
double x;

int main(void)
{
	
	freopen("cable.in","r",stdin);
	freopen("cable.out","w",stdout);
	scanf("%lf%lf",&n,&k);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf",&x);
		a[i] = x;
		maxx = max(maxx,a[i]);        //找出最长的网线 
	}
	double l = 0, r = maxx;
	while(l + 0.001 < r)    //二分查找
	{
		double mid = (l + r) / 2.0;
		int ans = 0;
		for(int i = 1;i <= n; i++) ans += (a[i]/mid);
		if(ans >= k) l = mid;
		else r = mid; 
	} 
	int ans = 0, an = 0;
	for(int i = 1; i <= n; i++)
	{
		an += (a[i]/r);
		ans += (a[i]/l);
	}
	if(an >= k) l = r;
	printf("%.2lf",floor(l*100)/100.0);             //保留两位 
	fclose(stdin);
	fclose(stdout);
	return 0;
}



