//πÈ≤¢≈≈–Ú«ÛƒÊ–Ú∂‘ 
#include <cstdio>
#include <iostream>
using namespace std;
int temp[10001],a[10001],tot = 0;
void merge_sort(int left,int right);

int main(void)
{
	int n;	
	freopen("dream.in","r",stdin);
	freopen("dream.out","w",stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	merge_sort(1,n);
	cout << tot;
	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

void merge_sort(int left,int right)
{
	if(left == right) return;
	int mid = (left + right) / 2;
	merge_sort(left,mid);
	merge_sort(mid+1,right);
	int p = left, i = left, j = mid + 1;
	while(i <= mid && j <= right)
	{
		if(a[i] > a[j])
		{
			tot = tot + mid - i + 1;
			temp[p++] = a[j++];
		}
		else temp[p++] = a[i++];
	}
	while(i <= mid) temp[p++] = a[i++];
	while(j <= right) temp[p++] = a[j++];
	for( i = left; i <= right; i++)
		a[i] = temp[i];
	
	return;
}
