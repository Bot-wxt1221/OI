#include <cstdio>
#include <cmath>
#include <algorithm>

#define LL long long

#define MAXN 12000

#define H_IO

using namespace std;

struct ang
{
	int l, w;
	int t, h;
	LL s;
};

int R;
int N;
ang poi[MAXN];

bool judge(int key);
bool cutdown(int x);

int main()
{
	int i, j;
	
	#ifdef H_IO
	freopen("rectangle.in", "r", stdin);
	freopen("rectangle.out", "w", stdout);
	#endif
	
	scanf("%d %d", &R, &N);
	for (i=0; i<N; i++)
	{
		scanf("%d %d %d %d", &poi[i].l, &poi[i].t, &poi[i].w, &poi[i].h);
		poi[i].s = (LL)poi[i].w * poi[i].h;
	}
	
	int l = 0, r = R, mid;
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
	
	if (cutdown(l))
	{
		int right = R;
		for (i=0; i<N; i++)
		{
			if (poi[i].l >= l && poi[i].l <= right)
			{
				right = poi[i].l;
			}
		}
		
		l = right;
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
	LL L = 0, R = 0;
	
	for (i=0; i<N; i++)
	{
		if (poi[i].l + poi[i].w <= key)
		{
			L += poi[i].s;
		}
		if (poi[i].l >= key)
		{
			R += poi[i].s;
		}
		if (poi[i].l <= key && poi[i].l + poi[i].w >= key)
		{
			L += (key - poi[i].l) * poi[i].h;
			R += (poi[i].l + poi[i].w - key) * poi[i].h;
		}
	}
	
	if (L < R)
	{
		return false;
	}
	
	return true;
}

bool cutdown(int x)
{
	int i;
	for (i=0; i<N; i++)
	{
		if (poi[i].l < x && poi[i].l + poi[i].w > x)
		{
			return false;
		}
	}
	
	return true;
}
