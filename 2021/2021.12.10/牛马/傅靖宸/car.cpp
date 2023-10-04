#include <cstdio>
#include <cstring>

#define LL long long

#define HHH

using namespace std;

struct poi
{
	int x, y, d;
};

int W, H;
LL all = 0LL;
//0 1 2 3
//^ V < >
poi Move[4][2];
//				 = {(poi){-1, 0, 0}, (poi){0, -1, 2}, 
//				  (poi){1, 0, 1}, (poi){0, 1, 3}, 
//				  (poi){0, -1, 2}, (poi){1, 0, 1}, 
//				  (poi){0, 1, 3}, (poi){-1, 0, 0}};
bool map[12][12][12][12];
int ans[9][9] = {};

inline bool access(poi now);
void dfs(poi now);

int main()
{
	int i, j;
	
	#ifdef HHH
	freopen("car.in", "r", stdin);
	freopen("car.out", "w", stdout);
	#endif
	
	memset(map, false, sizeof(map));
	
	Move[0][0].x = -1, Move[0][0].y = 0, Move[0][0].d = 0; Move[0][1].x = 0, Move[0][1].y = -1, Move[0][1].d = 2;
	Move[1][0].x = 1, Move[1][0].y = 0, Move[1][0].d = 1;  Move[1][1].x = 0, Move[1][1].y = 1, Move[1][1].d = 3;
	Move[2][0].x = 0, Move[2][0].y = -1, Move[2][0].d = 2; Move[2][1].x = 1, Move[2][1].y = 0, Move[2][1].d = 1;
	Move[3][0].x = 0, Move[3][0].y = 1, Move[3][0].d = 3;  Move[3][1].x = -1, Move[3][1].y = 0, Move[3][1].d = 0;
	
	scanf("%d %d", &W, &H);
	all = 0LL;
	W++, H++;
	
	poi t;
	t.x = H, t.y = 1, t.d = 3;
	map[t.x][t.y][t.x + 1][t.y] = true;
	map[t.x][t.y][t.x][t.y - 1] = true;
	dfs(t);
	
	printf("%lld", all);
		
	
	#ifdef HHH
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

inline bool access(poi now, poi pre)
{
	if (now.x < 1 || now.y < 1 || now.x > H || now.y > W)
	{
		return false;
	}
	if (map[now.x][now.y][pre.x][pre.y] == true || map[pre.x][pre.y][now.x][now.y] == true)
	{
		return false;
	}
	
	return true;
}

void dfs(poi now)
{
	if (now.x == 1 && now.y == W)
	{
		all++;
		return;
	}
	
	int k;
	poi t;
	for (k=0; k<2; k++)
	{
		t.x = now.x + Move[now.d][k].x;
		t.y = now.y + Move[now.d][k].y;
		t.d = Move[now.d][k].d;
		//printf("%d %d %d\n%d %d %d\n%d\n\n", t.x, t.y, t.d, now.x, now.y, now.d, k);
		
		if (access(t, now) == true)
		{
			map[now.x][now.y][t.x][t.y] ^= 1;
			dfs(t);
			map[now.x][now.y][t.x][t.y] ^= 1;
		}
	}
	
	return;
}
