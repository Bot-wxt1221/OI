/*
"往返路径" 理解成 "两种路径"会简单很多。
以顶点的横坐标 x和纵坐标 y为准，往右记
录 0，往下记录 1，以此记录通过的顶点，
也就是通过递归用深度优先搜索遍历，清除标记。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 10
using namespace std;
int square;
long long count = 0;
bool is_used[SIZE][SIZE][2];
void route(int x, int y, bool is_first_time);

int main(){
	cin >> square;
	memset(is_used, false, sizeof(is_used));
	route(0, 0, true);
	cout << count;
	return 0;
}

void route(int x, int y, bool is_first_time){
	if( (x == square) && (y == square) ){
		if(is_first_time){
			route(0, 0, false);
		}
		else{
			count++;
		}
	}
	if(x < square){
		if(!is_used[x][y][0]){
			is_used[x][y][0] = true;
			route(x + 1, y, is_first_time);
			is_used[x][y][0] = false;
		}
	}
	if(y < square){
		if(!is_used[x][y][1]){
			is_used[x][y][1] = true;
			route(x, y + 1, is_first_time);
			is_used[x][y][1] = false;
		}
	}
	return;	
}
