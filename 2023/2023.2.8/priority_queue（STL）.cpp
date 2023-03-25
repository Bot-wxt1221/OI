#include <cstdio>
#include <string>
#include <queue>
using namespace std;

int main() {
	freopen("priority_queue.in", "r", stdin);
	freopen("priority_queue.out", "w", stdout);
	char com[10];
	priority_queue <int> PQ;
	int key;
	while(1) {
		scanf("%s", com);
		if(com[0] == 'i') {
			scanf("%d", &key);
			PQ.push(key);
		} else if(com[1] == 'x') {
			printf("%d\n", PQ.top());
			PQ.pop();
		} else if(com[0] == 'e') {
			break;
		}
	}
	
	return 0;
}

/*
Sample Input 1
insert 8
insert 2
extract
insert 10
extract
insert 11
extract
extract
end

Sample Output 1
8
10
11
2
*/
