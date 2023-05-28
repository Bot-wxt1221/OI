#include <iostream>
#include <cstdio>
using namespace std;
int n;
int ans=0;//方案总数 
void wxt(int x,int n,int m,int k);
//x为这个插线板的插座个数,n为需要的插座个数,m为已有的插座个数,k为当前层次的分枝数 
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
