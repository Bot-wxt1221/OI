#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 1005;

int cnt;  //组件的类型数
map<string, int> id;
int ID(string s) {
	if(!id.count(s)) id[s] = cnt++;
	return id[s];
} 

struct Component {
	int price;
	int quality;
};

int n, b;  //组件的数目， 预算
vector<Component> comp[MAXN];

//品质因子不小于 q 的组件能否组装成一个不超过 b 元的电脑
bool ok(int q) {
	int sum = 0;
	for(int i = 0; i < cnt; i++) {
		int cheapest = b + 1, m = comp[i].size();
		for(int j = 0; j < m; j++) {
			if(comp[i][j].quality >= q) cheapest = min(cheapest, comp[i][j].price);
		}
		if(cheapest == b + 1) return false;
		sum += cheapest;
		if(sum > b) return false;
	}
	return true;
} 

int main() {
//	freopen("assemble.in", "r", stdin);
//	freopen("assemble.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &b);
		
		cnt = 0;
		for(int i = 0; i < n; i++) comp[i].clear();
		id.clear();
		
		int maxq = 0;
		for(int i = 0; i < n; i++) {
			char type[30], name[30];
			int p, q;
			scanf("%s%s%d%d", type, name, &p, &q);
			maxq = max(maxq, q);
			comp[ID(type)].push_back((Component) {p, q});
		}
		
		int L = 0, R = maxq;
		while(L < R) {
			int M = L + (R-L+1) / 2;
			if(ok(M)) L = M; else R = M - 1;
		}
		printf("%d\n", L);		
	}
	
	return 0;
}

/*
Sample Input
1
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10

Sample Output
9
*/



