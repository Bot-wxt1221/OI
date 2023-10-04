#include <iostream>
using namespace std;

typedef struct Bnode	/*定义二叉树存储结构*/
{ char data;
  struct Bnode *lchild,*rchild;
}Bnode,*Btree;

void Createtree(Btree &T)	/*创建二叉树函数*/
{
    //按先序次序输入二叉树中结点的值（一个字符），创建二叉链表表示的二叉树T
	char ch;
	cin >> ch;
	if(ch=='#')
        T=NULL;			//递归结束，建空树
	else{
		T=new Bnode;
		T->data=ch;					//生成根结点
		Createtree(T->lchild);	//递归创建左子树
		Createtree(T->rchild);	//递归创建右子树
	}
}

int LeafCount(Btree T)//求二叉树的叶子数
{
    if(T==NULL)//如果为空树，深度为0
        return 0;
    else
        if(T->lchild==NULL&&T->rchild==NULL)//左右子树均为空，则叶子数为1
           return 1;
        else
           return LeafCount(T->lchild)+LeafCount(T->rchild);//递归计算左子树和右子树的叶子数之和
}

int NodeCount(Btree T)//求二叉树的结点数
{
    if(T==NULL)//如果为空树，深度为0
        return 0;
    else
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;//递归计算左子树和右子树的结点数之和加1
}

int main()
{
    Btree mytree;
    cout<<"按先序次序输入二叉树中结点的值（孩子为空时输入#），创建一棵二叉树"<<endl;
    //ABD##E##CF#G###
    Createtree(mytree);//创建二叉树
    cout<<endl;
    cout<<"二叉树的结点数为："<<NodeCount(mytree)<<endl;
    cout<<"二叉树的叶子数为："<<LeafCount(mytree)<<endl;
    return 0;
}
