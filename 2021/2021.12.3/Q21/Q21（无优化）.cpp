/*
����ֻ��Ҫ���� "һ������������Ϊ 1���м���������һ������
�� "�����Ĺ��򣬾Ϳ���������˹�������Ρ�ÿһ�е����ֶ���һά��
���ʾ���м������Ԫ��ͨ���������ó��������Ϳ��Բ��ϼ������
һ�е����֡�

һֱ�ظ����㣬ֱ�����ֵ� 2014 �� 0
*/


#include <iostream>
#include <cstdio>
using namespace std;
int cur_row[2000] = {1}; //��ǰ�е�ֵ
int next_row[2000] = {1}; //��һ�е�ֵ

int main(){
	int count = 0;  // 0 ���ֵĴ���
	int line = 1;  // ��ǰ�е�����

	while(count < 2014){
		/*
		for(int i = 0; i < line; i++){	
			cout << cur_row[i] << " ";
		}
		cout << endl;
		*/
		next_row[0] = 1;
		int t = 1;
		//ͨ��������һ�е����ֵ�õ���һ��
		for(int i = 0 ; i < line - 1 && count < 2014; i++){
			next_row[t] = cur_row[i] ^ cur_row[i+1];
			if(next_row[t] == 0) count++;			
			t += 1;
		}		
		next_row[t] = 1;	
		for(int i = 0; i <= t; i++){
			cur_row[i] = next_row[i];
		}
		line += 1;  //����������������һ�д���		
	}
	cout << line << endl;
	//cout << count;

	return 0;
}
