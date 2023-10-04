//优先队列例程
#include <bits/stdc++.h>
using namespace std;

int main() {
	priority_queue<int> q;
	q.push(93);//入队，插入新元素
	q.push(5);
	q.push(2);
	q.push(33);
	q.push(52);
	q.push(12);

	cout<<"元素个数为："<<q.size()<<endl;
	while(!q.empty()) { //当队列不为空
		cout<<q.top()<<endl;//取队首元素
		q.pop();//出队列要先判断是否为空
	}
	return 0;
}

