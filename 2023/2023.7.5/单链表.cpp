//������(��ͷ���) 
#include <bits/stdc++.h>
using namespace std;

struct Lnode  { //���嵥����ڵ� 
	int data;
	Lnode *next;   //ָ����һ���ڵ��ָ�� 
};

typedef Lnode *LinkList;  //LinkListΪָ��ṹ�� LNode ��ָ������ 

void CreateList_H(LinkList &L) {  //ǰ�巨���������� L 	
	L = new Lnode;  //�����½����Ϊͷ��㣬��ͷָ�� L ָ��ͷ���
	L->next = NULL;  //ͷ����ָ�����ÿ� 
	
	int n; Lnode *s;
	cout << "�����뵥����ڵ��������"; 
	cin >> n;  
	cout << "������ÿ���ڵ�����ݣ�"	;
	while(n--){  //����n���ڵ� 
		s = new Lnode;
		cin >> s->data;
		s->next = L->next;
		L->next = s;  //���½ڵ���뵽ͷ���֮�� 
	} 
}

void CreateList_R(LinkList &L) {  //��巨���������� L 
	L = new Lnode;
	L->next = NULL;
	
	int n; Lnode *s, *r = L;  //r��βָ�룬��ʼʱָ��ͷ���;
	cout << "�����뵥�����������";
	cin >> n;
	cout << "������ÿ���ڵ�����ݣ�";
	while(n--) {
		s = new Lnode;
		cin >> s->data;	
		s->next = NULL;	
		r->next = s;
		r = s;		
	}
} 

bool InsertList(LinkList &L, int i, int x) {  //���� 
	int j = 0;
	LinkList p = L;
	while(p && j < i-1) { //���ҵ� i-1 ���ڵ� 
		j++;
		p = p->next;
	}
	
	if(!p || j > i-1) return false;  //�� i��n+1����i��1������λ�ò�����
	
	Lnode *s = new Lnode;
	s->data = x;
	s->next = p->next;
	p->next = s;
	return true; 
}

bool DeleteList(LinkList &L, int i) {  //ɾ�� 
	LinkList p = L;
	int j = 0;
	while(p->next && j < i-1 ) { 
		p = p->next;
		j++;
	}
	if(!p->next || j > i-1) return false;  //��i>n��i<1ʱ��ɾ��λ�ò�����
	
	Lnode *q = p->next;
	p->next = q->next;
	delete q;  //�ͷű�ɾ���Ľڵ�ռ�
	return true; 
}

void PrintList(LinkList &L) {  //��ӡ������
	LinkList p = L->next;
	while(p) {
		cout << p->data << " ";
		p = p->next;
	} 
	cout << "\n";	
} 

int main() {
	LinkList L;
		
	//ǰ�巨���������� L
	CreateList_H(L);
	PrintList(L);
	
	//��巨���������� L
	CreateList_R(L);
	PrintList(L);	
	
	//�ڵ������ i ���ڵ�ǰ�������� x
	cout << "������Ҫ��������ݼ�λ�ã�"; 
	int x, i; cin >> x >> i;
	InsertList(L, i, x);
	PrintList(L); 
	
	
	//ɾ��������� i ��λ���ϵ�����
	cout << "������Ҫɾ��������λ�ã�"; 
	cin >> i;
	DeleteList(L, i);
	PrintList(L);  
	
	return 0;
}
 

