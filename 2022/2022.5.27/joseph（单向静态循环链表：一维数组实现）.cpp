#include <cstdio>
#include <iostream>
using namespace std;
int nodes[150];

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n-1; i++) //nodes[i]的值就是下一个节点
		nodes[i] = i+1;
	nodes[n] = 1;    //循环链表：尾指向头
	int now = 1, prev = 1; //从第 1 个开始
	while((n--) > 1) {
		for(int i = 1; i < m; i++) { //数到 m，停下
			prev = now;
			now = nodes[now]; //下一个
		}
		printf("%d ", now); //带空格
		nodes[prev] = nodes[now]; //跳过节点 now，即删除now
		now = nodes[prev]; //新的 now
	}
	printf("%d", now); //打印最后一个，不带空格
	return 0;
}

/*
输入:
10 3

输出:
3 6 9 2 7 1 8 5 10 4
*/
