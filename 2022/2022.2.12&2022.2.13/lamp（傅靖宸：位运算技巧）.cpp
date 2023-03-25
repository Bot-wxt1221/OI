#include <cstdio>

#define LL long long

#define H_IO

using namespace std;

int mT, T;
int line[5];//��ʼ״̬ 
int click[5];//���� 

void work();

int main()
{
	int i, j, d;
	
	#ifdef H_IO
	freopen("lamp.in", "r", stdin);
	freopen("lamp.out", "w", stdout);
	#endif
	
	scanf("%d", &T);
	for (mT=1; mT<=T; mT++)//����ĿҪ��mTͳ������ 
	{
		for (i=0; i<5; i++)
		{
			line[i] = 0;//Ҫ�г�ʼ�� 
			for (j=0; j<6; j++)
			{
				scanf("%d", &d);
				line[i] |= d << j;
				//����������鷴��洢Ϊ��������ʽ 
			}
		}
		
		work();//�ó���� 
		
		printf("PUZZLE #%d\n", mT);
		for (i=0; i<5; i++)
		{
			for (j=0; j<6; j++)
			{
				printf("%d ", (click[i] & (1 << j)) != 0);
				//��ʵ��(click[i] >> j) & 1 
			}
			printf("\n");
		}//��� 
	}
	
	#ifdef H_IO
	fclose(stdin);
	fclose(stdout);
	#endif
	
	return 0;
}

void work()
{
	int i, j;
	int rem;//�����һ�л����ŵĵƵ�λ�� 
	
	//0x0000003f����������Ϊ111111
	//0~111111�Ķ�������ʽ���������п��ܵİ��� 
	for (click[0] = 0; click[0] <= 0x0000003f; click[0]++)
	{
		rem = 0;
		
		for (i=1; i<5; i++)
		{
			rem ^= line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1);//1 
			
			click[i] = rem & 0x0000003f;//��������Խ�� 
			rem = click[i - 1];//2 
		}
//1��2ͳһ��������Ϊrem = click[i - 2] ^ line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1); 
		
		i = 5;
		rem ^= line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1);
		//ͳ�����һ�������ŵĵ� 
		if ((rem & 0x0000003f) == 0)
		{
			//���е�Ϩ�𣬸÷������� 
			return;
		}
	}
	
	return;
}
