#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 105; //���徲̬����Ŀռ��С
struct node{ //��������
	int id;
	//int data; //���б�Ҫ������һ�������������
	int nextid;
} nodes[maxn]; 

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++) {
		nodes[i].id = i;
		nodes[i].nextid = i + 1;
	}
	nodes[n].nextid = 1; //ѭ������βָ��ͷ
	int now = 1, prev = 1; //�ӵ� 1 ����ʼ
	while((n--)> 1) {
		for(int i = 1; i < m; i++) { //���� m��ͣ��
			prev = now;
			now = nodes[now].nextid;
		}
		printf("%d ", nodes[now].id); //���ո�
		nodes[prev].nextid = nodes[now].nextid; //�����ڵ� now����ɾ��now
		now = nodes[prev].nextid; //�µ� now
	}
	printf("%d", nodes[now].nextid); //��ӡ���һ�������治���ո�
	return 0;
}

/*
����:
10 3

���:
3 6 9 2 7 1 8 5 10 4
*/
