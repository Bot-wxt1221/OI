/*
���õĲ��߰������ֱ��� 2���� 3������Щ�����Ҫ��һ����˳
��ʹ�á���Ȼ����ĳ�����߰�ʱ���������õĲ��λ�ã���ô���� 
���Ҳ�Ĳ�ڿ�ʼ��˳��ʹ�á�
һ�����߰�һ��������һ�����߰�Ĳ���У��Ӵ˾������������
�߰����ˡ�������ǿ���ʹ�������������������Ҫ����ǿ��Կ�
�� n ����ڵĲ��߷�����
ĳ�����߰�Ĳ���ϲ����������߰�ʱ��ֻ��Ҫ����Щ���߰�Ĳ�
�ڸ�����˾Ϳ����ˡ�
���仯�ݹ飬���Լӿ������ٶȡ� 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 45
using namespace std;
int N;
long long int memo[SIZE]; 
long long int set_tap(int remain);
 
int main(){
	//freopen("tap.in", "r", stdin);
	//freopen("tap.out", "w", stdout);
	cin >> N;
	memset(memo, 0, sizeof(memo));
	memo[1] = 1LL;
	cout << set_tap(N);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

long long int set_tap(int remain){
	if(memo[remain]) return memo[remain];  //���Ѽ������ֱ�ӷ��� 
	long long int cnt = 0LL;
	// 2 �����
	for(int i = 1; i <= remain / 2; i++){
		if(remain - i == i){
			cnt += set_tap(i) * (set_tap(i) + 1) / 2;
		}			
		else{
			cnt += set_tap(remain - i) * set_tap(i);
		}		
	} 
	// 3 �����
	for(int i = 1; i <= remain / 3; i++){
		for(int j = i; j <= (remain - i) / 2; j++){
			if(remain - (i + j) == i && (i == j)){
				cnt += set_tap(i) * (set_tap(i) + 1) * (set_tap(i) + 2) / 6;				
			}
			else if(remain - (i + j) == i){
				cnt += set_tap(i) * (set_tap(i) + 1) * set_tap(j) / 2;
			}
			else if(i == j){
				cnt += set_tap(remain - (i + j)) * set_tap(i) * (set_tap(i) + 1) / 2;				
			}
			else if(remain - (i + j) == j){
				cnt += set_tap(j) * (set_tap(j) + 1) * set_tap(i) / 2;
			}
			else{
				cnt += set_tap(remain - (i + j)) * set_tap(j) * set_tap(i);
			}
		}
	} 
	memo[remain] = cnt; 
	return cnt;
}















