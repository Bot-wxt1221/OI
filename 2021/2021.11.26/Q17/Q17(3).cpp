//�� n ����������n-1���п�Ů
//�� n ����Ů����n-1ֻ��Ů
//ʱ�临�Ӷ� O(n) 
#include <iostream>
#include <cstdio>
using namespace std;
long long boy[100],girl[100];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	boy[1]=girl[1]=1;//boy��i������ iλ�÷����������� ��girlͬ�� 
	for(int i=2;i<=n;i++){
		boy[i]=boy[i-1]+girl[i-1];
		girl[i]=boy[i-1];
	}
	cout<<boy[n]+girl[n];
	return 0;
}
