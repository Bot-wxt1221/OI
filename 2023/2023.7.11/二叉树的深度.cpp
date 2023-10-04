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

int Depth(Btree T)//������������
{
    int m,n;
    if(T==NULL)//���Ϊ���������Ϊ0
        return 0;
    else
    {
       m=Depth(T->lchild);//�ݹ�������������
       n=Depth(T->rchild);//�ݹ�������������
       if(m>n)
          return m+1;//���������������ֵ��1
       else
          return n+1;
    }
}

int main()
{
    Btree mytree;
    cout<<"�������������������н���ֵ������Ϊ��ʱ����#��������һ�ö�����"<<endl;
    //ABD##E##CF#G###
    Createtree(mytree);//����������
    cout<<endl;
    cout<<"�����������Ϊ��"<<Depth(mytree)<<endl;
    return 0;
}
