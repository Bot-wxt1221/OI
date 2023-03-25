/*
从“两人最终同时停在同一级”可知，A 如果已经比 B 所处的级数
大，那么搜索就可以结束了。A 和 B 分别从不同位置出发，每次改
变前进级数并进行递归搜索
*/

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int N;  //楼梯级数
int STEPS; //一次最大前进级数
long long int Move(int a, int b);

int main(){
	cin >> N >> STEPS;	
	double dur;
    clock_t start, end;
    start = clock();
    
   	cout << Move(0, N);
   	
    end = clock();
    dur = (double)(end - start);
    printf("\nUse Time:%f\n",(dur/CLOCKS_PER_SEC));
	
	return 0;
}

long long int Move(int a, int b){	
	if(a > b) return 0LL;
	if(a == b) return 1LL;
	long long int cnt = 0;
	for(int i = 1; i <= STEPS; i++){
		for(int j = 1; j <= STEPS; j++){
			cnt += Move(a + i, b - j);
		}
	}
	return cnt;	
}
