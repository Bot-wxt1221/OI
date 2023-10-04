#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for(int j = p; j < r; j++) {
		if(A[j] <= x) {
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quick_sort(int A[], int p, int r) {
	int q;
	if(p < r) {
		q = partition(A, p, r);
		quick_sort(A, p, q - 1);
		quick_sort(A, q + 1, r);
	}
}
 
int main() {	
	int n; 
	int A[MAXN];
	
	cin >> n;	
	for(int i = 0; i < n; i++)	cin >> A[i];		
	quick_sort(A, 0, n - 1);	
	for(int i = 0; i < n; i++) 	cout << A[i] << " ";
		
	return 0;
}

