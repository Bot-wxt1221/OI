#include <cstdio>
#include <iostream>
using namespace std;
int nodes[150];

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n-1; i++) //nodes[i]��ֵ������һ���ڵ�
		nodes[i] = i+1;
	nodes[n] = 1;    //ѭ������βָ��ͷ
	int now = 1, prev = 1; //�ӵ� 1 ����ʼ
	while((n--) > 1) {
		for(int i = 1; i < m; i++) { //���� m��ͣ��
			prev = now;
			now = nodes[now]; //��һ��
		}
		printf("%d ", now); //���ո�
		nodes[prev] = nodes[now]; //�����ڵ� now����ɾ��now
		now = nodes[prev]; //�µ� now
	}
	printf("%d", now); //��ӡ���һ���������ո�
	return 0;
}

/*
����:
10 3

���:
3 6 9 2 7 1 8 5 10 4
*/
