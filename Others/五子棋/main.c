#include "main.h"
#include <stdlib.h>






void heqi()
{
	system("CLS");
	printf("*******************************************************************************\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*                     Tie                                                     *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*******************************************************************************\n");
	
}
/****************��Ϸ����*******************/
void over()
{
	system("CLS");
	printf("*******************************************************************************\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*                     Game Over                                               *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*******************************************************************************\n");
	
}
/****************��Ϸ��ʼ*******************/
void welcome()
{
	system("CLS");
    printf("*******************************************************************************\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*                     Welcome                                                 *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
	printf("*                                                                             *\n");
    printf("*******************************************************************************\n");
	printf("press any key ,then start!");
	getchar();
	//system("CLS");
}
void DrawPanel()
{
	//	char f[N]={' ','1','2','3','4','5','6','7','8','9','0','1','2','3','4','5','6','7','8','9'};
	int count=1;
    int i,j;
	system("CLS");
	//����б�־����ʾ�ڼ���
    for(i=0;i<=N;i++)
    {
		if(i==0)
		{
			printf("  ");
		}else
		{
			printf("%4d",count);
			count++;
			// printf("  ");
		}
        
    }
	printf("\n");
	//����count����Ϊ1
	count=1;
	//���ÿһ��
	for(i=0;i<N;i++)
	{
		for(j=-1;j<N;j++)
		{
			if(j==-1)
			{
				//����ǵ�һ�У�������ַ�
				printf("%2d",count);
				count++;
			}
			else
			{
				//�������"."
				if(pieces[i][j]==0)
				{
					//	printf("  ��");
					printf("  ��");
				}else if(pieces[i][j]==1)//ΪA��
				{
					printf("  ��");
				}else if(pieces[i][j]==2)
				{
					printf("  ��");
				}
			}
		}
		printf("\n");
	}
}
/******************������*****************/
int zouqihang()
{
    int x;
	if(flag==1)
	{
		printf("���A��");
	}else
	{
		printf("���B��");
	}
    printf("������Ҫ��������������!\n");
    printf("x=");
    scanf("%d",&x);
    while(x>N-1||x<1)
    {
        printf("error!\n");
		
		if(flag==1)
		{
			printf("���A��");
		}else
		{
			printf("���B��");
		}
        printf("������Ҫ��������������!\n");
        printf("x=");
        scanf("%d",&x);
    }
	return x;
}
/******************������*****************/
int zouqilie()
{
    int y;
    if(flag==1)
	{
		printf("���A��");
	}else
	{
		printf("���B��");
	}
    printf("������Ҫ��������������!\n");
    printf("y=");
    scanf("%d",&y);
    while(y>N-1||y<1)
    {
        printf("error!\n");
		if(flag==1)
		{
			printf("���A��");
		}else
		{
			printf("���B��");
		}
        printf("������Ҫ��������������!\n");
        printf("y=");
        scanf("%d",&y);
    }
	return y;
}
//����1����ʾAӮ������2��ʾBӮ���������
int check(int x,int y)
{
	//�����
	int count=1;
	int i=x,j=y;
	//������
	j++;
	while(j<N&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
			count++;
		}else
		{
			break;
		}
		j++;
	}
	j=y-1;
	//������
	while(j>=0&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		j--;

	}
	if(count==5)
	{
	   return pieces[x][y];
	}

     //�����
	i=x;
	j=y;
	count=1;
	//������
	i=i+1;
	while(i<N&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i++;
	}
	//������
	i=x-1;
	while(i>=0&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i--;
	}
	if(count==5)
	{
	   return pieces[x][y];
	}

	//��б��
	i=x;
	j=y;
	count=1;
	//��б����
	i=i-1;
	j=j-1;
	while(i>=0&&j>=0&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i--;
		j--;
	}
	//��б����
	i=x+1;
	j=y+1;
	while(i<N&&j<N&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i++;
		j++;
	}
	if(count==5)
	{
	   return pieces[x][y];
	}


	//��б����
	i=x;
	j=y;
	count=1;
	//��б������
	i=i-1;
	j=j+1;
	while(i>=0&&j<N&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i--;
		j++;
	}
	//��б������
	i=x+1;
	j=y-1;
	while(i>=0&&j<N&&count<5)
	{
		if(pieces[i][j]==pieces[x][y])
		{
		   count++;
		}else
		{
			break;
		}
		i++;
		j--;
	}
	if(count==5)
	{
	   return pieces[x][y];
	}

	return 0;
}

/******************������*****************/
void main()
{
	int x,y;
	int winner;
	int countpieces=0;//����������
	//��ӭ����
    welcome();
	//������
	DrawPanel();	
	while(countpieces<N*N)
	{
		x=zouqihang();
		y=zouqilie();
		x=x-1;
		y=y-1;
		if(pieces[x][y]==0)
		{
			pieces[x][y]=flag;
			countpieces++;
			//��������
			if(flag==1)
			{
				
				flag=2;
				
			}else
			{
				flag=1;
			}
			winner=check(x,y);
			if(winner==1)
			{
				//AӮ��
				printf("��ϲA��Ӯ��!\n");
				break;
			}else if(winner==2)
			{
				//BӮ��
				printf("��ϲB��Ӯ��!\n");
				break;
			}
		}else{
			printf("ERROR!\n");
			printf("�������д��������ⰴ����������!\n");
			getchar();	
			getchar();
		}
		DrawPanel();
	}
	if(countpieces==N*N)
	{
		heqi();
	}else
	{
		over();
	}
}








/******************��ʾ����*****************/
void showqi(int p)
{
    int i,j,k,m;
    int a[N*N],b[N*N];
    FILE *fp;
    fp=fopen("wuzi_list","rb");
    for(i=1;i<=N*N;i++)
    {
        fread(&weizhi[i],sizeof(struct zuobiao),1,fp);
        a[i]=weizhi[i].x[i];
        b[i]=weizhi[i].y[i];
    }
    for(m=1;m<p;m++)
    {
        while(weizhi[p].x[p]==a[m]&&weizhi[p].y[p]==b[m])
        {
            printf("error!\n");
            weizhi[p].x[p]=zouqihang();
            weizhi[p].y[p]=zouqilie();
            m=1;
        }
    }
    for(i=0;i<N;i++)
    {
        printf("%d",i);
        printf(" ");
    }
	printf("\n");
	for(i=1;i<N;i++)
	{
		for(j=1;j<N;j++)
		{
			if(j==1)
                printf("%2d",i);
			for(k=1;k<=p;k++)
			{
				if(i==weizhi[k].x[k]&&j==weizhi[k].y[k])
				{
					if(k%2==1)
					{
						printf("��");
						break;
					}
					else if(k%2==0)
					{
						printf("��");
						break;
					}
				}
				
			}
            if(k>p)
				printf("��");
            else 
				continue;
		}
		printf("\n");
	}
}

/******************�ļ�����*****************/
void save(int i)
{
    FILE *fp;
	static int m=0;
    fp=fopen("wuzi_list","wb");
    fwrite(&weizhi[i],sizeof(struct zuobiao),1,fp);
}
/****************�ж���Ӯ*******************/
void panduan(int p)
{
    int i,j,k[8]={1,1,1,1,1,1,1,1,};
    int a[N*N],b[N*N];
    FILE *fp;
    fp=fopen("wuzi_list","rb");
    for(i=1;i<=p;i++)
    {
        fread(&weizhi[i],sizeof(struct zuobiao),1,fp);
        a[i]=weizhi[i].x[i];
        b[i]=weizhi[i].y[i];
    }
	/*****************�ж���******************/
    for(i=1;i<=p;i++)
    {
        if(i%2==1)
        {
            for(j=1;j<=p;j=j+2)
            {
                if((a[i]==a[j])&&(b[i]==b[j]-1))
                {
                    k[0]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-2))
                {
                    k[0]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-3))
                {
                    k[0]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-4))
                {
                    k[0]++;
                    continue;
                }
                else if(k[0]==5)
                {
                    printf("Player 1 wins!!!\n");
                }
                else
                    continue;
			}
            if(k[0]==5)
                break;
            k[0]=1;
        }
        else if(k[0]==5)
            break;
        else if(i%2==0)
        {
            for(j=2;j<=p;j=j+2)
            {
                if((a[i]==a[j])&&(b[i]==b[j]-1))
                {
                    k[1]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-2))
                {
                    k[1]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-3))
                {
                    k[1]++;
                    continue;
                }
                else if((a[i]==a[j])&&(b[i]==b[j]-4))
                {
                    k[1]++;
                    continue;
                }
                else if(k[1]==5)
                {
                    printf("Player 2 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[1]==5)
                break;
            k[1]=1;
        }
    }
	/**********************�ж���************************/
    for(i=1;i<=p;i++)
    {
        if(k[0]==5||k[1]==5)
            break;
        else if(i%2==1)
        {
            for(j=1;j<=p;j=j+2)
            {
                if((a[i]==a[j]-1)&&(b[i]==b[j]))
                {
                    k[2]++;
                    continue;
                }
                else if((a[i]==a[j]-2)&&(b[i]==b[j]))
                {
                    k[2]++;
                    continue;
                }
                else if((a[i]==a[j]-3)&&(b[i]==b[j]))
                {
                    k[2]++;
                    continue;
                }
                else if((a[i]==a[j]-4)&&(b[i]==b[j]))
                {
                    k[2]++;
                    continue;
                }
                else if(k[2]==5)
                {
                    printf("Player 1 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[2]==5)
                break;
            k[2]=1;
        }
        else if(k[2]==5)
            break;
        else if(i%2==0)
        {
            for(j=2;j<=p;j=j+2)
            {
                if((a[i]==a[j]-1)&&(b[i]==b[j]))
                {
                    k[3]++;
                    continue;
                }
                else if((a[i]==a[j]-2)&&(b[i]==b[j]))
                {
                    k[3]++;
                    continue;
                }
                else if((a[i]==a[j]-3)&&(b[i]==b[j]))
                {
                    k[3]++;
                    continue;
                }
                else if((a[i]==a[j]-4)&&(b[i]==b[j]))
                {
                    k[3]++;
                    continue;
                }
                else if(k[3]==5)
                {
                    printf("Player 2 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[3]==5)
                break;
            k[3]=1;
        }
    }
	/****************�ж϶Խǣ�����-���£�******************/
    for(i=1;i<=p;i++)
    {
        if(k[0]==5||k[1]==5||k[2]==5||k[3]==5)
            break;
        else if(i%2==1)
        {
            for(j=1;j<=p;j=j+2)
            {
                if((a[i]==a[j]-1)&&(b[i]==b[j]-1))
                {
                    k[4]++;
                    continue;
                }
                else if((a[i]==a[j]-2)&&(b[i]==b[j]-2))
                {
                    k[4]++;
                    continue;
                }
                else if((a[i]==a[j]-3)&&(b[i]==b[j]-3))
                {
                    k[4]++;
                    continue;
                }
                else if((a[i]==a[j]-4)&&(b[i]==b[j]-4))
                {
                    k[4]++; 
                    continue;
                }
                else if(k[4]==5)
                {
                    printf("Player 1 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[4]==5)
                break;
            k[4]=1;
        }
        else if(k[2]==5)
            break;
        else if(i%2==0)
        {
            for(j=2;j<=p;j=j+2)
            {
                if((a[i]==a[j]-1)&&(b[i]==b[j]-1))
                {
                    k[5]++;
                    continue;
                }
                else if((a[i]==a[j]-2)&&(b[i]==b[j]-2))
                {
                    k[5]++;
                    continue;
                }
                else if((a[i]==a[j]-3)&&(b[i]==b[j]-3))
                {
                    k[5]++;
                    continue;
                }
                else if((a[i]==a[j]-4)&&(b[i]==b[j]-4))
                {
                    k[5]++;
                    continue;
                }
                else if(k[5]==5)
                {
                    printf("Player 2 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[5]==5)
                break;
            k[5]=1;
        }
    }
	/**********�ж϶Խǣ�����-���ϣ�************/
    for(i=1;i<=p;i++)
    {
        if(k[0]==5||k[1]==5||k[2]==5||k[3]==5||k[4]==5||k[5]==5)
            break;
        else if(i%2==1)
        {
            for(j=1;j<=p;j=j+2)
            {
                if((a[i]==a[j]+1)&&(b[i]==b[j]-1))
                {
                    k[6]++;
                    continue;
                }
                else if((a[i]==a[j]+2)&&(b[i]==b[j]-2))
                {
                    k[6]++;
                    continue;
                }
                else if((a[i]==a[j]+3)&&(b[i]==b[j]-3))
                {
                    k[6]++;
                    continue;
                }
                else if((a[i]==a[j]+4)&&(b[i]==b[j]-4))
                {
                    k[6]++; 
                    continue;
                }
                else if(k[6]==5)
                {
                    printf("Player 1 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[6]==5)
                break;
            k[6]=1;
        }
        else if(k[6]==5)
            break;
        else if(i%2==0)
        {
            for(j=2;j<=p;j=j+2)
            {
                if((a[i]==a[j]+1)&&(b[i]==b[j]-1))
                {
                    k[7]++;
                    continue;
                }
                else if((a[i]==a[j]+2)&&(b[i]==b[j]-2))
                {
                    k[7]++;
                    continue;
                }
                else if((a[i]==a[j]+3)&&(b[i]==b[j]-3))
                {
                    k[7]++;
                    continue;
                }
                else if((a[i]==a[j]+4)&&(b[i]==b[j]-4))
                {
                    k[7]++;
                    continue;
                }
                else if(k[7]==5)
                {
                    printf("Player 2 wins!!!\n");
                }
                else
                    continue;
            }
            if(k[7]==5)
                break;
            k[7]=1;
        }
    }
}

