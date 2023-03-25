/*
举个例子，如下所示，当显示顺序为 0123456789 时，需要切换 28 次。
0→ 1: 4次（切换A、D、E、F）
1→ 2: 5次（切换A、C、D、E、G）
2→ 3: 2次（切换C、 E）
3→ 4: 3次（切换A、D、F）
4→ 5: 3次（切换A、B、D）
5→ 6: 1次（切换E）
6→ 7: 5次（切换B、D、E、F、G）
7→ 8: 4次（切换D、E、F、G）
8→ 9: 1次（切换E）
只需要把 0~9 这 10 个数字的排列顺序全部遍历一下就可以了。这
个做法需要遍历 10!（10 的阶乘）次，暴力搜索就足以解题了。

切换处理：因为只有亮灯和灭灯两种状态，用二进制数表示就可以了。
0和1的切换用位运算可以高速实现，本题用异或运算处理起来比较简单。
*/

#include <iostream>
#include <cstdio>
using namespace std;

unsigned char flip[10][10], bit[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B}; // 定义表示 0 ～ 9 的比特序列 
unsigned char bitcount(unsigned char x); // 统计比特序列中 1 的个数
int MIN = 63;
bool is_used[10]; //各数字是否已使用
int a[11];  //记录具体方案 
void Search(unsigned char sum, int prev, int step);  //每次设置翻转比特序列后的值为初始值 

int main(){
	//事先得出异或运算结果
	for(int i = 0;i < 10; i++){
		for(int j = 0; j < 10; j++){
			flip[i][j] = bitcount(bit[i]^bit[j]);
		}
	}
	memset(is_used, false, sizeof(is_used));
	Search(0, 0, 1);
	cout << MIN;
	
	return 0;
}

unsigned char bitcount(unsigned char x){
	x = (x & 0x55555555) + (x >> 1 & 0x55555555);
 	x = (x & 0x33333333) + (x >> 2 & 0x33333333);
 	x = (x & 0x0F0F0F0F) + (x >> 4 & 0x0F0F0F0F);
 	x = (x & 0x00FF00FF) + (x >> 8 & 0x00FF00FF);
 	x = (x & 0x0000FFFF) + (x >> 16 & 0x0000FFFF);
 	return x;
}

void Search(unsigned char sum, int prev, int step){ 
//sum:  已使用数字的翻转次数,  prev : 上一次使用的数字, step: 当前步数 
	if(step == 11){
		MIN = sum;
		for(int i = 1; i <= 10; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	} 
	else{
		for(int i = 0; i < 10; i++){
			if(!is_used[i]){
				is_used[i] = true; a[step] = i;
				unsigned char next_sum = 0;
				if(prev >= 0) next_sum = sum + flip[prev][i];
				if(MIN > next_sum) Search(next_sum, i, step + 1);
				is_used[i] = false;
			}
		}
	}
}
