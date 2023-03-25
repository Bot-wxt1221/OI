#include <cstdio>
#include <cstring>
#include <algorithm>

#define LL long long

#define MAXN 12000

#define H_IO

using namespace std;

struct OI
{
	char n[39];
	LL w;
};

int N, K;
OI poi[MAXN];

inline int cmp1(char a[], char b[]);
bool cmp_sort(OI a, OI b);
bool cmp_w(OI a, OI b);

int find(char s[]);

int main()
{
	int i, j;
	char n[39];
	LL w;
	
	#ifdef H_IO
	freopen("oier.in", "r", stdin);
	freopen("oier.out", "w", stdout);
	#endif
	
	scanf("%d", &N);
	for (i=0; i<N; i++)
	{
		scanf("%s", poi[i].n);
		poi[i].w = 0;
	}
	sort(poi, poi + N, cmp_sort);
//	for (i=0; i<N; i++)
//	{
//		printf("%s %lld\n", poi[i].n, poi[i].w);
//	}
	
	scanf("%d", &K);
	for (i=0; i<K; i++)
	{
		scanf("%s %lld", n, &w);
		poi[find(n)].w += w;
	}
	sort(poi, poi + N, cmp_w);
	for (i=0; i<N; i++)
	{
		printf("%s %lld\n", poi[i].n, poi[i].w);
	}
	
	#ifdef H_IO
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

inline int cmp1(char a[], char b[])
{
	int i, lena = strlen(a), lenb = strlen(b);
	if (lena > lenb)
	{
		return 1;
	}
	if (lena < lenb)
	{
		return -1;
	}
	
	for (i=0; i<lena; i++)
	{
		if (a[i] > b[i])
		{
			return 1;
		}
		if (a[i] < b[i])
		{
			return -1;
		}
	}
	
	return 0;
}

bool cmp_sort(OI a, OI b)
{
	return cmp1(a.n, b.n) == -1;
}

bool cmp_w(OI a, OI b)
{
	if (a.w == b.w)
	{
		return cmp1(a.n, b.n) == -1;
	}
	
	return a.w > b.w;
}

int find(char s[])
{
	int l = 0, r = N - 1, mid;
	
	while (l < r)
	{
		mid = (l + r) / 2;
		if (cmp1(poi[mid].n, s) == -1)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	
	return l;
}
