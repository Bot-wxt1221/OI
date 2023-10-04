#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000005;
const int INF = 1 << 30;

int H, A[MAXN];

void max_heap(int i) {
	int L, R, largest;
	L = 2 * i;
	R = 2 * i + 1;
	
	if(L <= H && A[L] > A[i]) largest = L;
	else largest = i;
	if(R <= H && A[R] > A[largest]) largest = R;
	
	if(largest != i) {
		swap(A[i], A[largest]);
		max_heap(largest);
	}
}

int extract() {
	int maxv;
	if(H < 1) return -INF;
	maxv = A[1];
	A[1] = A[H--];
	max_heap(1);
	return maxv;
}

void increaseKey(int i, int key) {
	if(key < A[i]) return;
	A[i] = key;
	while(i > 1 && A[i / 2] < A[i]) {
		swap(A[i], A[i / 2]);
		i = i / 2;
	}
}

void insert(int key) {
	H++;
	A[H] = -INF;
	increaseKey(H, key);
}

int main() {
	freopen("priority_queue.in", "r", stdin);
	freopen("priority_queue.out", "w", stdout);
	char com[10];
	int key;
	while(1) {
		scanf("%s", com);
		if(com[0] == 'e' && com[1] == 'n') break;
		if(com[0] == 'i') {
			scanf("%d", &key);
			insert(key);
		} else {
			printf("%d\n", extract());
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
