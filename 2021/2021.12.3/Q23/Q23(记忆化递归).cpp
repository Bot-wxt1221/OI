/*
如果剩余硬币为 0，则无法继续游戏，而只要还有 1 枚硬币，游戏
就能继续。如果某回合获胜，则硬币增加 1 枚，落败则减少 1 枚。
这道题中，保持思路简单非常重要。

这里只需要判断 "游戏是否进行到了题干要求的回合"以及 "是否
已经输光硬币"。

记忆化递归可以加快速度，每个问题只计算一次，但递归次数过多
有可能系统栈溢出。 

*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long int memo[100][200]; 
long long int game(int coin, int depth);

int main(){
	memset(memo, 0, sizeof(memo));
	cout << game(10, 24);	
	return 0;
} 

long long int game(int coin, int depth){
	if(memo[coin][depth]) return memo[coin][depth];
	if(coin == 0) return 0LL;
	if(depth == 0) return 1LL;
	long long int win = game(coin + 1, depth - 1);  //获胜时
	long long int lose = game(coin - 1, depth - 1); //落败时
	memo[coin][depth] = win + lose; 
	return memo[coin][depth];
} 





