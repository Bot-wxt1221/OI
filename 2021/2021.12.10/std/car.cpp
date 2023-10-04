/*
这个问题的关键在于，已经通过的道路不能再次通过。也就是说，
需要把已经通过的位置记录下来。另外，只能直行或者左转，因此
也要保存上一次移动的方向。
这里，我们把 "横线和竖线是否已经通过"分别保存到数组里。然
后，用二进制数表示各个方格的横线和竖线是否已经使用过。
1---已通过，  0---没有通过
按照前行方向，用递归遍历还没有走过的所有道路。
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define SIZE 8
using namespace std;
int W, H; //宽度（列数），高度（行数） 
int DIR[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};  //前进方向：上、左、下、右 

int Search(int x, int y, int dir, int left[], int bottom[]);
 
int main(){
	freopen("car.in", "r", stdin);
	freopen("car.out", "w", stdout);
	cin >> W >> H;
	int left[SIZE], bottom[SIZE];
	memset(left, 0, sizeof(left));   // 用二进制表示某根竖线是否已通过
	memset(bottom, 0, sizeof(bottom));	// 用二进制表示某根横线是否已通过
	cout << Search(0, 0, 3, left, bottom);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

int Search(int x, int y, int dir, int left[], int bottom[]){
	int left_l[SIZE], bottom_l[SIZE];
	for(int i = 0; i <= H; i++){
		left_l[i] = left[i];
	}
	for(int i = 0; i <= W; i++){
		bottom_l[i] = bottom[i];
	}
	
	int pos;
	//已经越界或者已通过的情况下无法前行
	if(dir == 0 || dir == 2){  //前后移动的情况
		pos = min(y, y + DIR[dir][1]);
		if(pos < 0 || y + DIR[dir][1] > H) return 0;
		if( ( left_l[pos] & (1 << x) ) > 0 ) return 0;
		left_l[pos] |= (1 << x);  //把竖线标记为已通过
	} 
	else{ //左右移动的情况
		pos = min(x, x + DIR[dir][0]);
		if(pos < 0 || x + DIR[dir][0] > W) return 0;
		if( ( bottom_l[pos] & (1 << y) ) > 0 ) return 0;
		bottom_l[pos] |= (1 << y);  // 把横线标记为已通过
	}
	
	int next_x = x + DIR[dir][0], next_y = y + DIR[dir][1];
	if(next_x == W && next_y == H) return 1;  //到达终点则结束
	
	int cnt = 0;
	//前进
	cnt += Search(next_x, next_y, dir, left_l, bottom_l);
	//左转
	dir = (dir + 1) % 4;
	cnt += Search(next_x, next_y, dir, left_l, bottom_l); 
	return cnt;
}
























































