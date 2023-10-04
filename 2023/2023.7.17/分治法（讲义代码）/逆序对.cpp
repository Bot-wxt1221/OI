#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
//预设一个比序列中任何数都大的值 INF，用于合并时"技巧性"处理两个有序子数组的合并，
//即在数组末尾增加一个值为 INF 的元素，标志素组结束。 
const long long INF = 2000000000LL;  
int L[MAXN / 2 + 5], R[MAXN / 2 + 5]; //存放有序的子数组

long long merge(int A[], int left, int mid, int right) { 
//合并A[left, mid], A[mid, right]， 注意是左闭右开区间的合并 
	long long cnt = 0;
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i = 0; i < n1; i++) L[i] = A[left + i];
	for(int i = 0; i < n2; i++) R[i] = A[mid + i];
	L[n1] = R[n2] = INF;  //在数组末尾增加一个值为 INF（INF > A数组中任何数） 的元素，标志素组结束。
	int i = 0, j = 0;
	for(int k = left; k < right; k++) {
		if(L[i] <= R[j]) A[k] = L[i++];
		else {
			A[k] = R[j++];
			cnt += n1 - i;  // = mid + j - k - 1	
		}		
	} 	
	return cnt;
} 

long long merge_sort(int A[], int left, int right) {
	int mid;
	long long a, b, c;
	if(left + 1 < right) {
		mid = (left + right) / 2;
		a = merge_sort(A, left, mid);
		b = merge_sort(A, mid, right);
		c = merge(A, left, mid, right);
		return a + b + c;
	} else return 0LL;
}

int main() {
	freopen("inversion.in", "r", stdin);
	freopen("inversion.out", "w", stdout);
	int n, A[MAXN];
	cin >> n;
	for(int i = 0; i < n; i++) cin >> A[i];
	
	long long ans = merge_sort(A, 0, n);
	cout << ans << endl;
	
	return 0;
}

/*
Sample Input 1
5
3 5 2 1 4
Sample Output 1
6

Sample Input 2
3
3 1 2
Sample Output 2
2
*/



