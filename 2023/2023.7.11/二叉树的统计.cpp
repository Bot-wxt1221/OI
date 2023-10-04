#include <iostream>
using namespace std;

typedef struct Bnode	/*����������洢�ṹ*/
{ char data;
  struct Bnode *lchild,*rchild;
}Bnode,*Btree;

void Createtree(Btree &T)	/*��������������*/
{
    //�������������������н���ֵ��һ���ַ������������������ʾ�Ķ�����T
	char ch;
	cin >> ch;
	if(ch=='#')
        T=NULL;			//�ݹ������������
	else{
		T=new Bnode;
		T->data=ch;					//���ɸ����
		Createtree(T->lchild);	//�ݹ鴴��������
		Createtree(T->rchild);	//�ݹ鴴��������
	}
}

int LeafCount(Btree T)//���������Ҷ����
{
    if(T==NULL)//���Ϊ���������Ϊ0
        return 0;
    else
        if(T->lchild==NULL&&T->rchild==NULL)//����������Ϊ�գ���Ҷ����Ϊ1
           return 1;
        else
           return LeafCount(T->lchild)+LeafCount(T->rchild);//�ݹ��������������������Ҷ����֮��
}

int NodeCount(Btree T)//��������Ľ����
{
    if(T==NULL)//���Ϊ���������Ϊ0
        return 0;
    else
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;//�ݹ�������������������Ľ����֮�ͼ�1
}

int main()
{
    Btree mytree;
    cout<<"�������������������н���ֵ������Ϊ��ʱ����#��������һ�ö�����"<<endl;
    //ABD##E##CF#G###
    Createtree(mytree);//����������
    cout<<endl;
    cout<<"�������Ľ����Ϊ��"<<NodeCount(mytree)<<endl;
    cout<<"��������Ҷ����Ϊ��"<<LeafCount(mytree)<<endl;
    return 0;
}
