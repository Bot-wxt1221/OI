#include <cstdio>

#define LL long long

#define H_IO

using namespace std;

int mT, T;
int line[5];//初始状态 
int click[5];//方案 

void work();

int main()
{
	int i, j, d;
	
	#ifdef H_IO
	freopen("lamp.in", "r", stdin);
	freopen("lamp.out", "w", stdout);
	#endif
	
	scanf("%d", &T);
	for (mT=1; mT<=T; mT++)//依题目要求，mT统计组数 
	{
		for (i=0; i<5; i++)
		{
			line[i] = 0;//要有初始化 
			for (j=0; j<6; j++)
			{
				scanf("%d", &d);
				line[i] |= d << j;
				//将读入的数组反向存储为二进制形式 
			}
		}
		
		work();//得出结果 
		
		printf("PUZZLE #%d\n", mT);
		for (i=0; i<5; i++)
		{
			for (j=0; j<6; j++)
			{
				printf("%d ", (click[i] & (1 << j)) != 0);
				//其实是(click[i] >> j) & 1 
			}
			printf("\n");
		}//输出 
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
	int rem;//标记上一行还亮着的灯的位置 
	
	//0x0000003f，二进制下为111111
	//0~111111的二进制形式包含了所有可能的按法 
	for (click[0] = 0; click[0] <= 0x0000003f; click[0]++)
	{
		rem = 0;
		
		for (i=1; i<5; i++)
		{
			rem ^= line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1);//1 
			
			click[i] = rem & 0x0000003f;//防范左移越界 
			rem = click[i - 1];//2 
		}
//1和2统一起来，即为rem = click[i - 2] ^ line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1); 
		
		i = 5;
		rem ^= line[i - 1] ^ click[i - 1] ^ (click[i - 1] << 1) ^ (click[i - 1] >> 1);
		//统计最后一还还亮着的灯 
		if ((rem & 0x0000003f) == 0)
		{
			//所有灯熄灭，该方案成立 
			return;
		}
	}
	
	return;
}
