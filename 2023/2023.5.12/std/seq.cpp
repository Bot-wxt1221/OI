/*
考虑最后一行，因为其代表文件结束，所以解密后的a=b=c=0。那么我们可以知道倒数第二行的答案（LastAns=-a=-b=-c）。
那么原始式子即转换成一个简单的三元一次式子（只和a,b,c有关），然后这解密后的值又可以由上一行的答案和输入的a0,b0,c0得到，
于是就变成了一个只和LastAns有关系的一元一次式子，所以又可以得到了上一行的答案。所以这样一直算回去就好了。
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

