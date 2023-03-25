#include <cstdio>
#include <iostream>
using namespace std;
struct node {
	int data;
	node *next;
}; 

int main() {
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	node *head, *p, *now, *prev; //�������
	head = new node; head->data = 1; head->next = NULL; //�����һ���ڵ㣬������Ϊ 1
	now = head; //��ǰָ����ͷ
	for(int i = 2; i <= n; i++) {
		p = new node;  p->data = i; p->next = NULL;  //p ���½ڵ�
		now->next = p;   //��������½ڵ�����ǰ���������
		now = p; //βָ�����һ��
	}
	now->next = head; //βָ��ָ��ͷ��ѭ�����������	
	
	now = head, prev = head; //�ӵ� 1 ����ʼ��
	while((n--) > 1) {
		for(int i = 1; i < m; i++) {   //���� m��ͣ��
			prev = now;    //��¼��һ��λ�ã��������������� m ���ڵ�
			now = now->next;
		}
		printf("%d ", now->data); //����� m �ڵ㣬���ո�
		prev->next = now->next; //��������ڵ�
		delete now; //�ͷŽڵ�
		now = prev->next;  //�µ�һ��
	}
	printf("%d", now->data); //��ӡ���һ�������治���ո�
	delete now; //�ͷ����һ���ڵ�
	return 0;
}

/*
����:
10 3

���:
3 6 9 2 7 1 8 5 10 4
*/
