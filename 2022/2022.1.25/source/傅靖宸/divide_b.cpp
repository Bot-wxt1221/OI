#include <cstdio>

#define LL long long

#define MAXN 120000

#define H_IO

using namespace std;

int N, M;
int x[MAXN];
int all = 0;

bool judge(int key);

int main()
{
	int i, j;
	
	#ifdef H_IO
	freopen("divide_b.in", "r", stdin);
	freopen("divide_b.out", "w", stdout);
	#endif
	
	scanf("%d %d", &N, &M);
	for (i=0; i<N; i++)
	{
		scanf("%d", &x[i]);
		all += x[i];
	}
	
	int l = 0, r = all, mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (judge(mid))
		{
			r = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	
	printf("%d", r);
	
	#ifdef H_IO
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

bool judge(int key)
{
	int i, j;
	int v = 0, pos = 0, part = 0;
	while (pos < N)
	{
		v = 0;
		while (pos < N && v <= key)
		{
			v += x[pos];
			pos++;
		}
		if (v > key)
		{
			pos--;
			v -= x[pos];
		}
		if (x[pos] > key || v > key)
		{
			return false;
		}
		
		part++;
	}
	if (part > M)
	{
		return false;
	}
	
	return true;
}

/*
13 4
1 1 4 5 1 4 1 9 1 9 8 1 0
*/
