#include <cstdio>
#include <cstring>
#include <algorithm>
#define UU 0
#define LL 1
#define DD 2
#define RR 3
//LeftTurn = 1
//RightTurn = 3
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};
#define f(x, y, z) for(int x = (y); x <= (z); ++x)
#define f2(x, y, z) for(int x = (y), asdf = (z); x <= asdf; ++x)
using std::min;
using std::abs;

int N; long long T;
struct mir{int x, y; long long dr;} xm[400086], ym[400086];
inline bool byx(const mir &a, const mir &b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
inline bool byy(const mir &a, const mir &b){
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
inline bool operator ==(const mir &a, const mir &b){
    return a.x == b.x && a.y == b.y;
}

inline mir *findxless(const mir a){
    int l = 0, r = N + 1;
    while(l < r){
        int m = ((l + r) >> 1) + 1;
        if(xm[m] == a) return xm + m;
        else if(byx(xm[m], a)) l = m; else r = m - 1;
    }
    if(l < 1 || l > N || xm[l].x != a.x) return NULL;
    return xm + l;
}
inline mir *findxmore(const mir a){
    int l = 0, r = N + 1;
    while(l < r){
        int m = (l + r) >> 1;
        if(xm[m] == a) return xm + m;
        else if(byx(a, xm[m])) r = m; else l = m + 1;
    }
    if(l < 1 || l > N || xm[l].x != a.x) return NULL;
    return xm + l;
}
inline mir *findyless(const mir a){
    int l = 0, r = N + 1;
    while(l < r){
        int m = ((l + r) >> 1) + 1;
        if(ym[m] == a) return ym + m;
        else if(byy(ym[m], a)) l = m; else r = m - 1;
    }
    if(l < 1 || l > N || ym[l].y != a.y) return NULL;
    return ym + l;
}
inline mir *findymore(const mir a){
    int l = 0, r = N + 1;
    while(l < r){
        int m = (l + r) >> 1;
        if(ym[m] == a) return ym + m;
        else if(byy(a, ym[m])) r = m; else l = m + 1;
    }
    if(l < 1 || l > N || ym[l].y != a.y) return NULL;
    return ym + l;
}

int main(){
	freopen("mirror.in", "r", stdin);
	freopen("mirror.out", "w", stdout);
	scanf("%d%*d%I64d", &N, &T); long long iT = T;
	f(i, 1, N){
		int cx, cy; char buf[4];
		scanf("%d%d%s", &cx, &cy, buf);
		xm[i].x = ym[i].x = cx;
		xm[i].y = ym[i].y = cy;
		if(buf[0] == '/'){
			xm[i].dr = 3; ym[i].dr = 1;
		}else{
			xm[i].dr = 1; ym[i].dr = 3;
		}
	}
	xm[0] = (mir) {-1000000008, -1000000008, 0};
	ym[0] = (mir) {-1000000008, -1000000008, 0};
	xm[N + 1] = (mir) {1000000008, 1000000008, 0};
	ym[N + 1] = (mir) {1000000008, 1000000008, 0};
	std::sort(xm + 1, xm + N + 1, byx);
	std::sort(ym + 1, ym + N + 1, byy);
	int cx = 0, cy = 0, cr = RR;
	for(;;){
		// printf("C %d %d = %d\n", cx, cy, cr);
		mir *res;
		if(cr == UU) res = findxmore((mir) {cx, cy + 1});
		else if(cr == LL) res = findyless((mir) {cx - 1, cy});
		else if(cr == DD) res = findxless((mir) {cx, cy - 1});
		else res = findymore((mir) {cx + 1, cy});
		if(res){
			if(cy == 0 && res->y == 0 && cx < 0 && res->x > 0) T %= (iT - T - cx);
			int dis = abs(res->x - cx) + abs(res->y - cy);
			if(dis < T){
				cx = res->x; cy = res->y; cr = (cr + res->dr) % 4; T -= (long long) dis;
			}else{
				printf("%I64d %I64d\n", (long long) cx + T * (long long) dx[cr], (long long) cy + T * (long long) dy[cr]);
				return 0;
			}
		}else{
			printf("%I64d %I64d\n", (long long) cx + T * (long long) dx[cr], (long long) cy + T * (long long) dy[cr]);
			return 0;
		}
	}
    return 0;
}
