#include<iostream>
using namespace std;
#define ENDFLAG -1
typedef int ElemType;

typedef struct BSTNode{
	ElemType data;	//���������
	BSTNode *lchild,*rchild;	//���Һ���ָ��
}BSTNode,*BSTree;

BSTree SearchBST(BSTree T,ElemType key)//�����������ĵݹ����
{
    //�����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
    if((!T)|| key==T->data)
        return T;
    else if (key<T->data)
            return SearchBST(T->lchild,key);//���������м�������
        else
            return SearchBST(T->rchild,key); //���������м�������
}

void InsertBST(BSTree &T,ElemType e)//�����������Ĳ���
{
    //������������T�в����ڹؼ��ֵ���e������Ԫ��ʱ��������Ԫ��
    if(!T)
    {
        BSTree S=new BSTNode; //�����½��
        S->data=e;             //�½��S����������Ϊe
        S->lchild=S->rchild=NULL;//�½��S��ΪҶ�ӽ��
        T=S;            		//���½��S���ӵ����ҵ��Ĳ���λ��
    }
    else if(e<T->data)
            InsertBST(T->lchild,e );//����������
        else if(e>T->data)
            InsertBST(T->rchild,e);//����������
}

void CreateBST(BSTree &T )//�����������Ĵ���
{
    //���ζ���һ���ؼ���Ϊkey�Ľ�㣬���˽��������������T��
    T=NULL;
    ElemType e;
    cin>>e;
    while(e!=ENDFLAG)//ENDFLAGΪ�Զ��峣������Ϊ���������־
    {
        InsertBST(T,e);  //�������������T��
        cin>>e;
    }
}

void DeleteBST(BSTree &T,char key)
{
  //�Ӷ���������T��ɾ���ؼ��ֵ���key�Ľ��
    BSTree p=T;BSTree f=NULL;
    BSTree q;
    BSTree s;
    if(!T) return; //��Ϊ���򷵻�
    while(p)//����
    {
        if(p->data==key) break;  //�ҵ��ؼ��ֵ���key�Ľ��p������ѭ��
        f=p;                //fΪp��˫��
        if (p->data>key)
            p=p->lchild; //��p���������м�������
        else
            p=p->rchild; //��p���������м�������
    }
    if(!p) return; //�Ҳ�����ɾ����򷵻�
    //���������p�������������ա�������������������
    if((p->lchild)&&(p->rchild))//��ɾ���p��������������
    {
        q=p;
        s=p->lchild;
        while(s->rchild)//��p���������м���������ǰ����㣬�������½��
        {
            q=s;
            s=s->rchild;
        }
        p->data=s->data;  //s��ֵ��ֵ����ɾ���p,Ȼ��ɾ��s���
        if(q!=p)
            q->rchild=s->lchild; //�ؽ�q��������
        else
            q->lchild=s->lchild; //�ؽ�q��������
        delete s;
    }
    else
    {
        if(!p->rchild)//��ɾ���p����������ֻ���ؽ���������
        {
            q=p;
            p=p->lchild;
        }
        else if(!p->lchild)//��ɾ���p����������ֻ���ؽ���������
        {
             q=p;
             p=p->rchild;
        }
        /*�D�D�D�D�D�D�D�D�D�D��p��ָ�������ҽӵ���˫�׽��f��Ӧ��λ�èD�D�D�D�D�D�D�D*/
        if(!f)
            T=p;  //��ɾ���Ϊ�����
        else if(q==f->lchild)
                f->lchild=p; //�ҽӵ�f��������λ��
            else
                f->rchild=p;//�ҽӵ�f��������λ��
        delete q;
	}
}

void InOrderTraverse(BSTree &T)//�������
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
	cout<<"������һЩ��������-1����"<<endl;
	CreateBST(T);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
	cout<<endl;
	ElemType key;//�����һ��ɾ������
	cout<<"����������ҹؼ���"<<endl;
	cin>>key;
	BSTree result=SearchBST(T,key);
	if(result)
        cout<<"�ҵ�"<<key<<endl;
	else
        cout<<"δ�ҵ�"<<key<<endl;
	cout<<"�������ɾ���ؼ���"<<endl;
	cin>>key;
	DeleteBST(T,key);
	cout<<"��ǰ�������������������Ϊ"<<endl;
	InOrderTraverse(T);
	return 0;
}

