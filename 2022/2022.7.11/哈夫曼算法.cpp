#define MAXVALUE 10000       //定义最大权值
#define MAXLEAF 30           //定义哈夫曼树中叶子结点个数
#define MAXNODE  MAXLEAF*2-1  //具有n个叶子结点的哈夫曼树共有2n－1个结点 

typedef struct {
        int weight;
        int parent;
        int lchild;
        int rchild;
}HNodeType;

void  HaffmanTree(HNodeType HuffNode [ ])
{	//哈夫曼树的构造算法
	int i,j,m1,m2,x1,x2,n;
	scanf("%d",&n);            //输入叶子结点个数
	for (i=0;i<2*n-1;i++)         //数组HuffNode[ ]初始化
	{ 
		HuffNode[i].weight=0;
	  	HuffNode[i].parent=-1;
	  	HuffNode[i].lchild=-1;
	  	HuffNode[i].rchild=-1;
	}
	for (i=0;i<n;i++) scanf("%d",&HuffNode[i].weight);  //输入n个叶子结点的权值
	for (i=0;i<n-1;i++)            //构造哈夫曼树
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
	 	//将找出的两棵子树合并为一棵子树
	 	HuffNode[x1].parent=n+i;         HuffNode[x2].parent=n+i; 
		HuffNode[n+i].weight= HuffNode[x1].weight+HuffNode[x2].weight;
	 	HuffNode[n+i].lchild=x1;  HuffNode[n+i].rchild=x2;     
	}
}

