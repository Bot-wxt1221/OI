#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{  //个位数字越大，优先级别越低 
	bool operator() (const int &a, const int &b) {
		return a % 10 > b % 10;   
	}
};
 
priority_queue<int, vector<int>, cmp > pq;  //pq---个位数字越大的整数，优先级越低的队列 

int main() {
	for(int i = 0; i < 10; i++) {
		pq.push(i); 
	}	
	while(!pq.empty()) {
		printf("%d ", pq.top());
		pq.pop();
	}	
	
	return 0;
}
