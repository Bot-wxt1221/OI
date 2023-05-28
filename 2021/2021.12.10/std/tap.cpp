/*
可用的插线板插口数分别是 2个和 3个，这些插口需要按一定的顺
序使用。既然连接某个插线板时不考虑所用的插口位置，那么可以 
从右侧的插口开始按顺序使用。
一个插线板一旦插入另一个插线板的插口中，从此就连接在这个插
线板上了。因此我们可以使用深度优先搜索。这里要求的是可以空
出 n 个插口的插线方法。
某个插线板的插口上插了其他插线板时，只需要把这些插线板的插
口个数相乘就可以了。
记忆化递归，可以加快运行速度。 
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#define SIZE 45
using namespace std;
int N;
long long int memo[SIZE]; 
long long int set_tap(int remain);
 
int main(){
	//freopen("tap.in", "r", stdin);
	//freopen("tap.out", "w", stdout);
	cin >> N;
	memset(memo, 0, sizeof(memo));
	memo[1] = 1LL;
	cout << set_tap(N);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

long long int set_tap(int remain){
	if(memo[remain]) return memo[remain];  //若已计算过，直接返回 
	long long int cnt = 0LL;
	// 2 个插口
	for(int i = 1; i <= remain / 2; i++){
		if(remain - i == i){
			cnt += set_tap(i) * (set_tap(i) + 1) / 2;
		}			
		else{
			cnt += set_tap(remain - i) * set_tap(i);
		}		
	} 
	// 3 个插口
	for(int i = 1; i <= remain / 3; i++){
		for(int j = i; j <= (remain - i) / 2; j++){
			if(remain - (i + j) == i && (i == j)){
				cnt += set_tap(i) * (set_tap(i) + 1) * (set_tap(i) + 2) / 6;				
			}
			else if(remain - (i + j) == i){
				cnt += set_tap(i) * (set_tap(i) + 1) * set_tap(j) / 2;
			}
			else if(i == j){
				cnt += set_tap(remain - (i + j)) * set_tap(i) * (set_tap(i) + 1) / 2;				
			}
			else if(remain - (i + j) == j){
				cnt += set_tap(j) * (set_tap(j) + 1) * set_tap(i) / 2;
			}
			else{
				cnt += set_tap(remain - (i + j)) * set_tap(j) * set_tap(i);
			}
		}
	} 
	memo[remain] = cnt; 
	return cnt;
}















