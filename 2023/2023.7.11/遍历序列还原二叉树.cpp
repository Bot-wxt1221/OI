#include <iostream>
using namespace std;
typedef struct node {
	char data;
	struct node *lchild, *rchild;
} BiTNode, *BiTree;

BiTree pre_mid_createBiTree(char *pre, char *mid, int len) { //前序中序还原建立二叉树
	if(len==0)	return NULL;
	char ch = pre[0];  //找到先序中的第一个结点
	int index = 0;
	while(mid[index] != ch) { //在中序中找到的根结点的左边为该结点的左子树，右边为右子树
		index++;
	}
	BiTree T = new BiTNode;//创建根结点
	T->data = ch;
	T->lchild = pre_mid_createBiTree(pre+1, mid, index);//建立左子树
	T->rchild = pre_mid_createBiTree(pre+index+1, mid+index+1, len-index-1);//建立右子树
	return T;
}

BiTree pro_mid_createBiTree(char *last, char *mid, int len) { //后序中序还原建立二叉树
	if(len == 0)	return NULL;
	char ch = last[len-1]; //取得后序遍历顺序中最后一个结点
	int index = 0;//在中序序列中找根结点，并用index记录长度
	while(mid[index] != ch)//在中序中找到根结点，左边为该结点的左子树，右边为右子树
		index++;
	BiTree T = new BiTNode;//创建根结点
	T->data = ch;
	T->lchild = pro_mid_createBiTree(last, mid, index);//建立左子树
	T->rchild = pro_mid_createBiTree(last+index, mid+index+1, len-index-1);//建立右子树
	return T;
}

void pre_order(BiTree T) { //前序递归遍历二叉树
	if(T) {
		cout << T->data;
		pre_order(T->lchild);
		pre_order(T->rchild);
	}
}

void pro_order(BiTree T) { //后序递归遍历二叉树
	if(T) {
		pro_order(T->lchild);
		pro_order(T->rchild);
		cout << T->data;
	}
}
int main() {
	BiTree T;
	int n;
	char pre[100], mid[100], last[100];
	cout << "1. 前序中序还原二叉树\n";
	cout << "2. 后序中序还原二叉树\n";
	cout << "0. 退出\n";
	int choose = -1;
	while(choose != 0) {
		cout << "请选择:";
		cin >> choose;

		switch (choose) {
			case 1://前序中序还原二叉树
				cout << "请输入结点的个数:" << endl;
				cin >> n;
				cout << "请输入前序序列:" << endl;
				for(int i = 0; i < n; i++)	cin >> pre[i];
				cout << "请输入中序序列:" << endl;
				for(int i = 0; i < n; i++)	cin >> mid[i];
				T = pre_mid_createBiTree(pre, mid, n);
				cout << endl;
				cout << "二叉树还原成功，输出其后序序列:" << endl;
				pro_order(T);
				cout << endl << endl;
				break;
			case 2: //后序中序还原二叉树
				cout << "请输入结点的个数:" << endl;
				cin >> n;
				cout << "请输入后序序列:" << endl;
				for(int i = 0; i < n; i++)  cin >> last[i];
				cout << "请输入中序序列:" << endl;
				for(int i = 0; i < n; i++)  cin>>mid[i];
				T = pro_mid_createBiTree(last, mid, n);
				cout << endl;
				cout << "二叉树还原成功，输出其先序序列:" << endl;
				pre_order(T);
				cout << endl << endl;
				break;
		}
	}
	return 0;
}
