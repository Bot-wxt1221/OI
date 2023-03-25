//����:��Ϊ�ַ�������ֱ�ӱȽϴ�С,�������������������,Ȼ���ڵõ���Ϣʱ���ж��ֲ��Ҽ����ҵ������ǡ�ʱ�临�Ӷ�O(k*logn)��
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

