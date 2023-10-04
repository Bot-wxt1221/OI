/*
�ӡ���������ͬʱͣ��ͬһ������֪��A ����Ѿ��� B �����ļ���
����ô�����Ϳ��Խ����ˡ�A �� B �ֱ�Ӳ�ͬλ�ó�����ÿ�θ�
��ǰ�����������еݹ�����
*/

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int N;  //¥�ݼ���
int STEPS; //һ�����ǰ������
long long int Move(int a, int b);

int main(){
	cin >> N >> STEPS;	
	double dur;
    clock_t start, end;
    start = clock();
    
   	cout << Move(0, N);
   	
    end = clock();
    dur = (double)(end - start);
    printf("\nUse Time:%f\n",(dur/CLOCKS_PER_SEC));
	
	return 0;
}

long long int Move(int a, int b){	
	if(a > b) return 0LL;
	if(a == b) return 1LL;
	long long int cnt = 0;
	for(int i = 1; i <= STEPS; i++){
		for(int j = 1; j <= STEPS; j++){
			cnt += Move(a + i, b - j);
		}
	}
	return cnt;	
}
