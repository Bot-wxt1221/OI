#include <cstdio>
#include <iostream>
using namespace std;

int x[50] = {0, 32, 15, 19, 4, 21, 2, 25, 17, 34, 6, 27, 13, 36, 11, 30, 8, 23, 10, 5, 24, 16, 33, 1, 20, 14, 31, 9, 22, 18, 29, 7, 28, 12, 35, 3, 26};//0-36
int y[50] = {0, 28, 9, 26, 30, 11, 7, 20, 32, 17, 5, 22, 34, 15, 3, 24, 36, 13, 1, 0, 27, 10, 25, 29, 12, 8, 19, 31, 18, 6, 21, 33, 16, 4, 23, 35, 14, 2};//0-37
//存着欧式和美式 

int get (int t[], int n, int r){
	int maxt = -1;//在这个n下的欧式美式的最大值，一开始的最大值为-1 
	int nowt = 0;//当前的和是多少 
	for (int j = 0; j < r; j++)nowt += t[j];//一开始的第一个和 
	for (int j = 0; j <= n; j++){//滑动窗口遍历 
		if (nowt > maxt) maxt = nowt;//如果当前大于最大值就更新 
		nowt -= t[j]; nowt += t[(j + r) % (n + 1)];//减去第一个，加上后面最新的一个 
	}
	return maxt;
} 

int main(){
	int cnt = 0;
	for (int i = 2; i <= 36; i++){//遍历每一个n 
		if (get(x, 36, i) < get(y, 37, i)) cnt++;//如果美式大于欧式就增加 
	}
	cout << cnt;
	return 0;
}
