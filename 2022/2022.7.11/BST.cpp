#include<iostream>
using namespace std;
#define ENDFLAG -1
typedef int ElemType;

typedef struct BSTNode{
	ElemType data;	//结点数据域
	BSTNode *lchild,*rchild;	//左右孩子指针
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,ElemType key)//二叉排序树的递归查找
{
    //若查找成功，则返回指向该数据元素结点的指针，否则返回空指针
    if((!T)|| key==T->data)
        return T;
    else if (key<T->data)
            return SearchBST(T->lchild,key);//在左子树中继续查找
        else
            return SearchBST(T->rchild,key); //在右子树中继续查找
}

void InsertBST(BSTree &T,ElemType e)//二叉排序树的插入
{
    //当二叉排序树T中不存在关键字等于e的数据元素时，则插入该元素
    if(!T)
    {
        BSTree S=new BSTNode; //生成新结点
        S->data=e;             //新结点S的数据域置为e
        S->lchild=S->rchild=NULL;//新结点S作为叶子结点
        T=S;            		//把新结点S链接到已找到的插入位置
    }
    else if(e<T->data)
            InsertBST(T->lchild,e );//插入左子树
        else if(e>T->data)
            InsertBST(T->rchild,e);//插入右子树
}

void CreateBST(BSTree &T )//二叉排序树的创建
{
    //依次读入一个关键字为key的结点，将此结点插入二叉排序树T中
    T=NULL;
    ElemType e;
    cin>>e;
    while(e!=ENDFLAG)//ENDFLAG为自定义常量，作为输入结束标志
    {
        InsertBST(T,e);  //插入二叉排序树T中
        cin>>e;
    }
}

void DeleteBST(BSTree &T,char key)
{
  //从二叉排序树T中删除关键字等于key的结点
    BSTree p=T;BSTree f=NULL;
    BSTree q;
    BSTree s;
    if(!T) return; //树为空则返回
    while(p)//查找
    {
        if(p->data==key) break;  //找到关键字等于key的结点p，结束循环
        f=p;                //f为p的双亲
        if (p->data>key)
            p=p->lchild; //在p的左子树中继续查找
        else
            p=p->rchild; //在p的右子树中继续查找
    }
    if(!p) return; //找不到被删结点则返回
    //三种情况：p左右子树均不空、无右子树、无左子树
    if((p->lchild)&&(p->rchild))//被删结点p左右子树均不空
    {
        q=p;
        s=p->lchild;
        while(s->rchild)//在p的左子树中继续查找其前驱结点，即最右下结点
        {
            q=s;
            s=s->rchild;
        }
        p->data=s->data;  //s的值赋值给被删结点p,然后删除s结点
        if(q!=p)
            q->rchild=s->lchild; //重接q的右子树
        else
            q->lchild=s->lchild; //重接q的左子树
        delete s;
    }
    else
    {
        if(!p->rchild)//被删结点p无右子树，只需重接其左子树
        {
            q=p;
            p=p->lchild;
        }
        else if(!p->lchild)//被删结点p无左子树，只需重接其右子树
        {
             q=p;
             p=p->rchild;
        }
        /*――――――――――将p所指的子树挂接到其双亲结点f相应的位置――――――――*/
        if(!f)
            T=p;  //被删结点为根结点
        else if(q==f->lchild)
                f->lchild=p; //挂接到f的左子树位置
            else
                f->rchild=p;//挂接到f的右子树位置
        delete q;
	}
}

void InOrderTraverse(BSTree &T)//中序遍历
{
    if(T)
	{
        InOrderTraverse(T->lchild);
        cout<<T->data<<"\t";
        InOrderTraverse(T->rchild);
	}
}

int main()
{
	BSTree T;
	cout<<"请输入一些整型数，-1结束"<<endl;
	CreateBST(T);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	ElemType key;//待查找或待删除内容
	cout<<"请输入待查找关键字"<<endl;
	cin>>key;
	BSTree result=SearchBST(T,key);
	if(result)
        cout<<"找到"<<key<<endl;
	else
        cout<<"未找到"<<key<<endl;
	cout<<"请输入待删除关键字"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"当前有序二叉树中序遍历结果为"<<endl;
	InOrderTraverse(T);
	return 0;
}

