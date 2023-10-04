#include <cstdio>
#include <queue>
using namespace std;

struct node1 {
	int x, y;
	bool operator <(const node1 &a) const {
		return x < a.x;  //定义越小的数优先级越低，即越大的数优先级越高 
	}
};

struct node2 {
	int x, y;
	bool operator <(const node2 &a) const {
		return x > a.x;  //定义越大的数优先级越低, 即越小的数优先级越高 
	}
};
 
priority_queue<node1> pq1;  
priority_queue<node2> pq2;

int main() {
	node1 t1; 
	for(int i = 1; i <= 10; i++) {
		t1.x = t1.y = i;		
		pq1.push(t1); 
	}	
	while(!pq1.empty()) {
		printf("%d ", pq1.top());
		pq1.pop();
	}
	
	printf("\n");
	
	node2 t2; 
	for(int i = 1; i <= 10; i++) {
		t2.x = t2.y = i;		
		pq2.push(t2); 
	}
	while(!pq2.empty()) {
		printf("%d ", pq2.top());
		pq2.pop();
	}
	
	return 0;
}
