#include <cstdio>
#include <map>
#include <algorithm>

typedef std::pair<int, int> PII;
typedef std::map<PII, char> Map;
typedef Map::iterator Mit;
Map S;

int n, m, cx, cy, dx, dy;
long long T;

int main(){
	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);
	scanf("%d%d%I64d", &n, &m, &T);
	while(n--){
		char buf[4];
		scanf("%d%d%s", &cx, &cy, buf);
		S[PII(cx, cy)] = buf[0];
	}
	cx = cy = 0; dx = 1; dy = 0;
	while(T--){
		cx += dx; cy += dy;
		Mit i = S.find(PII(cx, cy));
		if(i != S.end()){
			if(i->second == '/') std::swap(dx, dy);
			else{dx = -dx; dy = -dy; std::swap(dx, dy);}
		}
	}
	printf("%d %d\n", cx, cy);
	return 0;
}
