#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ans=0;//�������� 
void wxt(int x,int n,int m,int k);
//xΪ������߰�Ĳ�������,nΪ��Ҫ�Ĳ�������,mΪ���еĲ�������,kΪ��ǰ��εķ�֦�� 
int main()
{
	cin >> n;
	
	freopen("tap.in","r",stdin);
	freopen("tap.out","w",stdout);
	
	wxt(2,n,2,1);
	wxt(3,n,3,1);
	
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void wxt(int x,int n,int m,int k)
{
	if(m>n) return;
	if(m==n)
	{
		ans++;
		return;
	}
	if(m<n)
	{
		for(int i=1;i<=k;i++)
			for(int j=x;j>=1;j--)
			{
				wxt(2,n,m+j,j);
				wxt(3,n,m+2*j,j);
			}
	}
	return;
}
