#include <iostream>
#include <cstdio>
#include <vector> 
using namespace std;
vector <int> a;
int main(){
	cout<<2<<" ";//������֪ 2������ 
	a.push_back(2);
	for(int i=3;i<=100;i+=2){// ���� 2���û����ż�������� 
		bool y=1;
		for(int j=0;j<a.size()&&a[j]*a[j]<=i;j++){//��һ�����ܱ� a��������һ���ܱ� a���������������� 
			if(i%a[j]==0){
				y=0;
			}
		}
		if(y){
			a.push_back(i);
			cout<<i<<' ';
		}
	}
	return 0;
}

