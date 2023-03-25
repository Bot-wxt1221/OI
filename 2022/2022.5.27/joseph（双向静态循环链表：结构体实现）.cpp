#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 105;
struct node{ //˫������
	int id; //�ڵ���
	//int data; //���б�Ҫ������һ�������������
	int preid; //ǰһ���ڵ�
	int nextid; //��һ���ڵ�
}nodes[maxn];

int main(){
	freopen("joseph.in", "r", stdin);
	freopen("joseph.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	nodes[0].nextid = 1;
	for(int i = 1; i <= n; i++){ //��������
		nodes[i].id = i;
		nodes[i].preid = i-1; //ǰ�ڵ�
		nodes[i].nextid = i+1; //��ڵ�
	}
	nodes[n].nextid = 1; //ѭ������βָ��ͷ
	nodes[1].preid = n; //ѭ������ͷָ��β
	int now = 1; //�ӵ� 1 ����ʼ
	while((n--) >1){
		for(int i = 1; i < m; i++) //���� m��ͣ��
		now = nodes[now].nextid;
		printf("%d ", nodes[now].id); //��ӡ��������ո�
		int prev = nodes[now].preid;
		int next = nodes[now].nextid;
		nodes[prev].nextid = nodes[now].nextid; //ɾ�� now
		nodes[next].preid = nodes[now].preid;
		now = next; //�µĿ�ʼ
	}
	printf("%d", nodes[now].nextid); //��ӡ���һ�������治���ո�return 0;
}

/*
����:
10 3

���:
3 6 9 2 7 1 8 5 10 4
*/
