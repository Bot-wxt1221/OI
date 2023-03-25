#include <cstdio>
#include <algorithm>
using namespace std;

char s[20][5];
int tot1, tot2, tot3, n;

int main()
{
	freopen("prize.in", "r", stdin);
	freopen("prize.out", "w", stdout);
	for(int i = 0; i <= 11; i++) scanf("%s", s[i]);
	for(int i = 5; i <= 9; i++)
	{
		if (s[i][0] == '0') tot2 = 2000;
		if (s[i][0] == '0' || s[i][0] == '1') tot1 = 3000;
	}
	tot3 = 1000; 
	for(int i = 0; i <= 4; i++) if (s[i][0] != 'A') tot3 = 0;
	for(int i = 0; i <= 2; i++) if (s[i][0] > 'B') tot1 = 0;
	if (s[10][0] == 'N') tot1 = tot3 = 0;
	if (s[11][0] == 'N') printf("%d\n", max(max(tot1, tot2), tot3));
		else printf("%d\n", tot1 + tot2 + tot3);
	return 0;
} 
