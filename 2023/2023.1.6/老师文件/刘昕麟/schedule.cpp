#include <cstdio>
#include <iostream>


using namespace std;
const int N = 100005;
struct note{
	string name;
	int time;
};
note qu[N];
int f = 0, r = 0;
int n, q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("schedule10.in","r",stdin);
	freopen("schedule.out","w",stdout);
//	double start = clock();
	cin >> n >> q;
	note p;
	for(int i = 1; i <= n; i++){
		cin >> p.name >> p.time;
		qu[r++] = p;
	}
	int cnt = 0;
	while(f != r){
		p = qu[f];
		f++;
		f == N - 1 ? f = 0 : f = f;
		if(p.time > q){
			p.time -= q;
			cnt += q;
			qu[r++] = p;
			r == N - 1 ? r = 0 : r = r;
		}
		else{
			cnt += p.time;
			cout << p.name << ' ' << cnt << '\n';
		}
	}
//	cout << (clock() - start) / CLOCKS_PER_SEC;
	return 0;
}

