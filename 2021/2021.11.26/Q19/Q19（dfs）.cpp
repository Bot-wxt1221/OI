/*
1. �� 1~N ��ѡȡ 7 ����������"��ྭ�� 6 �� "����ô���Ե�֪������Ҫ�ҵ��� "�� 2 ������˵õ������� "����ϡ�
�����Ļ����˷������е��� 2 �����ͻ��Ϊ��Լ����

2. �ٸ����ӣ�ѡ�� a~h ��Щ��, ���� 7 �����ֱַ������µ���ʽʱ��������� 6 �����������������������ϵ��
a �� b, b �� c, c �� d, d �� e, e �� f, f �� g, g ��h
������ a~h ��Щ���ֱ��� "����"��

3. ����һ�����ǣ��ѵ� 1 ���������ó� "ƽ���� "����4����Ҳ����˵���������������ϸ���:
����a �� a, a �� b, b �� c, c �� d, d �� e, e �� f, f �� g
ĩβ���ͬ�����ó�ƽ�����ͻ��ø�С��Ҳ���Ǳ���������������:
����a �� a, a �� b, b �� c, c �� d, d �� e, e �� f, f �� f
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int primes[6] = {2, 3, 5, 7, 11, 13}; //�� 6 �������䵱a~f
int min_friends[7];
int MIN = 13 * 13, cnt = 0; //����С���ֳ�ʼ�������������ƽ��
bool book[6];
int a[3];
void dfs(int step, int k); //��˳��� 6 ��������ѡȡ 2 ���������˷�����������ϼ�����Сֵ 

int main(){
	
	memset(book, false, sizeof(book));
	dfs(1, 0);
	
	cout << MIN << endl;	
	for(int i = 0; i < 7; i++)
		cout << min_friends[i] << " ";	
	
	return 0;
}

void dfs(int step, int k){
	if(step == 3){
		int friends[7];		
		int t[7], cnt = 0;
		for(int i = 0; i < 6; i++){
			if(!book[i]) t[cnt++] = primes[i];
		}	
		sort (t, t + 4);
		
		friends[0] = a[1] * a[1]; 		
		friends[6] = a[2] * a[2];
		do{
			friends[1] = a[1] * t[0];
			friends[2] = t[0] * t[1];
			friends[3] = t[1] * t[2];
			friends[4] = t[2] * t[3];	
			friends[5] = t[3] * a[2];	
			/*
			for(int i = 0; i < 7; i++){
				cout << friends[i] << " " ;
			}	
			cout << endl;
			*/
			int MAX = friends[0];
		
			for(int i = 1; i < 7; i++){
				if(MAX < friends[i]) MAX = friends[i];
			}	
			//cout << MAX << endl;	
			
			if(MIN > MAX){		
				MIN = MAX;
				for(int i = 0; i < 7; i++)
					min_friends[i] = friends[i];
			}			
		}while ( next_permutation(t, t + 4) );		
	}
	for(int i = k; i < 6; i++){
		if(!book[i]){
			a[step] = primes[i];
			book[i] = true;
			dfs(step + 1, i + 1);
			book[i] = false;
		}
	}
	return;
}
