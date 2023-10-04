#include <iostream>
#include <algorithm>
using namespace std;
void swap(int & a,int & b){ //交换变量a,b值
	int tmp = a;
	a = b;
	b = tmp;
}
bool cmp(int a,int b){
	return a>b;
}
void QuickSort(int a[],int s,int e,int sk){
if( s >= e) return;
	int k = a[sk];
	int i = s, j = e;
	while( i != j ) {
		while( j > i && a[j] >= k )	--j;
		swap(a[i],a[j]);
		while( i < j && a[i] <= k )	++i;
		swap(a[i],a[j]);
    }
}
int a[100005];
int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	QuickSort(a, 0, n - 1,m-1);
	sort(a+n-m,a+n,cmp);
	for(int i=n-m;i<n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
	
	
