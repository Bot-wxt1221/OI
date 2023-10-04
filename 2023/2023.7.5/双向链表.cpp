//双向链表(带头结点) 
#include <bits/stdc++.h>
using namespace std;

struct DLnode  { //定义单链表节点 
	int data;
	DLnode *prior, *next;   //指向直接前驱和直接后继的指针 
};

typedef DLnode *DLinkList;  //DLinkList为指向结构体 DLNode 的指针类型 

void CreateList_H(DLinkList &L) {  //前插法创建单链表 L 	
	L = new DLnode;  //生成新结点作为头结点，用头指针 L 指向头结点
	L->prior = L->next = NULL;  //头结点的指针域置空 
	
	int n; DLnode *s;
	cout << "请输入单链表节点的数量："; 
	cin >> n;  
	cout << "请输入每个节点的数据："	;
	while(n--){  //输入n个节点 
		s = new DLnode;
		cin >> s->data;
		s->next = L->next;
		L->next = s;  //将新节点插入到头结点之后 
		s->prior = L; 
	} 
}

void CreateList_R(DLinkList &L) {  //后插法创建单链表 L 
	L = new DLnode;
	L->prior = L->next = NULL;
	
	int n; DLnode *s, *r = L;  //r是尾指针，初始时指向头结点;
	cout << "请输入单链表的数量：";
	cin >> n;
	cout << "请输入每个节点的数据：";
	while(n--) {
		s = new DLnode;
		cin >> s->data;	
		s->next = NULL;	
		s->prior = r;
		r->next = s;
		r = s;			
	}
} 

bool InsertList(DLinkList &L, int i, int x) {  //插入 
	int j = 0;
	DLinkList p = L;
	while(p && j < i) { //查找第 i 个节点 
		j++;
		p = p->next;
	}
	
	if(!p || j > i) return false;  //当 i＞n+1或者i＜1，插入位置不合理
	
	DLnode *s = new DLnode;
	s->data = x;
	p->prior->next = s;
	s->prior = p->prior;
	s->next = p;
	p->prior = s; 
	return true; 
}

bool DeleteList(DLinkList &L, int i) {  //删除 
	DLinkList p = L;
	int j = 0;
	while(p && j < i ) { //查找第 i 个节点 
		p = p->next;
		j++;
	}
	if(!p || j > i) return false;  //当i>n或i<1时，删除位置不合理
	
	if(p->next) p->next->prior = p->prior;
	p->prior->next = p->next;
	delete p;  //释放被删除的节点空间 
	
	return true; 
}

void PrintList(DLinkList &L) {  //打印单链表
	DLinkList p = L->next;
	while(p) {
		cout << p->data << " ";
		p = p->next;
	} 
	cout << "\n";	
} 

int main() {
	DLinkList L;
		
	//前插法创建单链表 L
	CreateList_H(L);
	PrintList(L);
	
	//后插法创建单链表 L
	CreateList_R(L);
	PrintList(L);	
	
	//在单链表第 i 个节点前插入数据 x
	cout << "请输入要插入的数据及位置："; 
	int x, i; cin >> x >> i;
	InsertList(L, i, x);
	PrintList(L); 
	
	
	//删除单链表第 i 个位置上的数据
	cout << "请输入要删除的数据位置："; 
	cin >> i;
	DeleteList(L, i);
	PrintList(L);  
	
	return 0;
}
 

