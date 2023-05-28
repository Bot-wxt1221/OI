/*
假设正方形的边长为 3 厘米, 如下图： 
a b c d
e f g h
i j k l  
m n o p
如果一开始已经由 a 移动到 b，那么还要从 bdpn 这个长方形里找
到一条从 b 出发分别返回到 f、j、n 的路径，才能避免和起始路
径重合（如果返回 b，那么路径一定是 b → a，这与问题要求不符）。
如果返回到 f，那么最终路径是 f → e → a ；如果返回到 j，则是
j → i → e → a ；如果返回到 n，则是 n → m → i → e → a。
经过这几个顶点的路径都可以算作 1 种路径。换句话说，只要求出从
b 点出发，分别返回到 f、j、n 的路径数，然后再相加就能求得最终
答案（已经由 a 移动到 e 的情形与上述情形对称，所以最终答案是
其中一种情形下的路径数的两倍）。

接下来求从 b 出发返回到 f 的路径。假设这时已经由 b 移动到c，
那么就相当于求 cdpo 这个长方形中由 c 出发分别返回到g、k、o 的路
径。假设事先已经由 b 移动到 f，则是求由 f 出发返回到 f 的路径，
也就是计算 fhpm 这个正方形（即递归过程的 “前一个”）即可。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 10
using namespace std;
long long route(int width, int height, int back_y);

int main(){
	int square;
	cin >> square;	
	cout << route(square, square, 0);
	return 0;
}

long long route(int width, int height, int back_y){
	if(width == 1) return (back_y == height) ? back_y : back_y + 2;
	if(height == 1) return (back_y == 0) ? 2 : 1;
	long long total = 0LL;
	if(back_y == 0){
		for(int i = 0; i < height; i++){
			total += 2 * route(width - 1, height, i + 1);
		}
	}
	else{
		for(int i = back_y; i <= height; i++){
			total += route(width - 1, height, i);
		}
		total += route(width, height - 1, back_y - 1);
	}
	return total;
}
