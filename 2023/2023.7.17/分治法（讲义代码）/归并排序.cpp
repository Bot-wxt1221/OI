#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int A[MAXN], n, cnt = 0;
int L[MAXN / 2 + 5], R[MAXN / 2 + 5];

void merge(int A[], int left, int mid, int right) {	
	int n1 = mid - left;
	int n2 = right - mid;	
	for(int i = 0; i < n1; i++) L[i] = A[left + i];
	for(int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = R[n2] = 2000000000;
	int i = 0, j = 0;
	for(int k = left; k < right; k++) {
		cnt++;
		if(L[i] <= R[j]) A[k] = L[i++];
		else A[k] = R[j++];
	}
}

void merge_sort(int A[], int left, int right) {
	if(left + 1 < right) {
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main() {
//	freopen("merge_sort.in", "r", stdin);
//	freopen("merge_sort.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	merge_sort(A, 0, n);
	for(int i = 0; i < n; i++) {
		if(i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;
	
	return 0;
}

/*
Sample Input 1
10
8 5 9 2 6 3 7 1 10 4

Sample Output 1
1 2 3 4 5 6 7 8 9 10
34
*/
