#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
 
priority_queue<int> pq;  

int main() {
	for(int i = 1; i <= 10; i++) {
		int x; cin >> x;
		pq.push(x);
	}
	while(!pq.empty()) {
		printf("%d ", pq.top());
		pq.pop();
	}
	return 0;
}
