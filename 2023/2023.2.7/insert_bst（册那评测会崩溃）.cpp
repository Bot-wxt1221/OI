#include <bits/stdc++.h>
using namespace std;

struct Node { //定义二叉搜索树的结点 
	int key;
	Node *right, *left, *parent;
};

Node *root, *NIL;  //定义树根、空指针 

void insert(int x) {
	Node *t = NIL, *p = root, *q;
	
	q = new Node;
	q->key = x; q->left = NIL;	q->right = NIL;
	
	while(p != NIL) { //从树根查找插入 x 的适合位置  
		t = p;
		if(q->key < p->key) p = p->left;
		else p = p->right; 
	}
	
	q->parent = t;
	if(t == NIL) root = q;  //空树，则插入的结点就是树根		
	else if(q->key < t->key) t->left = q;
	else t->right = q;	
}

void inorder(Node *u) {
	if(u == NIL) return;
	inorder(u->left);
	cout << " " << u->key;
	inorder(u->right);
} 

void preorder(Node *u) {
	if(u == NIL) return;
	cout << " " << u->key;
	preorder(u->left);
	preorder(u->right);
}

int main() {
	freopen("insert_bst.in", "r", stdin);
  	freopen("insert_bst.out", "w", stdout);
  	int m, x;
	string com;	
	
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> com;
		if(com == "insert") {		
			cin >> x;
			insert(x); //将 x 插入以 root 为根的二叉搜索树 
		} else if(com == "print") {			
			inorder(root); cout << endl;
			preorder(root); cout << endl; 
		}
	}
	
	return 0;
}

/*
Sample Input 1
8
insert 30
insert 88
insert 12
insert 1
insert 20
insert 17
insert 25
print

Sample Output 1
 1 12 17 20 25 30 88
 30 12 1 20 17 25 88

*/
