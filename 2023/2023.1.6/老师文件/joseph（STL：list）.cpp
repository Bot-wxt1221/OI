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
	for(int i = 1; i <= n; i++) //��������
		node.push_back(i);
	list<int>::iterator it = node.begin();
	while(node.size() > 1){ //list �Ĵ�С�� STL �Լ�����
		for(int i = 1; i < m; i++){ //���� m
			it++;
			if(it == node.end()) //ѭ������end()�� list ĩ����һλ��
			it = node.begin();
		}
		cout << *it << " ";
		list<int>::iterator next = ++it;
		if(next == node.end()) next = node.begin(); //ѭ������
		node.erase(--it); //ɾ������ڵ㣬node.size()�Զ���1
		it = next;
	}
	cout << *it;
	return 0;
}

/*
����:
10 3

���:
3 6 9 2 7 1 8 5 10 4
*/
