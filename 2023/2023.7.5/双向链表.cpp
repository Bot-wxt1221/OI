//˫������(��ͷ���) 
#include <bits/stdc++.h>
using namespace std;

struct DLnode  { //���嵥����ڵ� 
	int data;
	DLnode *prior, *next;   //ָ��ֱ��ǰ����ֱ�Ӻ�̵�ָ�� 
};

typedef DLnode *DLinkList;  //DLinkListΪָ��ṹ�� DLNode ��ָ������ 

void CreateList_H(DLinkList &L) {  //ǰ�巨���������� L 	
	L = new DLnode;  //�����½����Ϊͷ��㣬��ͷָ�� L ָ��ͷ���
	L->prior = L->next = NULL;  //ͷ����ָ�����ÿ� 
	
	int n; DLnode *s;
	cout << "�����뵥����ڵ��������"; 
	cin >> n;  
	cout << "������ÿ���ڵ�����ݣ�"	;
	while(n--){  //����n���ڵ� 
		s = new DLnode;
		cin >> s->data;
		s->next = L->next;
		L->next = s;  //���½ڵ���뵽ͷ���֮�� 
		s->prior = L; 
	} 
}

void CreateList_R(DLinkList &L) {  //��巨���������� L 
	L = new DLnode;
	L->prior = L->next = NULL;
	
	int n; DLnode *s, *r = L;  //r��βָ�룬��ʼʱָ��ͷ���;
	cout << "�����뵥�����������";
	cin >> n;
	cout << "������ÿ���ڵ�����ݣ�";
	while(n--) {
		s = new DLnode;
		cin >> s->data;	
		s->next = NULL;	
		s->prior = r;
		r->next = s;
		r = s;			
	}
} 

bool InsertList(DLinkList &L, int i, int x) {  //���� 
	int j = 0;
	DLinkList p = L;
	while(p && j < i) { //���ҵ� i ���ڵ� 
		j++;
		p = p->next;
	}
	
	if(!p || j > i) return false;  //�� i��n+1����i��1������λ�ò�����
	
	DLnode *s = new DLnode;
	s->data = x;
	p->prior->next = s;
	s->prior = p->prior;
	s->next = p;
	p->prior = s; 
	return true; 
}

bool DeleteList(DLinkList &L, int i) {  //ɾ�� 
	DLinkList p = L;
	int j = 0;
	while(p && j < i ) { //���ҵ� i ���ڵ� 
		p = p->next;
		j++;
	}
	if(!p || j > i) return false;  //��i>n��i<1ʱ��ɾ��λ�ò�����
	
	if(p->next) p->next->prior = p->prior;
	p->prior->next = p->next;
	delete p;  //�ͷű�ɾ���Ľڵ�ռ� 
	
	return true; 
}

void PrintList(DLinkList &L) {  //��ӡ������
	DLinkList p = L->next;
	while(p) {
		cout << p->data << " ";
		p = p->next;
	} 
	cout << "\n";	
} 

int main() {
	DLinkList L;
		
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
 

