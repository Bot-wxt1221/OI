//单链表(带头结点) 
#include <bits/stdc++.h>
using namespace std;

struct Lnode  { //定义单链表节点 
	int data;
	Lnode *next;   //指向下一个节点的指针 
};

typedef Lnode *LinkList;  //LinkList为指向结构体 LNode 的指针类型 

void CreateList_H(LinkList &L) {  //前插法创建单链表 L 	
	L = new Lnode;  //生成新结点作为头结点，用头指针 L 指向头结点
	L->next = NULL;  //头结点的指针域置空 
	
	int n; Lnode *s;
	cout << "请输入单链表节点的数量："; 
	cin >> n;  
	cout << "请输入每个节点的数据："	;
	while(n--){  //输入n个节点 
		s = new Lnode;
		cin >> s->data;
		s->next = L->next;
		L->next = s;  //将新节点插入到头结点之后 
	} 
}

void CreateList_R(LinkList &L) {  //后插法创建单链表 L 
	L = new Lnode;
	L->next = NULL;
	
	int n; Lnode *s, *r = L;  //r是尾指针，初始时指向头结点;
	cout << "请输入单链表的数量：";
	cin >> n;
	cout << "请输入每个节点的数据：";
	while(n--) {
		s = new Lnode;
		cin >> s->data;	
		s->next = NULL;	
		r->next = s;
		r = s;		
	}
} 

bool InsertList(LinkList &L, int i, int x) {  //插入 
	int j = 0;
	LinkList p = L;
	while(p && j < i-1) { //查找第 i-1 个节点 
		j++;
		p = p->next;
	}
	
	if(!p || j > i-1) return false;  //当 i＞n+1或者i＜1，插入位置不合理
	
	Lnode *s = new Lnode;
	s->data = x;
	s->next = p->next;
	p->next = s;
	return true; 
}

bool DeleteList(LinkList &L, int i) {  //删除 
	LinkList p = L;
	int j = 0;
	while(p->next && j < i-1 ) { 
		p = p->next;
		j++;
	}
	if(!p->next || j > i-1) return false;  //当i>n或i<1时，删除位置不合理
	
	Lnode *q = p->next;
	p->next = q->next;
	delete q;  //释放被删除的节点空间
	return true; 
}

void PrintList(LinkList &L) {  //打印单链表
	LinkList p = L->next;
	while(p) {
		cout << p->data << " ";
		p = p->next;
	} 
	cout << "\n";	
} 

int main() {
	LinkList L;
		
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
 

