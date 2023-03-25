#include <iostream>
#include <cstdio>
#define SIZE 105
using namespace std;

int height, width, cnt;
string str = "";
int tatami[SIZE][SIZE];
void printTatami();
void setTatami(int h, int w, int id);

int main(){
	//freopen("tatami.in", "r", stdin);
	//freopen("tatami.out", "w", stdout);
	cin >> height >> width;
	// 设置初始值, 外围用 -1，内部用 0 表示
	for(int h = 0; h <= height + 1; h++){
		for(int w = 0; w <= width + 1; w++){
			tatami[h][w] = 0;
			if( h == 0 || w == 0 || h == height + 1 || w == width + 1)
				tatami[h][w] = -1;
		}	
	}
	cnt = 0;
	setTatami(1, 1, 1);
	cout << cnt << endl;
	cout << str;
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

void printTatami(){
	for(int i = 1; i <= height ; i++){
		for(int j = 1; j <= width; j++){
			// 横向铺时显示  - 
			if(tatami[i][j] == tatami[i][j + 1] || tatami[i][j] == tatami[i][j - 1]){
				str += "-";
			}
			// 纵向铺时显示 |
			if(tatami[i][j] == tatami[i + 1][j] || tatami[i][j] == tatami[i - 1][j]){
				str += "|";
			}		
		}
		str += "\n";
	}
	str += "\n";		
	return;
}

void setTatami(int h, int w, int id){
	if(h == height + 1){ // 铺完显示榻榻米
		cnt++;
		printTatami();
	}
	else if(w == width + 1){ // 到右边界时改行
		setTatami(h + 1, 1, id);
	}
	else if(tatami[h][w] > 0){ // 铺完向右移动
		setTatami(h, w + 1, id);
	}
	else{ // 当左上与上边相同或者左上与左边相同时可以铺
		if(tatami[h - 1][w - 1] == tatami[h - 1][w] || tatami[h - 1][w - 1] == tatami[h][w - 1]){
			if(tatami[h][w + 1] == 0){ // 可以横向铺的情况
				tatami[h][w] = tatami[h][w + 1] = id;
				setTatami(h, w + 2, id + 1);
				tatami[h][w] = tatami[h][w + 1] = 0;
			}
			if(tatami[h + 1][w] == 0){ // 可以纵向铺的情况
				tatami[h][w] = tatami[h + 1][w] = id;
				setTatami(h, w + 1, id + 1);
				tatami[h][w] = tatami[h + 1][w] = 0;
			}
		}
	}
}
