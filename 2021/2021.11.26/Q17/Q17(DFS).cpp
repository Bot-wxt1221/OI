/*
���������������з����У���ÿ�����һ�ˣ�����֤Ů����������
���С����ַ�����Լ򵥡���ô���� n������ʱ��������ұ���������
�򡰼�һ����������һ��Ů������������ұ���Ů������ֻ�ܼ�һ��
��������
*/
#include <iostream>
#include <cstdio>
using namespace std;

string boy = "B", girl = "G";
int N;
long long int add(string seq);

int main(){
	cin >> N;
	cout << add(boy) + add(girl);
	return 0;
}

long long int add(string seq){
	if(seq.size() == N){ //���������������ޣ���ֹ�ݹ�
		cout << seq << endl;
		return 1LL;  
	}
	//δ����������ʱ�������������ұ�Ϊ����ʱ��Ů��
	long long int cnt = 0;
	cnt += add(seq + boy);
	if(seq[seq.size() - 1] == 'B') cnt += add(seq + girl); 
	return cnt;
}
