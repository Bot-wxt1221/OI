#include <cstdio>
#include <iostream>
#include <list>
using namespace std;

int main(){
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	list<int> node;
	for(int i = 1; i <= n; i++) //建立链表
		node.push_back(i);
	list<int>::iterator it = node.begin();
	while(node.size() > 1){ //list 的大小由 STL 自己管理
		for(int i = 1; i < m; i++){ //数到 m
			it++;
			if(it == node.end()) //循环链表，end()是 list 末端下一位置
			it = node.begin();
		}
		cout << *it << " ";
		list<int>::iterator next = ++it;
		if(next == node.end()) next = node.begin(); //循环链表
		node.erase(--it); //删除这个节点，node.size()自动减1
		it = next;
	}
	cout << *it;
	return 0;
}

/*
输入:
10 3

输出:
3 6 9 2 7 1 8 5 10 4
*/
