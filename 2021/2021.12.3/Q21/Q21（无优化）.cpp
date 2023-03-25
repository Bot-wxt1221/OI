/*
我们只需要按照 "一行中两端设置为 1，中间数字由上一层计算而
来 "这样的规则，就可以生成帕斯卡三角形。每一行的数字都用一维数
组表示，中间的数组元素通过异或运算得出，这样就可以不断计算出下
一行的数字。

一直重复计算，直至出现第 2014 个 0
*/


#include <iostream>
#include <cstdio>
using namespace std;
int cur_row[2000] = {1}; //当前行的值
int next_row[2000] = {1}; //下一行的值

int main(){
	int count = 0;  // 0 出现的次数
	int line = 1;  // 当前行的行数

	while(count < 2014){
		/*
		for(int i = 0; i < line; i++){	
			cout << cur_row[i] << " ";
		}
		cout << endl;
		*/
		next_row[0] = 1;
		int t = 1;
		//通过计算上一行的异或值得到下一行
		for(int i = 0 ; i < line - 1 && count < 2014; i++){
			next_row[t] = cur_row[i] ^ cur_row[i+1];
			if(next_row[t] == 0) count++;			
			t += 1;
		}		
		next_row[t] = 1;	
		for(int i = 0; i <= t; i++){
			cur_row[i] = next_row[i];
		}
		line += 1;  //增加行数，进入下一行处理		
	}
	cout << line << endl;
	//cout << count;

	return 0;
}
