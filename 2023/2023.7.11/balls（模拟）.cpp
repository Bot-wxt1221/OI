//���ѷ��֣�����һ�����k�������ӽ�㡢���ӽ��ı�ŷֱ���2k��2k+1
//ֱ��ģ�⣨��ʱ����I�ߴ���Ըߴ�2^D-1��ÿ��������������ܲ������ܻ�
//�ߴ�219*19=9961472����һ��������10000�����ݡ�

#include <bits/stdc++.h>
using namespace std;
const int maxd = 20;

int s[1<<maxd];   //��������Ϊ 2^maxd-1
                             
int main() {	
	int T, D, I;
	while(scanf("%d", &T) == 1 && T != -1) {
		while(T--) {
			scanf("%d%d", &D, &I); 
			memset(s, 0, sizeof(s));  //����
			int k, n = (1<<D)-1;     //n���������
			for(int i = 0; i < I; i++){  //������I��С������
				k = 1;
				for(;;) {
					s[k] = !s[k];
					k = s[k] ? k*2 : k*2+1; //���ݿ���״̬ѡ�����䷽��
					if(k > n) break;    //�Ѿ��� ������ ����
				}                                              
			}                                                
			printf("%d\n", k/2);   //�����硱֮ǰ��Ҷ�ӱ��		
		}		
	}
	
	return 0;
} 
/*
Sample Input
5
4 2
3 4
10 1
2 2
8 128
-1

Sample Output
12
7
512
3
255
*/
 
