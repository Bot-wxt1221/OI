#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

struct node{
	int fa;
	int l;
	int num;
}lie[30005];

int n;

int find(int x){
	if(lie[x].fa == x) return x;
	int fx = find(lie[x].fa);
	lie[x].l += lie[lie[x].fa].l;
	lie[x].fa = fx;
	return fx;
}

int main(){
	cin >> n;
	for(int i = 1; i <= 30000; i++) lie[i].fa = i, lie[i].l = 0, lie[i].num = 1;
	for(int i = 1; i <= n; i++){
		char a; cin >> a;
		int b, c; cin >> b >> c;
		int fb = find(b), fc = find(c);
		if(a == 'M'){
			lie[fb].l += lie[fc].num;
			lie[fb].fa = fc;
			lie[fc].num += lie[fb].num;
			lie[fb].num = 0;
		}
		if(a == 'C'){
			if(lie[fb].fa != lie[fc].fa) cout << -1 << '\n';
			else cout << abs(lie[b].l - lie[c].l) - 1 << '\n';
		}
	}	
	return 0;
} 