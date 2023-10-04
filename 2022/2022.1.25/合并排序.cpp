#include <iostream>
using namespace std;
void Merge(int a[],int s,int m, int e,int tmp[]){	
//将数组a的局部a[s,m]和a[m+1,e]合并到tmp,并保证tmp有序，然后再拷贝回a[s,m], 
//归并操作时间复杂度：O（e-m+1),即O（n)
	int pb = 0,	p1 = s, p2 = m+1;
	while( p1 <= m && p2 <= e) {
		if( a[p1] < a[p2])	tmp[pb++] = a[p1++]; else tmp[pb++] = a[p2++];
	}
	while( p1 <= m)	tmp[pb++] = a[p1++];
	while( p2 <= e)	tmp[pb++] = a[p2++];
	for(int i = 0;i < e-s+1; ++i) a[s+i] = tmp[i];
}
void MergeSort(int a[],int s,int e,int tmp[]){
	if( s < e) {
		int m = s + (e-s)/2;
		MergeSort(a, s, m, tmp);
		MergeSort(a, m + 1, e, tmp);
		Merge(a, s, m, e, tmp);
	}
}
int a[10] = { 13,27,19,2,8,12,2,8,30,89};
int b[10];
int main()
{
	int size = sizeof(a)/sizeof(int);
	MergeSort(a, 0, size - 1, b);
	for(int i = 0;i < size; ++i)
	cout << a[i] << " ";
	return 0;
}
