/*
�������ؼ����������֤ƽ������Ϊ��֤��������֮���Ƿ���ƽ
������ֻҪԤ��׼����ƽ��������Լ��ˡ���Ϊ���������ֱ��ϵĲ�
ݮ�������Ҳ���ᳬ�� N �� 2 �������Կ������ȼ���á�
׼ȷ��˵�����������ֱ��ϵĲ�ݮ����֮�����Ӧ����N+(N - 1)= 2N-1����
�зֺ���ֱ���Χ��Բ�εģ����ȹ̶��ʼ��һ���ֱ���������
����ֱ��ϵĲ�ݮ����Ϊ 1����Ϊ�����з�������ͨ����ת�ֱ��õ���
������������ǰ���ǳ����ġ�
Ȼ��˳ʱ�������õĲ�ݮ��������֤ÿ�η��õĲ�ݮ����������
������ֱ�����һ���ϵ����ֺ������ 1 ���Ҳ�õ�ƽ������
*/ 
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX 105
using namespace std;
bool used[MAX];
int ans[MAX];
bool square[2 * MAX];
bool check(int n, int cur, int step);


int main(){
	//��ʼ�� 
	memset(used, false, sizeof(used));
	memset(square, false, sizeof(square));
	memset(ans, 0, sizeof(ans));
	//�����ƽ���������ֵΪ n �� 2 ����
	for(int i = 1; i <= floor(sqrt(2 * MAX)); i++){
		square[i * i] = true;		
	}		
	//��С����ö�� 
	int n = 2;	
	while(true){
		used[1] = true; 
		if(check(n, 1, 1))	break; //�ҵ� 1 �ֽⷨ�ͽ���	 	
		n += 1;			
	} 
	
	cout << n << endl;
	for(int i = 1; i <= n; i++)
		cout << ans[i] << " ";	
	
	return 0;
}

bool check(int n, int cur, int step){
	ans[step] = cur;
	if(step == n){ //ȫ�����ý���
		if(square[1 + cur]){  //1 �����һ����֮��Ϊƽ����ʱ
			ans[step] = cur;
			return true; 
		}
	}	
	for(int i = 1; i <= n; i++){
		//����û�б�ʹ�õ�����
		if(!used[i]){		
			if(square[i + cur]){ //�����ǰһ����֮��Ϊƽ����
				used[i] = true;				
				if(check(n, i, step + 1)) return true;	
				used[i] = false;				
			}				
		}
	}
	ans[step] = 0;
	return false;	                          
}
