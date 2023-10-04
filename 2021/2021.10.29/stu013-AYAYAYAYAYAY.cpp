#include <stdio.h>

void judge(int x);

int main()
{
	int i, j;
	
	for (i=1000; i<10000; i++)
	{
		judge(i);
	}
	
	return 0;
}

void judge(int x)
{
	int a = x / 1000, b = x % 1000 / 100, c = x % 100 / 10, d = x % 10;
	int i, j, k;
	int t1, t2, t3, t4, all;
	
	for (i=0; i<2; i++)
	{
		for (j=0; j<2; j++)
		{
			for (k=0; k<2; k++)
			{
				t1 = a, t2 = b, t3 = c, t4 = d;
				if (i == 0)
				{
					t2 += t1 * 10;
					t1 = 1;
				}
				if (j == 0)
				{
					t3 += t2 * 10;
					t2 = 1;
				}
				if (k == 0)
				{
					t4 += t3 * 10;
					t3 = 1;
				}
				all = t1 * t2 * t3 * t4;
				
				if ((i | j | k) && all == d * 1000 + c * 100 + b * 10 + a)
				{
					char ch = '\0';
					//printf("AAA%cAAA", '\0');
					printf("%d : %d%c%d%c%d%c%d\n", x, a, i ? '*' : ch, b, j ? '*' : ch, c, k ? '*' : ch, d);
				}
			}
		}
	}
}
