//�� n ����������n-1���п�Ů
//�� n ����Ů����n-1ֻ��Ů
//ʱ�临�Ӷ� O(n) 
#include <iostream>
#include <cstdio>
using namespace std;
unsigned long long b1,b2,g1,g2; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	b1=g1=1;//boy��i������ iλ�÷����������� ��girlͬ�� 
	for(int i=2;i<=n;i++){
		b2=b1+g1;
		g2=b1;
		b1=b2,g1=g2;
	}
	cout<<b1+g1;
	return 0;
}
