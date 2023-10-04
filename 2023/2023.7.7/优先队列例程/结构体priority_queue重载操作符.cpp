//结构体priority_queue重载操作符
#include <bits/stdc++.h>//使用万能头文件，无需写#include <queue> 
using namespace std;

struct Info {
	string name;
	float score;
	bool operator <(const Info &a) const {
		return a.score<score;//按score由小到大排列用"<",否则用">"
	}
} ;

int main() {
	priority_queue<Info> pq;
	Info info;
	info.name="Alice";
	info.score=98;
	pq.push(info);
	info.name="Jone";
	info.score=92;
	pq.push(info);
	info.name="Kate";
	info.score=95.5;
	pq.push(info);
	while(pq.empty()!=true) {
		cout<<pq.top().name<<": "<<pq.top().score<<endl;
		pq.pop();
	}
	return 0;
}

