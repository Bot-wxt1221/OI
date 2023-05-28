#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 105; //定义静态链表的空间大小
struct node{ //单向链表
	int id;
	//int data; //如有必要，定义一个有意义的数据
	int nextid;
} nodes[maxn]; 

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++) {
		nodes[i].id = i;
		nodes[i].nextid = i + 1;
	}
	nodes[n].nextid = 1; //循环链表：尾指向头
	int now = 1, prev = 1; //从第 1 个开始
	while((n--)> 1) {
		for(int i = 1; i < m; i++) { //数到 m，停下
			prev = now;
			now = nodes[now].nextid;
		}
		printf("%d ", nodes[now].id); //带空格
		nodes[prev].nextid = nodes[now].nextid; //跳过节点 now，即删除now
		now = nodes[prev].nextid; //新的 now
	}
	printf("%d", nodes[now].nextid); //打印最后一个，后面不带空格
	return 0;
}

/*
输入:
10 3

输出:
3 6 9 2 7 1 8 5 10 4
*/
