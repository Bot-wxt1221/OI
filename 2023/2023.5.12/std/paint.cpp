/*
����ͷβ������������Ͱ�κ�������ͬ��ɫ����Ͱ��Ķ��䲻Ӱ��𰸣�ȥ�������ǡ�
Ȼ�����������������������Ͱ�еĶ��䣨��������ֱ�Ϊa,b��������b-a�����᷽����
�����ж���ķ������˻���Ϊ����
*/
#include <cstdio>
#include <algorithm>
#define mod 1000000009
#define ll long long
using namespace std;

ll ans = 1;
int n, m;
struct data {
	int val, pos;
} a[100005];

int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

bool operator <(data a, data b) {
	return a.pos < b.pos;
}

int main() {
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	n = read();
	m = read();
	for(int i = 1; i <= m; i++) {
		char ch[2];
		scanf("%s", ch);
		a[i].val = ch[0]-'A';
		a[i].pos = read();
	}
	sort(a + 1, a + m + 1);
	for(int i = 2; i <= m; i++)
		if(a[i].val != a[i-1].val)
			ans = ans * (a[i].pos - a[i - 1].pos) % mod;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

