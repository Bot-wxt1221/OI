#include <cstdio>
#include <algorithm>
#define MAXX 51000
using namespace std;
int a[MAXX], b[MAXX];
int L,n,m;
int work(int mid);

int main(void)
{
	int mid;
	freopen("house.in","r",stdin);
	freopen("house.out","w",stdout);
	
	scanf("%d%d%d",&L,&n,&m);
	for(int i = 1; i <= n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	n++;
	a[0] = 0; a[n] = L;
	int left = 0, right = L;
	while(left + 1 < right)
	{
		mid = (left + right) / 2;
		if( work(mid) > m ) right = mid;
		else left = mid;
	}
	if( work(right) <= m ) printf("%d",right);
	else printf("%d",left);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

int work(int mid)
{
	int k = 0;
	for(int i = 0; i <= n; i++) b[i] = a[i];
	for(int i = 1; i <= n; i++) 
	{
		if(b[i] - b[i-1] < mid)
		{
			b[i] = b[i-1];
			k++;
		}
		if(k > m) return k;
	}
	return k;
}





