#include <iostream>
using namespace std;
int sum(const int array[],int n){//array是指针变量 
	for(int i=0;i<=n-1;i++){
		*(array+1) = *array + *(array+1);
		array++;
	}
	return *array;
}
int main(){
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	cout<<sum(a,10);
	return 0;
}
//无法编译 
