#include <bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	Node *left, *right, *parent;
};

Node *root, *NIL;

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

void tree_insert(int x) {
	Node *p = root, *t = NIL, *q;
	
	q = new Node;
	q->key = x; q->left = NIL; q->right = NIL;
	
	while(p != NIL) {
		t = p;
		if(x < p->key) p = p->left;
		else p = p->right;
	}
	q->parent = t;
	if(t == NIL) root = q;
	else if(x < t->key) t->left = q;
	else t->right = q;
}

Node * tree_find(int x) {
	Node *u = root;
	while(u != NIL && x != u->key) {	
		if(x < u->key) u = u->left;
		else u = u->right;
	}
	return u;
}

Node * treeMinimum(Node *u) {  //找二叉搜索树的最小值 
	while(u->left != NIL) u = u->left;
	return u;
}

Node * treeSuccessor(Node *u) { //查找 u 的后一个节点
	if(u->right != NIL) return treeMinimum(u->right);  
	/*
	Node *p = u->parent;
	while(p != NIL && u == p->right) {  //查找第一个"以左子结点身份出现的父结点 "
		u = p;
		p = p->parent;
	}
	return p;
	*/
} 

void tree_delete(Node *u) {
	Node *q;  //要删除的对象
	Node *q_son; //q的子结点
	
	//确定要删除的结点
	if(u->left == NIL || u->right == NIL) q = u;
	else q = treeSuccessor(u);
	
	//确定q的子结点 q_son
	if(q->left != NIL) q_son = q->left;
	else q_son = q->right;
	
	if(q_son != NIL) q_son->parent = q->parent;
	
	if(q->parent == NIL) root = q_son;
	else if(q == q->parent->left) q->parent->left = q_son;  
	else q->parent->right = q_son;
	
	if(q != u) u->key = q->key;
	
	free(q);  
} 


int main() {
	freopen("delete_bst.in", "r", stdin);
	freopen("delete_bst.out", "w", stdout);
	int n, x;
	char com[30];
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> com;
		if(com[0] == 'f') {
			cin >> x;
			Node *t = tree_find(x);
			if(t != NIL) cout << "yes\n";
			else cout << "no\n";			
		} else if(com[0] == 'i') {
			cin >> x;
			tree_insert(x);
		} else if(com[0] == 'p') {
			inorder(root); cout << endl;
			preorder(root); cout << endl;
		} else if(com[0] == 'd') {
			cin >> x;
			tree_delete(tree_find(x));
		}
	}
		
	return 0;
}

/*
Sample Input 1
18
insert 8
insert 2
insert 3
insert 7
insert 22
insert 1
find 1
find 2
find 3
find 4
find 5
find 6
find 7
find 8
print
delete 3
delete 7
print

Sample Output 1
yes
yes
yes
no
no
no
yes
yes
 1 2 3 7 8 22
 8 2 1 3 7 22
 1 2 8 22
 8 2 1 22
*/



