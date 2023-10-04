//无向图的割点---tarjan_cut算法
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, m; //n个点， m条边

//邻接表存图
struct Edge{
	int to, next;
} e[MAXN << 1];
int head[MAXN], cnt = 0;

void add(int u, int v) {
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt; 
} 
 
//tarjan_cut算法
int num = 0;  //时间戳计数器
int dfn[MAXN], low[MAXN]; //时间戳和追溯点
int root; //根节点 
void tarjan_cut(int u, int fa) { //求割点 
	dfn[u] = low[u] = ++num;
	int count = 0; //对于 root 节点，统计其孩子的数量
	for(int i = head[u]; i; i = e[i].next) {
		int v = e[i].to;
		if(v == fa) continue;
		if(!dfn[v]) {//u的邻接点v未访问过 
			tarjan_cut(v, u);
			low[u] = min(low[u], low[v]);
			if(low[v] >= dfn[u]) { //不能通过除u-v之外的路径回到更早的祖先 
				count++;
				if(u != root || count > 1) {//不是根节点或者是根节点但其孩子大于1个 
					cout << u << endl;
				}
			}
		}
		else { //u的邻接点v已访问过，但不是父亲，即v是u更早的祖先 
			low[u] = min(low[u], dfn[v]);
		}
	} 
	return;
} 

int main() {
	memset(head, 0, sizeof(head));
	memset(dfn, 0 ,sizeof(dfn));
	memset(low, 0, sizeof(low));
	cin >> n >> m;
	int u, v;
	while(m--) {
		cin >> u >> v;
		add(u, v);
		add(v, u);
	}
	for(int i = 1; i <= n; i++) {
		if(!dfn[i]) {
			root = i;
			tarjan_cut(i, 0);
		}
	}
	return 0;
}

/*
输入：
7 7
1 2
2 3
3 5
5 7
5 6
6 4
4 1
输出：
5
*/ 


/*
输入：
10 13
1 2
1 3
1 4
2 3
2 5
3 5
4 6
5 7
5 6
5 8
8 9
8 10
9 10
输出：
8
5
*/ 

