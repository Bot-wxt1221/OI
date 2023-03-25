#include <cstdio>
#include <iostream>
using namespace std;
double a[10001];

int main(void)
{
	int n, k, z, x = 0, y = 10000000, mid;         //x是左边界，y是右边界，以厘米为单位 
	double w = 0.0;
	freopen("cable.in","r",stdin);
	freopen("cable.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] *= 100;                   //读入网线长度，转换为厘米 
	}
	while(x <= y)                //二分查找
	{
		z = 0;
		mid = (x+y)/2;          //中间数为分割数
		for(int i = 1; i <= n; i++)
			z += a[i]/mid;		//统计可以切割多少根网线
		if(z < k)  y = mid - 1;    //若此时得到的网线数小于需要的网线数，则更改右边界为 mid-1
		else    //若此时得到的网线数大于等于需要的网线数，则更改左边界为 mid+1
		{
			x = mid + 1;        
			if(mid > w) w = mid;         //记录下最长的网线长度 
		} 
	}	
	printf("%.2lf",w/100); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}



