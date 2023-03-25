#define MAXVALUE 10000       //�������Ȩֵ
#define MAXLEAF 30           //�������������Ҷ�ӽ�����
#define MAXNODE  MAXLEAF*2-1  //����n��Ҷ�ӽ��Ĺ�����������2n��1����� 

typedef struct {
        int weight;
        int parent;
        int lchild;
        int rchild;
}HNodeType;

void  HaffmanTree(HNodeType HuffNode [ ])
{	//���������Ĺ����㷨
	int i,j,m1,m2,x1,x2,n;
	scanf("%d",&n);            //����Ҷ�ӽ�����
	for (i=0;i<2*n-1;i++)         //����HuffNode[ ]��ʼ��
	{ 
		HuffNode[i].weight=0;
	  	HuffNode[i].parent=-1;
	  	HuffNode[i].lchild=-1;
	  	HuffNode[i].rchild=-1;
	}
	for (i=0;i<n;i++) scanf("%d",&HuffNode[i].weight);  //����n��Ҷ�ӽ���Ȩֵ
	for (i=0;i<n-1;i++)            //�����������
	{ 
		m1=m2=MAXVALUE;
	  	x1=x2=0;
	  	for (j=0;j<n+i;j++)
	  	{ 
		  	if (HuffNode[j].weight<m1 && HuffNode[j].parent==-1)
	      	{ 
			  	m2=m1;     x2=x1;
	        	m1=HuffNode[j].weight;    x1=j;
	      	}
	     	else if (HuffNode[j].weight<m2 && HuffNode[j].parent==-1)
	        { 
				m2=HuffNode[j].weight;
	            x2=j;
	        }
	   	}
	 	//���ҳ������������ϲ�Ϊһ������
	 	HuffNode[x1].parent=n+i;         HuffNode[x2].parent=n+i; 
		HuffNode[n+i].weight= HuffNode[x1].weight+HuffNode[x2].weight;
	 	HuffNode[n+i].lchild=x1;  HuffNode[n+i].rchild=x2;     
	}
}

