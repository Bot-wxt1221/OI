//创建无向图的链式前向星 
#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100000 + 5;
int maxx[maxn], head[maxn];
int n, m, x, y, w, cnt;

struct Edge{
	int to, w, next;
} e[maxn];

void add(int u, int v, int w) { //添加一条边u--v 
 	e[cnt].to = v;
 	e[cnt].w = w;
	e[cnt].next = head[u];
	head[u] = cnt++;
} 

void printg(){ //输出链式前向星
	cout << "----------链式前向星如下：----------" << endl;
	for(int v = 1; v <= n; v++) {
		cout << v << "：  ";
		for(int i = head[v]; ~i; i = e[i].next) {
			int v1 = e[i].to, w1 = e[i].w;
			cout << "[" << v1 << " " << w1 << "]\t";
		}
		cout << endl;
	}
}

int main() {
	cin >> n >> m;
	memset(head, -1, sizeof(head));
	cnt = 0;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y >> w;
		add(x, y, w); //添加边
		add(y, x, w); //添加反向边 
	}
	printg();
	return 0;
}
/*
4 5
1 2 5
1 4 3
2 3 8
2 4 12
3 4 9
*/
