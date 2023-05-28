#include <cstdio>

#define LL long long

#define H

using namespace std;

int N;
LL all = 0LL;
int stack[120], top;
void dfs(int x);

int main()
{
	int i, j;
	
	#ifdef H
	freopen("tap.in", "r", stdin);
	freopen("tap.out", "w", stdout);
	#endif
	
	scanf("%d", &N);
	top = 0;
	stack[top++] = 1;
	dfs(1);
	printf("%lld", all);
	
	#ifdef H
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

void dfs(int x)
{
	if (x > N)
	{
		return;
	}
	if (x == N)
	{
		all++;
		return;
	}
	
	int i;
	for (i=0; i<top; i++)
	{
		if (stack[i] > 0)
		{
			stack[i]--;
			
			stack[top++] = 2;
			dfs(x + 1);
			top--;
			stack[top++] = 3;
			dfs(x + 2);
			top--;
			
			stack[i]++;
		}
	}
	
	return;
}
