#include <cstdio>
#include <algorithm>

#define LL long long

#define MAXN 120000

//#define H_IO

using namespace std;

int L, N, M;
int x[MAXN];

bool judge(int key);

int main()
{
	int i, j;
	
	#ifdef H_IO
	freopen("house.in", "r", stdin);
	freopen("house.out", "w", stdout);
	#endif
	
	scanf("%d %d %d", &L, &N, &M);
	for (i=0; i<N; i++)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + N);
	int l = 1, r = x[N - 1], mid;
	while (l < r)
	{
		mid = (l + r) / 2;
		if (judge(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	if (judge(l) == false)
	{
		l--;
	}
	
	printf("%d", l);
	
	#ifdef H_IO
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

bool judge(int key)
{
	int i, j;
	int pre = 0, pos = 0, remove = 0;
	while (pos < N)
	{
		while (pos < N && x[pos] - pre < key)
		{
			pos++;
			remove++;
		}
		pre = x[pos];
		pos++;
	}
	if (remove > M)
	{
		return false;
	}
	
	return true;
}
