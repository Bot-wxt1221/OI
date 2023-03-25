#include <cstdio>
#include <iostream>
using namespace std;
struct node {
	int data;
	node *next;
}; 

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	node *head, *p, *now, *prev; //定义变量
	head = new node; head->data = 1; head->next = NULL; //分配第一个节点，数据置为 1
	now = head; //当前指针是头
	for(int i = 2; i <= n; i++) {
		p = new node;  p->data = i; p->next = NULL;  //p 是新节点
		now->next = p;   //把申请的新节点连到前面的链表上
		now = p; //尾指针后移一个
	}
	now->next = head; //尾指针指向头：循环链表建立完成	
	
	now = head, prev = head; //从第 1 个开始数
	while((n--) > 1) {
		for(int i = 1; i < m; i++) {   //数到 m，停下
			prev = now;    //记录上一个位置，用于下面跳过第 m 个节点
			now = now->next;
		}
		printf("%d ", now->data); //输出第 m 节点，带空格
		prev->next = now->next; //跳过这个节点
		delete now; //释放节点
		now = prev->next;  //新的一轮
	}
	printf("%d", now->data); //打印最后一个，后面不带空格
	delete now; //释放最后一个节点
	return 0;
}

/*
输入:
10 3

输出:
3 6 9 2 7 1 8 5 10 4
*/
