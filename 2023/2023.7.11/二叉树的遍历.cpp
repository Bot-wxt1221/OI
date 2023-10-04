#include <iostream>
#include <queue>//�������ͷ�ļ�
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

void preorder(Btree T)//�������
{
    if(T)
    {
       cout<<T->data<<"  ";
       preorder(T->lchild);
       preorder(T->rchild);
    }
}

void inorder(Btree T)//�������
{
    if(T)
    {
       inorder(T->lchild);
       cout<<T->data<<"  ";
       inorder(T->rchild);
    }
}

void posorder(Btree T)//�������
{
    if(T)
    {
       posorder(T->lchild);
       posorder(T->rchild);
       cout<<T->data<<"  ";
    }
}

bool Leveltraverse(Btree T)
{
    Btree p;
    if(!T)
        return false;
    queue<Btree>Q; //����һ����ͨ����(�Ƚ��ȳ�)��������ָ������
    Q.push(T); //��ָ�����
    while(!Q.empty()) //������в���
    {
        p=Q.front();//ȡ����ͷԪ����Ϊ��ǰ��չ���livenode
        Q.pop(); //��ͷԪ�س���
        cout<<p->data<<"  ";
        if(p->lchild)
            Q.push(p->lchild); //����ָ�����
        if(p->rchild)
            Q.push(p->rchild); //�Һ���ָ�����
    }
    return true;
}

int main()
{
    Btree mytree;
    cout<<"�������������������н���ֵ������Ϊ��ʱ����#��������һ�ö�����"<<endl;
    Createtree(mytree);//����������
    cout<<endl;
    cout<<"��������������������"<<endl;
    preorder(mytree);//�������������
    cout<<endl;
    cout<<"��������������������"<<endl;
    inorder(mytree);//�������������
    cout<<endl;
    cout<<"�������ĺ�����������"<<endl;
    posorder(mytree);//�������������
    cout<<endl;
    cout<<"�������Ĳ�α��������"<<endl;
    Leveltraverse(mytree);//��α���������
    return 0;
}
