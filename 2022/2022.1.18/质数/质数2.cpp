#include <iostream>
#include <cstdio>
#define MAXN 1000000
using namespace std;
bool temp[MAXN+5];//0Ϊ������1Ϊ���� 
int main(){
	freopen(".out","w",stdout);
	for(int i=2;i*i<=MAXN;i++){//i�ı��� 
		if(temp[i]){
			continue;
		}
		int a=i+i;
		for(;a<=MAXN;){//���ٱ�     *******������ȥ�� 1��������ȥ���ͷ��� 
			temp[a]=1;
			a+=i;
		}
	}
	for(int i=2;i<=MAXN;i++){
		if(!temp[i]){
			cout<<i<<' ';
		}
	}
	return 0;
}

