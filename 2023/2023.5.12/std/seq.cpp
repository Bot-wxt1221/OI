/*
�������һ�У���Ϊ������ļ����������Խ��ܺ��a=b=c=0����ô���ǿ���֪�������ڶ��еĴ𰸣�LastAns=-a=-b=-c����
��ôԭʼʽ�Ӽ�ת����һ���򵥵���Ԫһ��ʽ�ӣ�ֻ��a,b,c�йأ���Ȼ������ܺ��ֵ�ֿ�������һ�еĴ𰸺������a0,b0,c0�õ���
���Ǿͱ����һ��ֻ��LastAns�й�ϵ��һԪһ��ʽ�ӣ������ֿ��Եõ�����һ�еĴ𰸡���������һֱ���ȥ�ͺ��ˡ�
*/
#include <cstdio>
#include <iostream>
using namespace std;

long long n, cnt, top, ans;
long long v[50005], res[500005];
long long a[500005], b[500005], c[500005];

long long read() {
	long long x = 0, f = 1;
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

int main() {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	n = read();
	for(int i = 1 ; i <= n; i++)
		v[i] = read();
	cnt = 1;
	while(scanf("%lld%lld%lld", &a[cnt], &b[cnt], &c[cnt]) != EOF)
		cnt++;
	cnt--;

	res[++top] = ans = -a[cnt--];
	for(int k = cnt; k; k--) {
		long long xi = v[ans], i = ans;
		long long t1 = a[k] * (i + 1) * xi * xi + (b[k] + 1) * i * xi + (c[k] + i);
		long long t2 = (i + 1) * xi * xi + i * xi + 1;
		ans = -t1 / t2;
		res[++top] = ans;
	}
	for(int i = top - 1; i; i--) printf("%lld\n", res[i]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

