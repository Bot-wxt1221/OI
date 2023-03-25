//分析:因为字符串可以直接比较大小,对明星名字其进行排序,然后在得到信息时进行二分查找即可找到该明星。时间复杂度O(k*logn)。
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
struct pp
{
	string s;
	int t;
} a[10001]; 
bool cmp(pp a,pp b)  { if (a.s < b.s) return 1;	return 0; }
bool cmp1(pp a,pp b) 
{ 
	if(a.t != b.t) return a.t > b.t;
	else return a.s < b.s; 
}
int find(string s)
{
	int l = 0, r = n - 1;	
	while (l <= r)
	{
		int mid = l + r >> 1; 
		if (a[mid].s == s) return mid;
        if (a[mid].s < s) l = mid + 1; else r = mid - 1;
	}
}

int main(void)
{
	freopen("oier.in","r",stdin);
	freopen("oier.out","w",stdout);
	cin >> n;
	for (int i = 0; i < n; i++ ) 
		cin >> a[i].s;
	sort(a,a+n,cmp);
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++)
	{
		string s;
		int t;
		cin >> s;
		cin >> t;
		a[find(s)].t += t;
	}
	sort(a,a+n,cmp1);
	for (int i = 0; i < n; i++) 
		cout << a[i].s << " "<< a[i].t << endl; 
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

