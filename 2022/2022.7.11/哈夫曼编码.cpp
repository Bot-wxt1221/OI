#define MAXBIT 10                 //定义哈夫曼编码的最大长度

typedef struct {
	int bit[MAXBIT];
	int start;
}HCodeType;

void HaffmanCode ( )
{ //生成哈夫曼编码
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXLEAF],cd; 
	int i,j, c,p;
	HuffmanTree (HuffNode );        //建立哈夫曼树
	for (i=0;i<n;i++)                //求每个叶子结点的哈夫曼编码
	{ 
		cd.start=n-1;   c=i;
	 	p=HuffNode[c].parent;
	 	while(p!=0)                 //由叶结点向上直到树根
	    { 
			if (HuffNode[p].lchild==c) cd.bit[cd.start]=0;
	     	else  cd.bit[cd.start]=1;
	    	cd.start--;    c=p;
	     	p=HuffNode[c].parent;
	    }
		for (j=cd.start+1;j<n;j++)       //保存求出的每个叶结点的哈夫曼编码和编码的起始位
	   		HuffCode[i].bit[j]=cd.bit[j];
		HuffCode[i].start=cd.start;
	}
	for (i=0;i<n;i++)                //输出每个叶子结点的哈夫曼编码
	{ 
		for (j=HuffCode[i].start+1;j<n;j++)
	    	printf("%ld",HuffCode[i].bit[j]);
	 	printf("\n");
	}
}

