#include <iostream>
#include <cstdio>
using namespace std;
int abso(int n){//�β� 
	if(n<0){
		return -n;
	}
	return n;
} 
int main(){//���ú��� 
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin>>n;
	cout<<abso(n);//��������     ʵ��     һһ��Ӧ��������ͬ������ƥ�䣨��ͬ����ݣ��� 
	return 0;
}

