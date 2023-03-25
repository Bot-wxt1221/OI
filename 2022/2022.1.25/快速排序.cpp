
#include <iostream>
using namespace std;
void swap(int & a,int & b){ //交换变量a,b值
	int tmp = a;
	a = b;
	b = tmp;
}
void QuickSort(int a[],int s,int e){
if( s >= e) return;
	int k = a[s];
	int i = s, j = e;
	while( i != j ) {
		while( j > i && a[j] >= k )	--j;
		swap(a[i],a[j]);
		while( i < j && a[i] <= k )	++i;
		swap(a[i],a[j]);
    } //处理完后，a[i] = k
	QuickSort(a, s, i-1);
	QuickSort(a, i+1, e);
}
int a[] = { 93,27,30,2,8,12,2,8,30,89};
int main(){
	int size = sizeof(a)/sizeof(int);
	QuickSort(a, 0, size - 1);
	for(int i = 0;i < size; ++i)
	cout << a[i] << " ";
	return 0;
}
	
	
