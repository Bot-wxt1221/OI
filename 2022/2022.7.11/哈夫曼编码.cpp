#define MAXBIT 10                 //����������������󳤶�

typedef struct {
	int bit[MAXBIT];
	int start;
}HCodeType;

void HaffmanCode ( )
{ //���ɹ���������
	HNodeType HuffNode[MAXNODE];
	HCodeType HuffCode[MAXLEAF],cd; 
	int i,j, c,p;
	HuffmanTree (HuffNode );        //������������
	for (i=0;i<n;i++)                //��ÿ��Ҷ�ӽ��Ĺ���������
	{ 
		cd.start=n-1;   c=i;
	 	p=HuffNode[c].parent;
	 	while(p!=0)                 //��Ҷ�������ֱ������
	    { 
			if (HuffNode[p].lchild==c) cd.bit[cd.start]=0;
	     	else  cd.bit[cd.start]=1;
	    	cd.start--;    c=p;
	     	p=HuffNode[c].parent;
	    }
		for (j=cd.start+1;j<n;j++)       //���������ÿ��Ҷ���Ĺ���������ͱ������ʼλ
	   		HuffCode[i].bit[j]=cd.bit[j];
		HuffCode[i].start=cd.start;
	}
	for (i=0;i<n;i++)                //���ÿ��Ҷ�ӽ��Ĺ���������
	{ 
		for (j=HuffCode[i].start+1;j<n;j++)
	    	printf("%ld",HuffCode[i].bit[j]);
	 	printf("\n");
	}
}

