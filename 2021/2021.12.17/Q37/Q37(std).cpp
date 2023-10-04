/*
�ٸ����ӣ�������ʾ������ʾ˳��Ϊ 0123456789 ʱ����Ҫ�л� 28 �Ρ�
0�� 1: 4�Σ��л�A��D��E��F��
1�� 2: 5�Σ��л�A��C��D��E��G��
2�� 3: 2�Σ��л�C�� E��
3�� 4: 3�Σ��л�A��D��F��
4�� 5: 3�Σ��л�A��B��D��
5�� 6: 1�Σ��л�E��
6�� 7: 5�Σ��л�B��D��E��F��G��
7�� 8: 4�Σ��л�D��E��F��G��
8�� 9: 1�Σ��л�E��
ֻ��Ҫ�� 0~9 �� 10 �����ֵ�����˳��ȫ������һ�¾Ϳ����ˡ���
��������Ҫ���� 10!��10 �Ľ׳ˣ��Σ��������������Խ����ˡ�

�л�������Ϊֻ�����ƺ��������״̬���ö���������ʾ�Ϳ����ˡ�
0��1���л���λ������Ը���ʵ�֣�������������㴦�������Ƚϼ򵥡�
*/

#include <iostream>
#include <cstdio>
using namespace std;

unsigned char flip[10][10], bit[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B}; // �����ʾ 0 �� 9 �ı������� 
unsigned char bitcount(unsigned char x); // ͳ�Ʊ��������� 1 �ĸ���
int MIN = 63;
bool is_used[10]; //�������Ƿ���ʹ��
int a[11];  //��¼���巽�� 
void Search(unsigned char sum, int prev, int step);  //ÿ�����÷�ת�������к��ֵΪ��ʼֵ 

int main(){
	//���ȵó����������
	for(int i = 0;i < 10; i++){
		for(int j = 0; j < 10; j++){
			flip[i][j] = bitcount(bit[i]^bit[j]);
		}
	}
	memset(is_used, false, sizeof(is_used));
	Search(0, 0, 1);
	cout << MIN;
	
	return 0;
}

unsigned char bitcount(unsigned char x){
	x = (x & 0x55555555) + (x >> 1 & 0x55555555);
 	x = (x & 0x33333333) + (x >> 2 & 0x33333333);
 	x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
 	x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
 	x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);
 	return x;
}

void Search(unsigned char sum, int prev, int step){ 
//sum:  ��ʹ�����ֵķ�ת����,  prev : ��һ��ʹ�õ�����, step: ��ǰ���� 
	if(step == 11){
		MIN = sum;
		for(int i = 1; i <= 10; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	} 
	else{
		for(int i = 0; i < 10; i++){
			if(!is_used[i]){
				is_used[i] = true; a[step] = i;
				unsigned char next_sum = 0;
				if(prev >= 0) next_sum = sum + flip[prev][i];
				if(MIN > next_sum) Search(next_sum, i, step + 1);
				is_used[i] = false;
			}
		}
	}
}
