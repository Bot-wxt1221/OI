#include <cstdio>
#include <iostream>
using namespace std;
double a[10001];

int main(void)
{
	int n, k, z, x = 0, y = 10000000, mid;         //x����߽磬y���ұ߽磬������Ϊ��λ 
	double w = 0.0;
	freopen("cable.in","r",stdin);
	freopen("cable.out","w",stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] *= 100;                   //�������߳��ȣ�ת��Ϊ���� 
	}
	while(x <= y)                //���ֲ���
	{
		z = 0;
		mid = (x+y)/2;          //�м���Ϊ�ָ���
		for(int i = 1; i <= n; i++)
			z += a[i]/mid;		//ͳ�ƿ����и���ٸ�����
		if(z < k)  y = mid - 1;    //����ʱ�õ���������С����Ҫ����������������ұ߽�Ϊ mid-1
		else    //����ʱ�õ������������ڵ�����Ҫ�����������������߽�Ϊ mid+1
		{
			x = mid + 1;        
			if(mid > w) w = mid;         //��¼��������߳��� 
		} 
	}	
	printf("%.2lf",w/100); 
	fclose(stdin);
	fclose(stdout);
	return 0;
}



