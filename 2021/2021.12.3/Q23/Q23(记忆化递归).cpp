/*
���ʣ��Ӳ��Ϊ 0�����޷�������Ϸ����ֻҪ���� 1 öӲ�ң���Ϸ
���ܼ��������ĳ�غϻ�ʤ����Ӳ������ 1 ö���������� 1 ö��
������У�����˼·�򵥷ǳ���Ҫ��

����ֻ��Ҫ�ж� "��Ϸ�Ƿ���е������Ҫ��Ļغ�"�Լ� "�Ƿ�
�Ѿ����Ӳ��"��

���仯�ݹ���Լӿ��ٶȣ�ÿ������ֻ����һ�Σ����ݹ��������
�п���ϵͳջ����� 

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long int memo[100][200]; 
long long int game(int coin, int depth);

int main(){
	memset(memo, 0, sizeof(memo));
	cout << game(10, 24);	
	return 0;
} 

long long int game(int coin, int depth){
	if(memo[coin][depth]) return memo[coin][depth];
	if(coin == 0) return 0LL;
	if(depth == 0) return 1LL;
	long long int win = game(coin + 1, depth - 1);  //��ʤʱ
	long long int lose = game(coin - 1, depth - 1); //���ʱ
	memo[coin][depth] = win + lose; 
	return memo[coin][depth];
} 





