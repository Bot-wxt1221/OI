#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

struct cmp{  //��λ����Խ�����ȼ���Խ�� 
	bool operator() (const int &a, const int &b) {
		return a % 10 > b % 10;   
	}
};
 
priority_queue<int, vector<int>, cmp > pq;  //pq---��λ����Խ������������ȼ�Խ�͵Ķ��� 

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
