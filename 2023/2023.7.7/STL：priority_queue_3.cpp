#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
 
priority_queue<int, vector<int>, less<int> > pq1;  //����ԽС���������ȼ�Խ�͵Ķ��� 
priority_queue<int, vector<int>, greater<int> > pq2;  //����Խ����������ȼ�Խ�͵Ķ��� 


int main() {
	for(int i = 1; i <= 10; i++) {
		pq1.push(i); pq2.push(i);
	}	
	while(!pq1.empty()) {
		printf("%d ", pq1.top());
		pq1.pop();
	}
	
	printf("\n");
	
	
	while(!pq2.empty()) {
		printf("%d ", pq2.top());
		pq2.pop();
	}
	
	return 0;
}
