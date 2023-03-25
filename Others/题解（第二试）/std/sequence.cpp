#include <cstdio>
#include <cstring>

#define LL long long
//ʮ��OIһ���գ�����long long������ 

#define H

using namespace std;

int n, m;
LL a[510000], K[510000], sK[510000], D[510000], sD[510000], ssD[510000];
//a:�洢ԭ���� 
//K:�������ò����ʽ�洢 
//sK:K��ǰ׺�� 
//D: �������ò����ʽ�洢 
//sD:D��ǰ׺�� 
//ssD:sD��ǰ׺�� 

inline void Read(int &p);//��������õ�д�� 
//��ʵ����ⲻ�ÿ������Ϊ�������ݷ�Χ��С�� 

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
		ssD[r + 1] -= d * (r - l);//��ʼ���� 
	}
	for (register int i=1; i<=n; i++)
	{
		sK[i] = sK[i - 1] + K[i];
		sD[i] = sD[i - 1] + D[i];
		ssD[i] += ssD[i - 1] + sD[i];
		a[i] += sK[i] + ssD[i];//һ����ǰ׺��һ�ߵó��� 
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
		p = (p << 3) + (p << 1) + (c & 15);//λ������� 
		c = getchar();
	}
	if (isNeg)
	{
		p = -p;
	}
	
	return;
}
