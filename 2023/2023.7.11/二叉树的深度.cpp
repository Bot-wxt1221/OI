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

int Depth(Btree T)//求二叉树的深度
{
    int m,n;
    if(T==NULL)//如果为空树，深度为0
        return 0;
    else
    {
       m=Depth(T->lchild);//递归计算左子树深度
       n=Depth(T->rchild);//递归计算左子树深度
       if(m>n)
          return m+1;//返回左右子树最大值加1
       else
          return n+1;
    }
}

int main()
{
    Btree mytree;
    cout<<"按先序次序输入二叉树中结点的值（孩子为空时输入#），创建一棵二叉树"<<endl;
    //ABD##E##CF#G###
    Createtree(mytree);//创建二叉树
    cout<<endl;
    cout<<"二叉树的深度为："<<Depth(mytree)<<endl;
    return 0;
}
