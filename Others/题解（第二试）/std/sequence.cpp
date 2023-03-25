#include <cstdio>
#include <cstring>

#define LL long long
//十年OI一场空，不开long long见祖宗 

#define H

using namespace std;

int n, m;
LL a[510000], K[510000], sK[510000], D[510000], sD[510000], ssD[510000];
//a:存储原数列 
//K:将首项用差分形式存储 
//sK:K的前缀和 
//D: 将公差用差分形式存储 
//sD:D的前缀和 
//ssD:sD的前缀和 

inline void Read(int &p);//快读，引用的写法 
//其实这道题不用快读，因为后面数据范围改小了 

int main()
{
	int l, r, k, d;
	
	#ifdef H
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	#endif
	
	Read(n);
	Read(m);
	
	for (register int i=1; i<=n; i++)
	{
		scanf("%lld", &a[i]);
	}
	for(register int i=0; i<m; i++)
	{
		Read(l);
		Read(r);
		Read(k);
		Read(d);
		
		K[l] += k;
		K[r + 1] -= k;
		D[l + 1] += d;
		D[r + 1] -= d;
		ssD[r + 1] -= d * (r - l);//初始处理 
	}
	for (register int i=1; i<=n; i++)
	{
		sK[i] = sK[i - 1] + K[i];
		sD[i] = sD[i - 1] + D[i];
		ssD[i] += ssD[i - 1] + sD[i];
		a[i] += sK[i] + ssD[i];//一边做前缀和一边得出答案 
		printf("%lld ", a[i]);
	}
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

inline void Read(int &p)
{
	p = 0;
	bool isNeg = false;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-')
	{
		c = getchar();
	}
	if(c == '-')
	{
		isNeg = true;
		c = getchar();
	}
	while ('0' <= c && c <= '9')
	{
		p = (p << 3) + (p << 1) + (c & 15);//位运算加速 
		c = getchar();
	}
	if (isNeg)
	{
		p = -p;
	}
	
	return;
}
