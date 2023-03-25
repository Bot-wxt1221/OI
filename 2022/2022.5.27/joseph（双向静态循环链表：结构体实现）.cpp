#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 105;
struct node{ //双向链表
	int id; //节点编号
	//int data; //如有必要，定义一个有意义的数据
	int preid; //前一个节点
	int nextid; //后一个节点
}nodes[maxn];

int main(){
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++){ //建立链表
		nodes[i].id = i;
		nodes[i].preid = i-1; //前节点
		nodes[i].nextid = i+1; //后节点
	}
	nodes[n].nextid = 1; //循环链表：尾指向头
	nodes[1].preid = n; //循环链表：头指向尾
	int now = 1; //从第 1 个开始
	while((n--) >1){
		for(int i = 1; i < m; i++) //数到 m，停下
		now = nodes[now].nextid;
		printf("%d ", nodes[now].id); //打印，后面带空格
		int prev = nodes[now].preid;
		int next = nodes[now].nextid;
		nodes[prev].nextid = nodes[now].nextid; //删除 now
		nodes[next].preid = nodes[now].preid;
		now = next; //新的开始
	}
	printf("%d", nodes[now].nextid); //打印最后一个，后面不带空格return 0;
}

/*
输入:
10 3

输出:
3 6 9 2 7 1 8 5 10 4
*/
